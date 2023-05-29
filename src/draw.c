/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:53:04 by oandelin          #+#    #+#             */
/*   Updated: 2023/05/29 17:10:26 by oandelin         ###   ########.fr       */
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
	*x = (*x - *y) * cos(angle);
	*y = (*x + *y) * sin(angle) - z;
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

	z = fdf->map.points[(int)y][(int)x].z;
	if ((int)y1 < fdf->map.h && (int)x1 < fdf->map.w)
		z1 = fdf->map.points[(int)y1][(int)x1].z;
	else
		z1 = z;	
	ft_printf("x: %d, x1: %d, y: %d, y1: %d, z: %d, z1: %d\n", (int)x, (int)x1, (int)y, (int)y1, z, z1);
	if (z > 0 || z1 > 0)
		color = 0xFF00000;
	else
		color = 0xFFFFFF;
	//ft_printf("kakka");
	get_zoom(&x, &y, &x1, &y1, fdf->zoom);
	isometric(&x, &y, z, fdf->angle);
	isometric(&x1, &y1, z1, fdf->angle);
	x += fdf->shift_x;
	y += fdf->shift_y;
	x1 += fdf->shift_x;
	y1 += fdf->shift_y;
	if (x > fdf->win_w || x1 > fdf->win_w || x < 0 || x1 < 0)
		return;
	if (y > fdf->win_h || y1 > fdf->win_h || y < 0 || y1 < 0)
		return;
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

// void draw_moire(t_fdf fdf, int left, int top, int right, int bottom)
// {
// 	int x, y;

// 	draw_line(fdf, left, top, right, top);
// 	draw_line(fdf, left, bottom, right, bottom);
// 	draw_line(fdf, left, top, left, bottom);
// 	draw_line(fdf, right, top, right, bottom);
	
// 	for (x = left; x < right; x += 10)
// 		draw_line(fdf, x, top, right - x + left, bottom);
	
// 	for (y = top; y < bottom; y += 10)
// 		draw_line(fdf, left, y, right, bottom - y + top);
// }
// void draw_tile(t_fdf data, int x, int y, int color)
// {
// 	int tile_width = 64;
// 	int tile_height = 32;
// 	int top_x = (x - y) * (tile_width / 2) + 400;
// 	int top_y = (x + y) * (tile_height / 2) + 100;
// 	int left_x = top_x - tile_width / 2;
// 	int left_y = top_y + tile_height / 2;
// 	int bottom_x = top_x;
// 	int bottom_y = left_y + (tile_height / 2);
// 	int right_x = top_x + (tile_width / 2);
// 	int right_y = left_y;
	
// 	draw_line(data, top_x, top_y, right_x, right_y, color);
// 	draw_line(data, top_x, top_y, left_x, left_y, color);
// 	draw_line(data, left_x, left_y, bottom_x, bottom_y, color);
// 	draw_line(data, bottom_x, bottom_y, right_x, right_y, color);
	
// }
void draw(t_fdf *data)
{
	int x;
	int y;
	int color;
	
	y = 0;
	while(y < data->map.h)
	{
		x = 0;
		while(x < data->map.w)
		{

			draw_line(data, x, y, x + 1, y);
			draw_line(data, x, y, x, y + 1);
			x++;
		}
		y++;
	}
}

// void draw_block(t_fdf data, int x, int y, int z)
// {
// 	int tile_width = 64;
// 	int tile_height = 32;
// 	int origin_x = (x - y) * (tile_width / 2) + 400;
// 	int origin_y = (x + y) * (tile_height / 2) + 100;

// 	draw_line(data, origin_x, origin_y - (z * tile_height, top_y, right_x, right_y, color);)
// 	draw_line(data, top_x, top_y, left_x, left_y, color);
// 	draw_line(data, left_x, left_y, bottom_x, bottom_y, color);
// 	draw_line(data, bottom_x, bottom_y, right_x, right_y, color);



// }

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

