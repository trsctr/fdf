/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:16:21 by trsctr            #+#    #+#             */
/*   Updated: 2023/03/30 15:06:39 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	handle_no_event(void *data)
{
	/* This function needs to exist, but it is useless for the moment */
	return (0);
}

int	handle_keypress(int keysym, t_window *window)
{
	ft_printf("Keypress: %d\n", keysym);
	if (keysym == 53)
	{	
		mlx_destroy_window(window->mlx_ptr, window->win_ptr);
		ft_printf("lol imma exit\n");
		free(window->matrix);
		exit(0);}
	return (0);
}

int	handle_keyrelease(int keysym, void *data)
{
	printf("Keyrelease: %d\n", keysym);

	return (0);
}

// int close(int keycode, s_data data)
// {
// 	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
// 	return(0);
// }



// int	key_hook(int keycode, t_window *window)
// {
// 	mlx_destroy_window(window->mlx_ptr, window->win_ptr);
// 	printf("hihi\n");
// 	exit(0);
// }
