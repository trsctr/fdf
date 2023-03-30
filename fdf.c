/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trsctr <trsctr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:10:59 by oandelin          #+#    #+#             */
/*   Updated: 2023/03/30 12:34:56 by trsctr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <X11/X.h>


int	main(int argc, char **argv)
{
	t_window	window;
	t_line		line;
	t_img		image;
	int			fd;
	int			y = 10;
	int			line_height = 15;
	
	if (argc != 2)
	{
		ft_printf("Invalid arguments.\n");
		ft_printf("Example: ./fdf map_dir/map.fdf\n");
		return(1);
	}
	fd = open (argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error opening file\n");
		return(1);
	}
	ft_printf("Loading map..\n");
	parse_map(fd);
	window = new_window(640, 480, "joo");
	if (!window.mlx_ptr || !window.win_ptr)
		return (MLX_ERROR);
	mlx_loop_hook(window.mlx_ptr, &handle_no_event, &window);
	mlx_hook(window.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &window); /* ADDED */
	mlx_hook(window.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &window); /* CHANGED */
	mlx_key_hook(window.win_ptr, handle_keypress, &window);
	mlx_loop(window.mlx_ptr);
	mlx_destroy_display(window.mlx_ptr);
	free(window.mlx_ptr);
}
