/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:10:59 by oandelin          #+#    #+#             */
/*   Updated: 2023/04/27 16:55:05 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
// #include <stdio.h>
// #include <string.h>
// #include <X11/X.h>


int	main(int argc, char **argv)
{
	t_fdf		fdf;
	// t_window	window;
	// t_img		image;
	// t_map		map;
	int			fd;
 	int			x;
	int			y;
	
	y = -1;
	if (argc != 2)
	{
	 	ft_printf("Invalid arguments.\n");
	 	ft_printf("Example: ./fdf map_dir/map.fdf\n");
	 	return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error opening file\n");
		return (1);
	}
	fdf.map.w = 0;
	fdf.map.h = 0;
	ft_printf("Loading map..\n");
	fdf.map = parse_map(fdf.map, fd);
	// error handling?
	close(fd);
	fdf = new_window(fdf);
	if (!fdf.mlx_ptr || !fdf.win_ptr)
		return (MLX_ERROR);
	fdf.image = new_image(WIN_W, WIN_H, fdf);

	// window.map = &map;
	mlx_loop_hook(fdf.mlx_ptr, &handle_no_event, &fdf);
	// while (++y < WIN_H)
	// {
	// 	x = -1;
	// 	while (++x < WIN_H)
	// 	{
	// 		if (x % 2)
	// 			fdf.image.imgdata[y * WIN_W + x] = 0xFFFFFF;
	// 		else
	// 			fdf.image.imgdata[y * WIN_W + x] = 0xFF0000;
	// 	}
	// }

	
	draw(fdf);
	//draw_line(fdf, 10, 15, 200, 200);
	// ft_printf("rows %d\n", map.rows);
	// ft_printf("cols %d\n", map.cols);
	// bresenham(image, map.points[1][1].x, map.points[1][1].y, map.points[0][0].x, map.points[0][0].y);
	// while(y < map.rows)
	// {
	//   	while(x < map.cols)
	//    	{
	//      	ft_printf("x%d,y%d: z%d	", map.points[y][x].x, map.points[y][x].y, map.points[y][x].z);
	// 	  	x++;
	//   	}
	//   	ft_printf("\n");
	//    	y++;
	//    	x = 0;
	// }
	 mlx_hook(fdf.win_ptr, 02, 0, &handle_keypress, &fdf); /* ADDED */
	 mlx_hook(fdf.win_ptr, 03, 0, &handle_keyrelease, &fdf); /* CHANGED */
	//  draw_moire(fdf, 100, 50, WIN_W - 100, WIN_H - 50);
	 mlx_put_image_to_window(fdf.mlx_ptr, fdf.win_ptr, fdf.image.img_ptr, 0, 0);
	 menu(fdf);
	 //mlx_key_hook(window.win_ptr, handle_keypress, &window);
 	mlx_loop(fdf.mlx_ptr);
}
