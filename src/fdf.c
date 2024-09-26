/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:10:59 by oandelin          #+#    #+#             */
/*   Updated: 2024/09/26 15:33:27 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf		data;
	int			fd;

	if (argc != 2)
	{
		ft_printf("Invalid arguments.\nExample: ./fdf map_dir/map.fdf\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	ft_printf("Loading map..\n");
	data = parse_map(&data, fd);
	data = new_window(data);
	draw(&data);
	mlx_hook(data.win_ptr, ON_KEYPRESS, (1L<<0), &handle_keypress, &data);
	mlx_hook(data.win_ptr, ON_CLOSE, 0, &handle_close, &data);
	mlx_loop(data.mlx_ptr);
}
