/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:16:21 by trsctr            #+#    #+#             */
/*   Updated: 2023/06/06 20:56:36 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	handle_close(t_fdf *data)
{
	mlx_destroy_image(data->mlx_ptr, data->image.img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit (0);
}

void	handle_transform(int key, t_fdf *data)
{
	if (key == KEY_RIGHT)
		data->shift_x += 10;
	if (key == KEY_LEFT)
		data->shift_x -= 10;
	if (key == KEY_UP)
		data->shift_y -= 10;
	if (key == KEY_DOWN)
		data->shift_y += 10;
	if (key == KEY_W)
		data->zoom += 0.5;
	if (key == KEY_S && data->zoom > 1)
		data->zoom -= 0.5;
	if (key == KEY_Q)
		data->z_factor += 0.05;
	if (key == KEY_A)
		data->z_factor -= 0.05;
	if (key == KEY_SPACE)
		set_defaults(data);
	draw(data);
}

int	handle_keypress(int key, t_fdf *data)
{
	if (key == KEY_ESC)
	{	
		handle_close(data);
	}
	if (key == KEY_RIGHT || key == KEY_LEFT || key == KEY_UP || key == KEY_DOWN
		|| key == KEY_W || key == KEY_S || key == KEY_SPACE || key == KEY_A
		|| key == KEY_Q)
	{
		handle_transform(key, data);
	}
	return (0);
}
