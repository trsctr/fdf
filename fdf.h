/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trsctr <trsctr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:49:04 by oandelin          #+#    #+#             */
/*   Updated: 2023/03/30 12:34:57 by trsctr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>
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

// #### PARSING

void parse_map(int fd);
char *read_map(char *mapbuf, int fd);
int *convert_array(char **strarray);

// #### DRAW

void	pixel_to_img(t_img *image, int x, int y, int color);
void	bresenham(t_img image, int x1, int y1, int x2, int y2);
void	draw_rect (t_img image, int x, int y, int w, int h);

// #### HOOKS

int	handle_no_event(void *data);
int	handle_keypress(int keysym, t_window *window);
int	handle_keyrelease(int keysym, void *data);

#endif