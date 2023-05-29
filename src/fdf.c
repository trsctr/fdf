/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:10:59 by oandelin          #+#    #+#             */
/*   Updated: 2023/05/29 16:53:32 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf		fdf;
	int			fd;

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
	fdf = parse_map(&fdf, fd);
// 	error handling?
	close(fd);
	fdf = new_window(fdf);
	set_defaults(&fdf);
	if (!fdf.mlx_ptr || !fdf.win_ptr)
		return (MLX_ERROR);
	fdf.image = new_image(WIN_W, WIN_H, fdf);
	mlx_loop_hook(fdf.mlx_ptr, &handle_no_event, &fdf);
	draw(&fdf);
	mlx_hook(fdf.win_ptr, 02, 0, &handle_keypress, &fdf); /* ADDED */
	mlx_hook(fdf.win_ptr, 03, 0, &handle_keyrelease, &fdf); /* CHANGED */
	mlx_put_image_to_window(fdf.mlx_ptr, fdf.win_ptr, fdf.image.img_ptr, 0, 0);
	menu(fdf);

	mlx_loop(fdf.mlx_ptr);
}
