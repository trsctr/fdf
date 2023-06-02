/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:53:04 by oandelin          #+#    #+#             */
/*   Updated: 2023/06/02 16:57:09 by oandelin         ###   ########.fr       */
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



void bresenham(t_fdf *fdf, t_line *line)
{
	double	x_delta;
	double	y_delta;
	int		pixels;
	int		color;

	color = 0xFFFFFF;
	x_delta = line->x1 - line->x;
	y_delta = line->y1 - line->y;
	pixels = sqrt((x_delta * x_delta) + (y_delta * y_delta));
	x_delta /= pixels;
	y_delta /= pixels;
	while (pixels)
	{
		// jos haluaa gradientin, sille pitaa olla funktio tassa
		// pitaa olla position counterina jotenkin tolle gradientille
		pixel_to_img(fdf, line->x, line->y, color);
		line->x += x_delta;
		line->y += y_delta;
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
	t_coords coordinates;
	int	color;

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
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image.img_ptr, 0, 0);
	menu(*data);
}

