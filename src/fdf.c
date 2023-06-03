/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:10:59 by oandelin          #+#    #+#             */
/*   Updated: 2023/06/03 15:14:33 by oandelin         ###   ########.fr       */
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
	fdf = parse_map(fdf, fd);
// 	error handling?
	fdf = new_window(fdf);
	if (!fdf.mlx_ptr || !fdf.win_ptr)
		return (MLX_ERROR);
	draw(&fdf);
	mlx_hook(fdf.win_ptr, ON_CLOSE, 0, &handle_close, &fdf);
	mlx_hook(fdf.win_ptr, ON_KEYPRESS, 0, &handle_keypress, &fdf);
	mlx_hook(fdf.win_ptr, ON_KEYRELEASE, 0, &handle_keyrelease, &fdf);
	mlx_loop(fdf.mlx_ptr);
}
