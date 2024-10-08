/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:49:04 by oandelin          #+#    #+#             */
/*   Updated: 2024/09/26 15:44:47 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/include/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include "keys.h"
# define MLX_ERROR 1
# define WIN_W 1024
# define WIN_H 768

enum e_events{
	ON_CLOSE = 17,
	ON_KEYPRESS = 2,
	ON_KEYRELEASE = 3
};

// enum e_keys {
// 	KEY_ESC = 53,
// 	KEY_LEFT = 123,
// 	KEY_RIGHT = 124,
// 	KEY_DOWN = 125,
// 	KEY_UP = 126,
// 	KEY_W = 13,
// 	KEY_S = 1,
// 	KEY_A = 0,
// 	KEY_Q = 12,
// 	KEY_SPACE = 49
// };

enum e_direction {
	HORIZONTAL = 0,
	VERTICAL = 1
};

typedef struct s_point {
	int		z;
}	t_point;

typedef struct s_coords {
	int		x;
	int		y;
}	t_coords;

typedef struct s_map {
	int			w;
	int			h;
	t_point		**points;
}	t_map;

typedef struct s_img {
	void		*img_ptr;
	int			*imgdata;
	int			w;
	int			h;//
	int			bpp;
	int			endian;
	int			line_len;
}	t_img;

typedef struct s_line {
	double		x;
	double		y;
	double		x1;
	double		y1;
	double		z;
	double		z1;
}	t_line;

typedef struct s_fdf {
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		image;
	int			win_w;
	int			win_h;
	double		zoom;
	double		angle;
	int			shift_x;
	int			shift_y;
	double		z_factor;
	t_map		map;
}	t_fdf;

// #### INITIALIZE

t_fdf		new_window(t_fdf data);
t_img		new_image(int w, int h, t_fdf data);
void		set_defaults(t_fdf *data);

// #### READING THE MAP

t_fdf		parse_map(t_fdf *data, int fd);
char		*read_map(char *mapbuf, int fd);
t_map		convert_map(t_map map, char **lines);
t_map		fill_array(char **line, t_map map, int row);
void		destroy_strarr(char **arr);

// #### PROJECTION

void		project_line(t_fdf *data, t_coords coordinates, int direction);
void		shift_line(t_fdf *data, t_line *line);
void		isometric(t_line *line, t_fdf *data);
void		get_zoom(t_fdf *data, t_line *line);
void		get_z(t_line *line, t_fdf *data);

// #### DRAW

void		pixel_to_img(t_fdf *data, int x, int y, int color);
void		draw(t_fdf *data);
void		bresenham(t_fdf *data, t_line *line);
void		instructions(t_fdf data);

// #### HOOKS

int			handle_keypress(int key, t_fdf *data);
int			handle_close(t_fdf *data);

#endif