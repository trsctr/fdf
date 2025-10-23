/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:38:51 by trsctr            #+#    #+#             */
/*   Updated: 2025/10/23 19:01:02 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void parse_map(t_fdf *data, int fd)
{
	t_list	*lines;

	lines = read_lines(fd);
	if (get_map_size(lines, &data->map.w, &data->map.h) == -1) {
		free_lines(lines);
		
		exit(1);
	}
	convert_lines_to_map(&data->map, lines);
	free_lines(lines);
}

t_list	*read_lines(int fd)
{
	t_list	*head;
	t_list	*new_node;
	t_list  *tail;
	char	*line;

	head = NULL;
	line = get_next_line(fd);
	while (line)
	{
		new_node = ft_lstnew(line);
		if (!new_node)
		{
			ft_putendl_fd("Error reading map: map file not valid", 2);
			exit(1);
		}
		if (!head)
			head = new_node;
		else
			tail->next = new_node;
		tail = new_node;
		line = get_next_line(fd);
	}
	free(line);
	return (head);
}

void convert_lines_to_map(t_map *map, t_list *lines)
{
	t_list *current;
	char **split_line;
	int i;

	i = 0;
	map->points = (t_point **)malloc(sizeof(t_point*) * (map->h));
	map->points[0] = (t_point *) malloc(sizeof(t_point) * (map->w) * (map->h));
	while (i < map->h) {
		map->points[i] = map->points[0] + i * map->w;
		i++;
	}
	i = 0;
	current = lines;
	while (current) {
		if (is_empty_line(current->content)) {
			current = current->next;
			continue;
		}
		split_line = ft_split(current->content, ' ');
	 	fill_array(split_line, map, i);
	 	destroy_strarr(split_line);
		free(split_line);
	 	i++;
		current = current->next;
	}
}

void	fill_array(char **line, t_map *map, int row)
{
	int		col;

	col = 0;
	while (line[col])
	{
		if (line[col][0] == '\n')
			break ;
		if (!ft_isdigit(line[col][0]) && line[col][0] != '-')
		{
			ft_printf("col %d row %d char '%c'\n", col, row, line[col][0]);
			ft_putendl_fd("Error reading map: map file not valid", 2);
			exit(1);
		}
		map->points[row][col].z = ft_atoi(line[col]);
		col++;
	}
	if (col != map->w)
	{	
		ft_putendl_fd("Error reading map: map file not valid", 2);
		exit (1);
	}
}
