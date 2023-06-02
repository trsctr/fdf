/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:22:03 by oandelin          #+#    #+#             */
/*   Updated: 2023/06/02 17:03:06 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	get_zoom(t_fdf *data, t_line *line)
{
	line->x *= data->zoom;
	line->y *= data->zoom;
	line->x1 *= data->zoom;
	line->y1 *= data->zoom;
}

void	isometric(t_line *line, t_fdf *data)
{
	double	temp_x;
	double	temp_x1;
	double	z;
	double	z1;

	if ((int)line->y < data->map.h && (int)line->x < data->map.w) 
		z = (double)data->map.points[(int)line->y][(int)line->x].z * data->z_factor;
	else 
		z = 0;
	if ((int)line->y1 < data->map.h && (int)line->x1 < data->map.w)
		z1 = (double)data->map.points[(int)line->y1][(int)line->x1].z * data->z_factor;
	else
		z1 = z;	
	
	temp_x = line->x;
	temp_x1 = line->x1;
	line->x = (temp_x - line->y) * cos(data->angle);
	line->y = (temp_x + line->y) * sin(data->angle) - z;
	line->x1 = (temp_x1 - line->y1) * cos(data->angle);
	line->y1 = (temp_x1 + line->y1) * sin(data->angle) - z1;
}

void	shift_line(t_fdf *fdf, t_line *line)
{
	line->x += fdf->shift_x;
	line->y += fdf->shift_y;
	line->x1 += fdf->shift_x;
	line->y1 += fdf->shift_y;
}

void	project_line(t_fdf *fdf, t_coords coordinates, int direction)
{
	//double x, double y, double x1, double y1)
	// muuta semmoseks etta hakee kaikki tiedot structista
	// alkupiste, loppupiste, varit.
	t_line	line;
	double	z;
	double	z1;

	line.x = (double)coordinates.x;
	line.y = (double)coordinates.y;
	if (direction == 1)
	{
		line.x1 = line.x + 1;
		line.y1 = line.y;
	}
	else
	{
		line.x1 = line.x;
		line.y1 = line.y + 1;
	}

//	color = fdf->map.points[(int)y][(int)x].color;
	isometric(&line, fdf);
	get_zoom(fdf, &line);
	shift_line(fdf, &line);
	bresenham(fdf, &line);
}
