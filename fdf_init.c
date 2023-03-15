/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:47:46 by oandelin          #+#    #+#             */
/*   Updated: 2023/03/15 15:51:29 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_window new_window (int w, int h, char *title)
{
	t_window window;

	window.mlx_ptr = mlx_init();
	window.width = w;
	window.height = h;
	window.win_ptr = mlx_new_window(window.mlx_ptr, w, h, title);
	return (window);
}

t_img new_image(int w, int h, t_window window)
{
	t_img image;

	image.win = window;
	image.img_ptr = mlx_new_image(window.mlx_ptr, w, h);
	image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp), \
							&(image.line_len), &(image.endian));
	image.w = w;
	image.h = h;
	return (image);
}