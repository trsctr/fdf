/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:10:59 by oandelin          #+#    #+#             */
/*   Updated: 2023/03/15 18:12:48 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <string.h>


// int close(int keycode, s_data data)
// {
// 	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
// 	return(0);
// }

int draw_line (t_img image, t_line line, int color)
{
	double x_delta = line.x_end - line.x_start;
	double y_delta = line.y_end - line.y_start;
	int pixels = sqrt((x_delta * x_delta) + (y_delta * y_delta));

	x_delta /= pixels;
	y_delta /= pixels;

	double x_pixel = line.x_start;
	double y_pixel = line.y_start;
	while (pixels)
	{
		pixel_to_img(&image, x_pixel, y_pixel, color);
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


void draw_rect (t_img image, int x, int y, int w, int h)
{
	t_line hline1;
	t_line hline2;
	t_line vline1;
	t_line vline2;

	hline1.x_start = x;
	hline1.y_start = y;
	hline1.x_end = x + w;
	hline1.y_end = y;
	
	vline1.x_start = x;
	vline1.y_start = y;
	vline1.x_end = x;
	vline1.y_end = y + h;

	hline2.x_start = x;
	hline2.y_start = y + h;
	hline2.x_end = x + w;
	hline2.y_end = y + h;

	vline2.x_start = x + w;
	vline2.y_start = y;
	vline2.x_end = x + w;
	vline2.y_end = y + h;

	draw_line(image, hline1, 0x00FF0000);
	draw_line(image, vline1, 0x0000FF00);
	draw_line(image, hline2, 0x000000FF);
	draw_line(image, vline2, 0x00FFFF00);
}


int	key_hook(int keycode, t_window *window)
{
	mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	printf("hihi\n");
	exit(0);
}

int	main(void)
{
	t_window	window;
	t_line		line;
	t_img		image;

	line.x_start = 410;
	line.y_start = 360;
	line.x_end = 60;
	line.y_end = 90;
	window = new_window(640, 480, "joo");
	if (!window.mlx_ptr || !window.win_ptr)
		return (MLX_ERROR);
	image = new_image(640, 480, window);
	draw_line(image, line, 0x00FF00);
	draw_rect(image, 40, 40, 250, 240);
	bresenham(image, 610, 300, 60, 90);
	
	mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, image.img_ptr, 0, 0);
	printf("Let's Find out what's inside our structure :D\n");
	printf("img_ptr		: [%p]\n", image.img_ptr);
	printf("bpp		: [%d]\n", image.bpp);
	printf("line_len	: [%d]\n", image.line_len);
	printf("endian		: [%d]\n", image.endian);
	printf("addr		: [%s]\n", image.addr);
	mlx_key_hook(window.win_ptr, key_hook, &window);
	mlx_loop(window.mlx_ptr);

}
