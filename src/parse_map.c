/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:38:51 by trsctr            #+#    #+#             */
/*   Updated: 2024/09/26 15:44:42 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_fdf	parse_map(t_fdf *data, int fd)
{
	char	*map_buffer;
	char	**lines;
	int		i;

	i = 0;
	data->map.h = 0;
	data->map.w = 0;
	map_buffer = ft_calloc(1, 1);
	map_buffer = read_map(map_buffer, fd);
	lines = ft_split(map_buffer, '\n');
	free(map_buffer);
	while (lines[0][i])
	{
		if ((lines[0][i + 1] == ' ' || !lines[0][i + 1])
							&& ft_isalnum(lines[0][i]))
			data->map.w++;
		i++;
	}
	while (lines[data->map.h] != NULL)
		data->map.h++;
	data->map = convert_map(data->map, lines);
	destroy_strarr(lines);
	free(lines);
	return (*data);
}

char	*read_map(char *map_buffer, int fd)
{
	char	*temp;
	char	*next_line;

	next_line = get_next_line(fd);
	while (next_line)
	{
		temp = ft_strjoin(map_buffer, next_line);
		if (map_buffer)
			free(map_buffer);
		free(next_line);
		map_buffer = temp;
		next_line = get_next_line(fd);
	}
	free(next_line);
	close(fd);
	if (map_buffer[0] == '\0')
	{
		ft_putendl_fd("Error reading map: map file not valid", 2);
		exit(1);
	}
	return (map_buffer);
}

t_map	convert_map(t_map map, char **lines)
{
	char	**split_line;
	int		i;

	i = 0;
	map.points = (t_point **)malloc(sizeof(t_map)
			* sizeof(t_point) * (map.h));
	while (i <= map.h)
	{
		map.points[i] = (t_point *) malloc(sizeof(t_point) * (map.w));
		i++;
	}
	i = 0;
	while (lines[i])
	{
		split_line = ft_split(lines[i], ' ');
		map = fill_array(split_line, map, i);
		destroy_strarr(split_line);
		free(split_line);
		i++;
	}
	return (map);
}

t_map	fill_array(char **line, t_map map, int row)
{
	int		col;

	col = 0;
	while (line[col])
	{
		if (!ft_isdigit(line[col][0]) && line[col][0] != '-')
		{
			ft_putendl_fd("Error reading map: map file not valid", 2);
			exit(1);
		}
		map.points[row][col].z = ft_atoi(line[col]);
		col++;
	}
	if (col != map.w)
	{	
		ft_putendl_fd("Error reading map: map file not valid", 2);
		exit (1);
	}
	return (map);
}

void	destroy_strarr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	while (i >= 0)
	{
		free(arr[i]);
		i--;
	}
}
