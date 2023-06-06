/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:22:03 by oandelin          #+#    #+#             */
/*   Updated: 2023/06/06 20:57:11 by oandelin         ###   ########.fr       */
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

void	get_z(t_line *line, t_fdf *data)
{
	if ((int)line->y < data->map.h && (int)line->x < data->map.w)
		line->z = (double)data->map.points[(int)line->y][(int)line->x].z
			* data->z_factor;
	else if ((int)line->y == data->map.h)
		line->z = (double)data->map.points[(int)line->y - 1][(int)line->x].z
			* data->z_factor;
	else if ((int)line->x == data->map.w)
		line->z = (double)data->map.points[(int)line->y][(int)line->x - 1].z
			* data->z_factor;
	if ((int)line->y1 < data->map.h && (int)line->x1 < data->map.w)
		line->z1 = (double)data->map.points[(int)line->y1][(int)line->x1].z
			* data->z_factor;
	else if ((int)line->y == data->map.h && (int)line->x1 < data->map.w)
		line->z1 = (double)data->map.points[(int)line->y1 - 1][(int)line->x1].z
			* data->z_factor;
	else
		line->z1 = line->z;
}

void	isometric(t_line *line, t_fdf *data)
{
	double	temp_x;
	double	temp_x1;

	temp_x = line->x;
	temp_x1 = line->x1;
	line->x = (temp_x - line->y) * cos(data->angle);
	line->y = (temp_x + line->y) * sin(data->angle) - line->z;
	line->x1 = (temp_x1 - line->y1) * cos(data->angle);
	line->y1 = (temp_x1 + line->y1) * sin(data->angle) - line->z1;
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
	t_line	line;

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
	get_z(&line, fdf);
	isometric(&line, fdf);
	get_zoom(fdf, &line);
	shift_line(fdf, &line);
	bresenham(fdf, &line);
}
