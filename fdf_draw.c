/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:53:04 by oandelin          #+#    #+#             */
/*   Updated: 2023/04/18 16:29:16 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_to_img(t_img *image, int x, int y, int color)
{
	char	*pxl;

	pxl = image->addr + (y * image->line_len + x * (image->bpp / 8 ));
	*(unsigned int *)pxl = color;
}

int draw_line (t_img image, t_point start, t_point end)
{
	double x_delta = end.x - start.x;
	double y_delta = end.y - start.y;
	int pixels = sqrt((x_delta * x_delta) + (y_delta * y_delta));
	ft_printf("paska");
	x_delta /= pixels;
	y_delta /= pixels;

	double x_pixel = start.x;
	double y_pixel = start.y;
	while (pixels)
	{
		pixel_to_img(&image, x_pixel, y_pixel, start.color);
		x_pixel += x_delta;
		y_pixel += y_delta;
		--pixels;
	}
	return(0);
}

void bresenham(t_img image, int x1, int y1, int x2, int y2)
{
    int dx  = x2 - x1;
    int dy  = y2 - y1;
    int	y   = y1;
    int eps = 0;
    int x	= x1;
	while (x <= x2)
    {	pixel_to_img(&image, x, y, 0x0000FFFF);
        eps += dy;
        if ( (eps << 1) >= dx )  
		{
          y++;
		  eps -= dx;
        }
		x++;
    }
}


// void draw_rect (t_img image, int x, int y, int w, int h)
// {
// 	t_line hline1;
// 	t_line hline2;
// 	t_line vline1;
// 	t_line vline2;

// 	hline1.x_start = x;
// 	hline1.y_start = y;
// 	hline1.x_end = x + w;
// 	hline1.y_end = y;
	
// 	vline1.x_start = x;
// 	vline1.y_start = y;
// 	vline1.x_end = x;
// 	vline1.y_end = y + h;

// 	hline2.x_start = x;
// 	hline2.y_start = y + h;
// 	hline2.x_end = x + w;
// 	hline2.y_end = y + h;

// 	vline2.x_start = x + w;
// 	vline2.y_start = y;
// 	vline2.x_end = x + w;
// 	vline2.y_end = y + h;

// 	draw_line(image, hline1, 0x00FF0000);
// 	draw_line(image, vline1, 0x0000FF00);
// 	draw_line(image, hline2, 0x000000FF);
// 	draw_line(image, vline2, 0x00FFFF00);
// }
