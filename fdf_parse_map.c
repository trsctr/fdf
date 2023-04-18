/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:38:51 by trsctr            #+#    #+#             */
/*   Updated: 2023/04/18 16:31:22 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map parse_map(t_map map, int fd)
{
	char	*map_buffer;
	char	*next_line;
	char	**lines;
	char	**split_line;
	int	i;

	i = 0;
	map_buffer = read_map(map_buffer, fd);
	lines = ft_split(map_buffer, '\n');
	free(map_buffer);
	map = get_map_size(map, lines);
	map.points = (t_point **)malloc(sizeof(t_map) * sizeof(t_point) * (map.rows));
	while(i < map.rows)
	{
		map.points[i] = (t_point *) malloc(sizeof(t_point) * (map.cols));
		i++;
	}
	i = 0;
	while(lines[i])
	{
		split_line = ft_split(lines[i], ' ');
        map = convert_array(split_line, map, i);
		free(split_line);
        i++;
	}
	free(lines);
	return (map);
}

t_map	get_map_size(t_map map, char **lines)
{
	int	i;

	i = 0;
	map.rows = 0;
	map.cols = 0;
	while (lines[0][i])
	{
		if ((lines[0][i + 1] == ' ' || !lines[0][i + 1])
							&& ft_isdigit(lines[0][i]))
		{	
			map.cols++;
		}
		i++;
	}
	while (lines[map.rows])
		map.rows++;
	return (map);
}

char *read_map(char *map_buffer, int fd)
{
	char *next_line;
    int i;

	map_buffer = ft_calloc(1,1);
    next_line = get_next_line(fd);
	while (next_line)
    {
        map_buffer = ft_strjoin(map_buffer, next_line);
        free(next_line);
        next_line = get_next_line(fd);
        i++;
    }
	return (map_buffer);
}

t_map convert_array(char **line, t_map map, int row)
{
    int col;

    col = 0;
	while (col < map.cols)
	{
		map.points[row][col].x = col;
		map.points[row][col].y = row;
		map.points[row][col].z = ft_atoi(line[col]);
		// tahan strrchrr if jos loytyy ; poimitaan vari
		map.points[row][col].color = 0x00FF0000;
		col++;
	}
	return (map);
}
