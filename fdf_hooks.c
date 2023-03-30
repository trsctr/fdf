/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trsctr <trsctr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:16:21 by trsctr            #+#    #+#             */
/*   Updated: 2023/03/24 10:15:12 by trsctr           ###   ########.fr       */
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
	if (keysym == XK_Escape)
		mlx_destroy_window(window->mlx_ptr, window->win_ptr);

	printf("Keypress: %d\n", keysym);
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
