/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:38:51 by trsctr            #+#    #+#             */
/*   Updated: 2023/04/08 13:06:26 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


t_map parse_map(int fd, t_map map)
{
	char	*mapbuf;
	char	**lines;
	char	**split_line;
	int		**matrix;
	int i;
	int x = 0;
	int y = 0;

	mapbuf = read_map(mapbuf, fd);
	lines = ft_split(mapbuf, '\n');
	free(mapbuf);
	while (lines[i])
		i++;
	map.matrix = (int **) malloc(sizeof(int) * i + 1);
	map.rows = i;
	i = 0;
	while(lines[i])
	{
        split_line = ft_split(lines[i], ' ');
        map = convert_array(split_line, map, i);
		free(split_line);
        i++;
	}
	while(y < map.rows)
	{
		while(x < map.cols)
	 	{
	   	ft_printf("x%d,y%d: z%d	", x, y, map.matrix[y][x]);
		x++;
		}
		ft_printf("\n");
	   	y++;
	   	x = 0;
	}
	free(lines);
	return (map);
}

char *read_map(char *mapbuf, int fd)
{
	char *next_line;
    int i;

	mapbuf = ft_calloc(1,1);
    i = 0;
    next_line = get_next_line(fd);
    while (next_line)
    {
        mapbuf = ft_strjoin(mapbuf, next_line);
        free(next_line);
        next_line = get_next_line(fd);
        i++;
    }
    return(mapbuf);
}

t_map convert_array(char **line, t_map map, int row)
{
    int cols;
    int i;

    cols = 0;
    i = 0;
    while (line[i++])
        cols++;
	map.matrix[row] = (int *) malloc(sizeof(int) * (cols + 1));
    i = 0;
	while (i < cols)
    {
        map.matrix[row][i] = ft_atoi(line[i]);
        i++;
    }
	if (map.cols == 0)
		map.cols = cols;
	return (map);
}