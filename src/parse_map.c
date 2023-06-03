/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:38:51 by trsctr            #+#    #+#             */
/*   Updated: 2023/06/03 14:19:22 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_fdf parse_map(t_fdf fdf, int fd)
{
	char	*map_buffer;
	char	**lines;
	int		i;

	i = 0;
	map_buffer = read_map(map_buffer, fd);
	lines = ft_split(map_buffer, '\n');
	free(map_buffer);
	while (lines[0][i])
	{
		if ((lines[0][i + 1] == ' ' || !lines[0][i + 1])
							&& ft_isalnum(lines[0][i]))
		{	
			fdf.map.w++;
		}
		i++;
	}
	while (lines[fdf.map.h])
		fdf.map.h++;
	fdf.map = convert_map(fdf.map, lines);
	free(lines);
	return (fdf);
}

t_map	convert_map(t_map map, char **lines)
{
	char	**split_line;
	int i;

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
		free(split_line);
		i++;
	}
	return (map);
}

char	*read_map(char *map_buffer, int fd)
{
	char	*next_line;
	int		i;

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
// int parse_color(char *str)
// {
// 	int i;
// 	int x;
// 	int color;

// 	i = ft_strlen(str);
// 	while(i)
// 	{
// 		if (str[i] >= '0' && str[i] <= '9')
// 			x = str[i] - '0'
// 		else x = hex[i] - 'A' + 10;


// }

t_map	fill_array(char **line, t_map map, int row)
{
	int	col;
//	char **split;

	col = 0;
	while (line[col])
	{
		if (!ft_isdigit(line[col][0]) && line[col][0] != '-')
		{
			ft_printf("your map sucks bro\n");
			exit(1);
		}
		map.points[row][col].z = ft_atoi(line[col]);
		map.points[row][col].color = 0x00FFFFFF;
		//else map.points[row][col].z = 0;
		// if (ft_strchr(line[col], ','))
		// {
		// 	split = ft_split(line[col], ',');
		// 	map.points[row][col].color = parse_color(split[1]);
		// }
		// else 
		//
		col++;
	}
	if (col != map.w)
	{	
	 	ft_printf("there must be something wrong with your map file, row: %d col: %d map.w = %d", row, col, map.w);
	 	exit(0);
	}
	return (map);
}
