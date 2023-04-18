/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:49:04 by oandelin          #+#    #+#             */
/*   Updated: 2023/04/18 16:31:07 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/include/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
// # include <X11/keysym.h>
// # include <X11/X.h>
# define MLX_ERROR 1

typedef struct s_point {
	int		x;
	int		y;
	int		z;
	int			color;
}	t_point;

typedef struct s_map {
	int			rows;
	int			cols;
	t_point		**points;
}	t_map;

typedef struct s_window {
	int			width;
	int			height;
	void		*mlx_ptr;
	void		*win_ptr;
//	t_map		*map;
}	t_window;

typedef struct s_img {
	char		*addr;
	int			w;
	int			h;
	int			bpp;
	int			endian;
	int			line_len;
	void		*img_ptr;
	t_window	win;
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

// #### READING THE MAP

t_map		parse_map(t_map map, int fd);
t_map		get_map_size(t_map map, char **lines);
char		*read_map(char *mapbuf, int fd);
t_map		convert_array(char **line, t_map map, int row);

// #### DRAW

void		pixel_to_img(t_img *image, int x, int y, int color);
void		bresenham(t_img image, int x1, int y1, int x2, int y2);
void		draw_rect(t_img image, int x, int y, int w, int h);
int			draw_line (t_img image, t_point start, t_point end);

// #### HOOKS

int			handle_no_event(void *data);
int			handle_keypress(int keysym, t_window *window);
int			handle_keyrelease(int keysym, void *data);

#endif