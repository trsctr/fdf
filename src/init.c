/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:47:46 by oandelin          #+#    #+#             */
/*   Updated: 2023/06/03 15:14:47 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_fdf	new_window(t_fdf data)
{
	data.mlx_ptr = mlx_init();
	data.win_w = WIN_W;
	data.win_h = WIN_H;
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.win_w, data.win_h, "FDF");
	set_defaults(&data);
	return (data);
}

t_img	new_image(int w, int h, t_fdf data)
{
	t_img	image;

	if (data.image.imgdata)
		mlx_destroy_image(data.mlx_ptr, data.image.img_ptr);
	image.img_ptr = mlx_new_image(data.mlx_ptr, w, h);
	image.imgdata = (int *)mlx_get_data_addr(image.img_ptr, &(image.bpp), \
							&(image.line_len), &(image.endian));
	image.w = w;
	image.h = h;
	return (image);
}

void	set_defaults(t_fdf *fdf)
{
	fdf->zoom = 35;
	fdf->angle = 0.53;
	fdf->shift_x = WIN_W / 3;
	fdf->shift_y = WIN_H / 6;
	fdf->z_factor = 1;
}

void	menu(t_fdf data)
{
	char *line1 = "Press ARROW KEYS to move image";
	char *line2 = "Press W and S to zoom in/out";
	char *line3 = "Press Q and A to transform altitude difference";
	char *line4 = "Press SPACE to reset settings";
	char *line5 = "Press ESC to exit";

	mlx_string_put(data.mlx_ptr, data.win_ptr, 10, 5, 0xFFFFFFF, "Le FDF");
	mlx_string_put(data.mlx_ptr, data.win_ptr, 10, WIN_H -110, 0xFFFFFFF, line1);
	mlx_string_put(data.mlx_ptr, data.win_ptr, 10, WIN_H -90, 0xFFFFFFF, line2);
	mlx_string_put(data.mlx_ptr, data.win_ptr, 10, WIN_H -70, 0xFFFFFFF, line3);
	mlx_string_put(data.mlx_ptr, data.win_ptr, 10, WIN_H -50, 0xFFFFFFF, line4);
	mlx_string_put(data.mlx_ptr, data.win_ptr, 10, WIN_H -30, 0xFFFFFFF, line5);
}
