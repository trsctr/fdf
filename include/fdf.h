/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:49:04 by oandelin          #+#    #+#             */
/*   Updated: 2023/04/27 16:54:21 by oandelin         ###   ########.fr       */
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
# define WIN_W 800
# define WIN_H 600

typedef struct s_point {
	int		x;
	int		y;
	int		z;
	int			color;
}	t_point;

typedef struct s_map {
	int			w;
	int			h;
	t_point		**points;
}	t_map;

// typedef struct s_window {

// 	int			w;
// 	int			h;
// 	char		*title;
// }	t_window;

typedef struct s_img {
	void		*img_ptr;
	int			*imgdata;
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

typedef struct s_fdf {
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		image;
	int			win_w;
	int			win_h;
	t_map		map;
}	t_fdf;
// #### INITIALIZE

t_fdf new_window (t_fdf data);

t_img new_image(int w, int h, t_fdf data);

// #### READING THE MAP

t_map		parse_map(t_map map, int fd);
t_map		get_map_size(t_map map, char **lines);
char		*read_map(char *mapbuf, int fd);
t_map		convert_array(char **line, t_map map, int row);

// #### DRAW

void		pixel_to_img(t_fdf *data, int x, int y, int color);
void		bresenham(t_img image, int x1, int y1, int x2, int y2);
void		draw_rect(t_img image, int x, int y, int w, int h);
int			draw_line (t_fdf fdf, int x, int y, int x2, int y2);
void		draw(t_fdf data);
void		menu(t_fdf data);
void draw_moire(t_fdf fdf, int left, int top, int right, int bottom);



// #### HOOKS

int			handle_no_event(void *data);
int	handle_keypress(int keysym, t_fdf *data);
int			handle_keyrelease(int keysym, void *data);

#endif