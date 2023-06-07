/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:53:04 by oandelin          #+#    #+#             */
/*   Updated: 2023/06/07 12:59:26 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	pixel_to_img(t_fdf *data, int x, int y, int color)
{
	if ((x < WIN_W && y < WIN_H) && (x > 0 && y > 0))
		data->image.imgdata[y * data->win_w + x] = color;
}

void	bresenham(t_fdf *data, t_line *line)
{
	double	x_slope;
	double	y_slope;
	int		pixels;

	x_slope = line->x1 - line->x;
	y_slope = line->y1 - line->y;
	pixels = sqrt(pow(x_slope, 2) + pow(y_slope, 2));
	x_slope /= pixels;
	y_slope /= pixels;
	while (pixels)
	{
		pixel_to_img(data, line->x, line->y, 0xFFFFFF);
		line->x += x_slope;
		line->y += y_slope;
		pixels--;
	}
}

void	draw_borders(t_fdf *data)
{
	t_coords	coordinates;

	coordinates.y = data->map.h - 1;
	coordinates.x = data->map.w;
	while (coordinates.y >= 0)
	{
		project_line(data, coordinates, HORIZONTAL);
		coordinates.y--;
	}
	coordinates.x--;
	coordinates.y = data->map.h;
	while (coordinates.x >= 0)
	{	
		project_line(data, coordinates, VERTICAL);
		coordinates.x--;
	}
}	

void	draw(t_fdf *data)
{
	t_coords	coordinates;

	data->image = new_image(WIN_W, WIN_H, *data);
	coordinates.y = 0;
	while (coordinates.y < data->map.h)
	{
		coordinates.x = 0;
		while (coordinates.x < data->map.w)
		{
			project_line(data, coordinates, HORIZONTAL);
			project_line(data, coordinates, VERTICAL);
			coordinates.x++;
		}
		coordinates.y++;
	}
	draw_borders(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->image.img_ptr, 0, 0);
	instructions(*data);
}
