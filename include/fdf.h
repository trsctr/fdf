/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:49:04 by oandelin          #+#    #+#             */
/*   Updated: 2023/05/30 19:53:45 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/include/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
// # include <X11/keysym.h>
// # include <X11/X.h>
# define MLX_ERROR 1
# define WIN_W 1024
# define WIN_H 768

typedef struct s_point {
	int		z;
	int		color;
}	t_point;

typedef struct s_map {
	int			w;
	int			h;
	t_point		**points;
}	t_map;

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
	int			zoom;
	float		angle;
	int			shift_x;
	int			shift_y;
	t_map		map;
}	t_fdf;
// #### INITIALIZE

t_fdf		new_window(t_fdf data);
t_img		new_image(int w, int h, t_fdf data);
void		set_defaults(t_fdf *fdf);

// #### READING THE MAP

t_fdf		parse_map(t_fdf fdf, int fd);
t_map		get_map_size(t_map map, char **lines);
char		*read_map(char *mapbuf, int fd);
t_map		convert_array(char **line, t_map map, int row);

// #### DRAW

void		pixel_to_img(t_fdf *data, int x, int y, int color);
void		draw_line(t_fdf *fdf, float x, float y, float x1, float y1);
void		draw(t_fdf *data);
void		menu(t_fdf data);

// #### COLOR

int			get_t(int color);
int			get_r(int color);
int			get_g(int color);
int			get_b(int color);
int			set_color(int transparency, int red, int green, int blue);

// #### HOOKS

int			handle_no_event(void *data);
int			handle_keypress(int keysym, t_fdf *data);
int			handle_keyrelease(int keysym, void *data);

#endif