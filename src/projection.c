/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:22:03 by oandelin          #+#    #+#             */
/*   Updated: 2023/06/02 14:30:37 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	get_zoom(double *x, double *y, double *x1, double *y1, double zoom)
{
	*x *= zoom;
	*y *= zoom;
	*x1 *= zoom;
	*y1 *= zoom;
}

void	isometric(double *x, double *y, double z, double angle)
{
	float	temp_x;
	
	temp_x = *x;
	*x = (temp_x - *y) * cos(angle);
	*y = (temp_x + *y) * sin(angle) - z;
}

void	shift_line(t_fdf *fdf, double *x, double *y, double *x1, double *y1)
{
	*x += fdf->shift_x;
	*y += fdf->shift_y;
	*x1 += fdf->shift_x;
	*y1 += fdf->shift_y;
}

void	project_line(t_fdf *fdf, double x, double y, double x1, double y1)
{
	// muuta semmoseks etta hakee kaikki tiedot structista
	// alkupiste, loppupiste, varit.
	double z;
	double z1;

	if ((int)y < fdf->map.h && (int)x < fdf->map.w) 
		z = (double)fdf->map.points[(int)y][(int)x].z * fdf->z_factor;
	else 
		z = 0;
	if ((int)y1 < fdf->map.h && (int)x1 < fdf->map.w)
		z1 = (double)fdf->map.points[(int)y1][(int)x1].z * fdf->z_factor;
	else
		z1 = z;	
//	color = fdf->map.points[(int)y][(int)x].color;
	isometric(&x, &y, z, fdf->angle);
	isometric(&x1, &y1, z1, fdf->angle);
	get_zoom(&x, &y, &x1, &y1, fdf->zoom);
	shift_line(fdf, &x, &y, &x1, &y1);
	bresenham(fdf, x, y, x1, y1);
}
