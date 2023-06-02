/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:53:04 by oandelin          #+#    #+#             */
/*   Updated: 2023/06/02 14:29:45 by oandelin         ###   ########.fr       */
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



void bresenham(t_fdf *fdf, double x, double y, double x1, double y1)
{
	double x_delta;
	double y_delta;
	int pixels;
	int color;
		
	color = 0xFFFFFF;
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

void	draw_borders(t_fdf *data)
{
	int	y;
	int	x;

	y = data->map.h;
	x = data->map.w;
	while (y > 0)
	{
		project_line(data, x, y, x, y - 1);
		y--;
	}
	y = data->map.h;
	while (x > 0)
	{	
		project_line(data, x, y, x - 1, y);
		x--;
	}
}	


void	draw(t_fdf *data)
{
	int	x;
	int	y;
	int	color;

	//if (data->image != NULL)
	//mlx_destroy_image(data->mlx_ptr, data->image.img_ptr);
	data->image = new_image(WIN_W, WIN_H, *data);
	y = 0;
	while (y < data->map.h)
	{
		x = 0;
		while (x < data->map.w)
		{
			project_line(data, x, y, x + 1, y);
			project_line(data, x, y, x, y + 1);
			x++;
		}
		y++;
	}
	draw_borders(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image.img_ptr, 0, 0);
	menu(*data);
}

