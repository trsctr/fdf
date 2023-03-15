/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:49:04 by oandelin          #+#    #+#             */
/*   Updated: 2023/03/15 15:54:59 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# define MLX_ERROR 1

typedef struct s_window {
	void		*mlx_ptr;
	void		*win_ptr;
	int			width;
	int			height;
}	t_window;

typedef struct s_img {
	t_window	win;
	void		*img_ptr;
	char		*addr;
	int			w;
	int			h;
	int			bpp;
	int			endian;
	int			line_len;
}	t_img;

typedef struct s_line {
	int			x_start;
	int			y_start;
	int			x_end;
	int			y_end;
}	t_line;

// #### INITIALIZE

t_window	new_window(int w, int h, char *title);
t_img		new_image(int w, int h, t_window window);

// #### DRAW

void		pixel_to_img(t_img *image, int x, int y, int color);

#endif