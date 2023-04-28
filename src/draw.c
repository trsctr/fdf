/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:53:04 by oandelin          #+#    #+#             */
/*   Updated: 2023/04/27 16:54:48 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_to_img(t_fdf *data, int x, int y, int color)
{
	// tee jotenkin smoothimmin missa otetaan endian ja bpp huomioon jne
	// ja error protection ettei piirreta kuvan ulkopuolelle

	if (x < WIN_W && y < WIN_H)
		data->image.imgdata[y * data->win_w + x] = color;
	// pxl = image->imgdata + (y * image->line_len + x * (image->bpp / 8 ));
	// *pxl = color;
}

int draw_line (t_fdf fdf, int x, int y, int x2, int y2)
{
 	double x_delta;
 	double y_delta;
 	int pixels;
 	
 	x_delta = (x2 * 20) - (x * 20);
	y_delta = (y2 * 20) - (y * 20);

	// x_delta = x2 - x;
	// y_delta = y2 - y;
	
	
	pixels = sqrt((x_delta * x_delta) + (y_delta * y_delta));
	
	x_delta /= pixels;
 	y_delta /= pixels;
	
 	double x_pixel = x * 20;
 	double y_pixel = y * 20;

 	while (pixels)
	{
		if (fdf.map.points[y][x].z)
		 	pixel_to_img(&fdf, x_pixel, y_pixel, 0xFF0000);
 		else
			pixel_to_img(&fdf, x_pixel, y_pixel, 0xFFFFFF);
 		x_pixel += x_delta;
 		y_pixel += y_delta;
 		--pixels;
 	}
 	return(0);
}

void draw_moire(t_fdf fdf, int left, int top, int right, int bottom)
{
	int x, y;

	draw_line(fdf, left, top, right, top);
	draw_line(fdf, left, bottom, right, bottom);
	draw_line(fdf, left, top, left, bottom);
	draw_line(fdf, right, top, right, bottom);
	
	for (x = left; x < right; x += 10)
		draw_line(fdf, x, top, right - x + left, bottom);
	
	for (y = top; y < bottom; y += 10)
		draw_line(fdf, left, y, right, bottom - y + top);
}

void draw(t_fdf data)
{
	int x;
	int y;

	y = 0;
	while(y < data.map.h)
	{
		x = 0;
		while(x < data.map.w)
		{
			if(x < data.map.w - 1)
				draw_line(data, x, y, x + 1, y);
			if(y < data.map.h -1)
				draw_line(data, x, y, x, y + 1);
			x++;
		}
		y++;
	}
}



// int draw_line (t_img image, t_point start, t_point end)
// {
//  	double x_delta = end.x - start.x;
//  	double y_delta = end.y - start.y;
//  	int pixels = sqrt((x_delta * x_delta) + (y_delta * y_delta));
//  	ft_printf("paska");
//  	x_delta /= pixels;
//  	y_delta /= pixels;

//  	double x_pixel = start.x;
//  	double y_pixel = start.y;
//  	while (pixels)
// {
//  		pixel_to_img(&image, x_pixel, y_pixel, start.color);
//  		x_pixel += x_delta;
//  		y_pixel += y_delta;
//  		--pixels;
//  	}
//  	return(0);
// }

// void bresenham(t_img image, int x1, int y1, int x2, int y2)
// {
//      int dx  = x2 - x1;
//      int dy  = y2 - y1;
//      int	y   = y1;
//      int eps = 0;
//      int x	= x1;
//  	while (x <= x2)
//      {	pixel_to_img(&image, x, y, 0x0000FFFF);
//          eps += dy;
//          if ( (eps << 1) >= dx )  
//  		{
//            y++;
//  		  eps -= dx;
//          }
//  		x++;
//      }
// }


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
