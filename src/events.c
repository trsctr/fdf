/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:16:21 by trsctr            #+#    #+#             */
/*   Updated: 2023/06/03 16:28:49 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	handle_no_event(void *data)
{
	/* This function needs to exist, but it is useless for the moment */
	return (0);
}

void	destroy_everything(t_fdf *data)
{
	int	y;

	y = data->map.h;
	mlx_destroy_image(data->mlx_ptr, data->image.img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	while (--y >= 0)
	{
		free(data->map.points[y]);
	}
	free((void *)data->map.points);


}

int	handle_close(t_fdf *data)
{
	destroy_everything(data);
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
	ft_printf("Keypress: %d\n", key);
	if (key == KEY_ESC)
	{	
		destroy_everything(data);
		exit (0);
	}
	if (key == KEY_RIGHT || key == KEY_LEFT || key == KEY_UP || key == KEY_DOWN
		|| key == KEY_W || key == KEY_S || key == KEY_SPACE || key == KEY_A
		|| key == KEY_Q)
	{
		handle_transform(key, data);
	}
	return (0);
}

int	handle_keyrelease(int keysym, void *data)
{
	ft_printf("Keyrelease: %d\n", keysym);

	return (0);
}
