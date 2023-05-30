/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:53:04 by oandelin          #+#    #+#             */
/*   Updated: 2023/05/30 19:56:09 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	pixel_to_img(t_fdf *data, int x, int y, int color)
{
	// tee jotenkin smoothimmin missa otetaan endian ja bpp huomioon jne
	// ja error protection ettei piirreta kuvan ulkopuolelle

	if ((x < WIN_W && y < WIN_H) && (x > 0 && y > 0))
		data->image.imgdata[y * data->win_w + x] = color;
	// pxl = image->imgdata + (y * image->line_len + x * (image->bpp / 8 ));
	// *pxl = color;
}
void	get_zoom(float *x, float *y, float *x1, float *y1, int zoom)
{
	*x *= zoom;
	*y *= zoom;
	*x1 *= zoom;
	*y1 *= zoom;
}

void	isometric(float *x, float *y, int z, float angle)
{
	float temp_x;

	temp_x = *x;
	*x = (temp_x - *y) * cos(0.53);
	*y = (temp_x + *y) * sin(0.53);// - z;
}


void	draw_line(t_fdf *fdf, float x, float y, float x1, float y1)
{
	// muuta semmoseks etta hakee kaikki tiedot structista
	// alkupiste, loppupiste, varit.
	double x_delta;
	double y_delta;
	int pixels;
	int color;
	int z;
	int	z1;

	if ((int)y < fdf->map.h && (int)x < fdf->map.w) 
		z = fdf->map.points[(int)y][(int)x].z;
	else 
		z = 0;
	if ((int)y1 < fdf->map.h && (int)x1 < fdf->map.w)
		z1 = fdf->map.points[(int)y1][(int)x1].z;
	else
		z1 = z;	
	if (z > 0 || z1 > 0)
		color = 0xFF00000;
	else
		color = 0xFFFFFF;
	isometric(&x, &y, z, fdf->angle);
	isometric(&x1, &y1, z1, fdf->angle);
	get_zoom(&x, &y, &x1, &y1, fdf->zoom);
	y -= +z;
	y1 -= +z1;
	x += fdf->shift_x;
	y += fdf->shift_y;
	x1 += fdf->shift_x;
	y1 += fdf->shift_y;
	if (x > fdf->win_w || x1 > fdf->win_w || x < 0 || x1 < 0)
		return ;
	if (y > fdf->win_h || y1 > fdf->win_h || y < 0 || y1 < 0)
		return ;
	x_delta = x1 - x;
	y_delta = y1 - y;

	pixels = sqrt((x_delta * x_delta) + (y_delta * y_delta));
	x_delta /= pixels;
	y_delta /= pixels;
	while (pixels)
	{
		// jos haluaa gradientin, sille pitaa olla funktio tassa
		// pitaa olla position counterina jotenkin tolle gradientille
		pixel_to_img(fdf, x, y, color);
		x += x_delta;
		y += y_delta;
		pixels--;
	}
}
void	draw(t_fdf *data)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y <= data->map.h)
	{
		x = 0;
		while (x <= data->map.w)
		{
			draw_line(data, x, y, x + 1, y);
			draw_line(data, x, y, x, y + 1);
			x++;
		}
		y++;
	}
}

