/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:22:39 by oandelin          #+#    #+#             */
/*   Updated: 2025/10/20 18:23:50 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void free_lines(t_list *lines) {
	ft_lstclear(&lines, free);
}

int count_tokens(const char *line) {
	int count;
	int in_token;

	count = 0;
	in_token = 0;
	while(*line && *line != '\n') {
		if (*line == ' ' || *line == '\t') {
			in_token = 0;
		}
		else if (!in_token && (ft_isalnum(*line))) {
			in_token = 1;
			count++;
		}
		line++;
	}
	return count;
}

int is_empty_line(const char *line) {
	while (*line) {
		if (*line != ' ' && *line != '\t' && *line != '\n') {
			return 0;
		}
		line++;
	}
	return 1;
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

int get_map_size(t_list *lines, int *width, int *height) {
	int w;
	int h;
	int current_w;

	h = 0;
	w = 0;
	while(lines) {
		char *line = lines->content;
		if (!line || is_empty_line(line)) {
			lines = lines->next;
			continue;
		}
		current_w = count_tokens(line);
		if (w == 0) {
			w = current_w;
		} else if (current_w != w) {
			ft_putendl_fd("Error reading map: inconsistent row lengths", 2);
			return -1;
		}
		h++;
		lines = lines->next;
	}
	*width = w;
	*height = h;
	return 0;
}