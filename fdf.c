/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:10:59 by oandelin          #+#    #+#             */
/*   Updated: 2023/04/08 13:20:55 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
// #include <stdio.h>
// #include <string.h>
// #include <X11/X.h>


int	main(int argc, char **argv)
{
	t_window	window;
	t_line		line;
	t_img		image;
	t_map		map;
	int			fd;
 	int			x;
	int			y;
	
	x = 0;
	y = 0;
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
	ft_printf("Loading map..\n");
	map.cols = 0;
	map.rows = 0;
	map = parse_map(fd, map);
	window = new_window(640, 480, "joo");
	if (!window.mlx_ptr || !window.win_ptr)
		return (MLX_ERROR);
	mlx_loop_hook(window.mlx_ptr, &handle_no_event, &window);
	window.map = &map;
	ft_printf("rows %d\n", map.rows);
	ft_printf("cols %d\n", map.cols);
	// while(y < map.rows)
	// {
	// 	while(x < map.cols)
	//  	{
	//    	ft_printf("x%d,y%d: z%d	", x, y, map.matrix[y][x]);
	// 	x++;
	// 	}
	// 	ft_printf("\n");
	//    	y++;
	//    	x = 0;
	// }
	mlx_hook(window.win_ptr, 02, 0, &handle_keypress, &window); /* ADDED */
	mlx_hook(window.win_ptr, 03, 0, &handle_keyrelease, &window); /* CHANGED */
	// mlx_key_hook(window.win_ptr, handle_keypress, &window);
	mlx_loop(window.mlx_ptr);
}
