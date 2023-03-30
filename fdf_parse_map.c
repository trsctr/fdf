/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trsctr <trsctr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:38:51 by trsctr            #+#    #+#             */
/*   Updated: 2023/03/24 18:26:12 by trsctr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void parse_map(int fd)
{
    char    *mapbuf;
    char    **lines;
    char    **split_line;
    int     **matrix;

    int i = 0;
    matrix = ft_calloc(1,1);
    mapbuf = ft_calloc(1,1);
    mapbuf = read_map(mapbuf, fd);
    lines = ft_split(mapbuf, '\n');
    free(mapbuf);
    while(lines[i])
    {
        split_line = ft_split(lines[i], ' ');
        matrix[i] = convert_array(split_line);
        free(split_line);
        i++;
    }
}

char *read_map(char *mapbuf, int fd)
{
    char *next_line;
    int i;

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

int *convert_array(char **strarray)
{
    int *arr;
    int arrsize;
    int i;

    arrsize = 0;
    i = 0;
    while (strarray[i++])
        arrsize++;
    arr = (int *) malloc(sizeof(int) * (arrsize + 1));
    i = 0;
    while (i < arrsize)
    {
        arr[i] = ft_atoi(strarray[i]);
        i++;
    }
//    ft_printf("arr[i] %d, strarray[i] %s\n", arr[i-1], strarray[i-1]);
    return(arr);
}