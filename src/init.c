/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:47:46 by oandelin          #+#    #+#             */
/*   Updated: 2023/04/25 22:15:30 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf new_window (t_fdf data)
{
	data.mlx_ptr = mlx_init();
	data.win_w = WIN_W;
	data.win_h = WIN_H;
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.win_w, data.win_h, "FDF");
	return (data);
}

t_img new_image(int w, int h, t_fdf data)
{
	t_img image;

	image.img_ptr = mlx_new_image(data.mlx_ptr, w, h);
	image.imgdata = (int *)mlx_get_data_addr(image.img_ptr, &(image.bpp), \
							&(image.line_len), &(image.endian));
	image.w = w;
	image.h = h;
	return (image);
}

void menu(t_fdf data)
{
	char *line1 = "this is a placeholder";
	char *line2 = "this is also a placeholder";
	char *line3 = "press esc to exit";

	mlx_string_put(data.mlx_ptr, data.win_ptr, 10, data.win_h-70, 0xFFFFFFF, line1);
	mlx_string_put(data.mlx_ptr, data.win_ptr, 10, data.win_h-50, 0xFFFFFFF, line2);
	mlx_string_put(data.mlx_ptr, data.win_ptr, 10, data.win_h-30, 0xFFFFFFF, line3);
}
