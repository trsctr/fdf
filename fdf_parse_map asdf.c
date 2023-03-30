/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trsctr <trsctr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:38:51 by trsctr            #+#    #+#             */
/*   Updated: 2023/03/24 18:05:42 by trsctr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void parse_map(int fd)
{
    char *next_line;
    // char *mapbuf;
    // char *temp;
    int i;
    char **line_split;
    int **matrix;
    int row;
    int col;

    matrix = ft_calloc(1,1);
    // mapbuf = ft_calloc(1,1);
    i = 0;
    next_line = get_next_line(fd);
    while (next_line)
    {
    //     mapbuf = ft_strjoin(mapbuf, next_line);
        next_line = ft_strtrim(next_line, " ");
        line_split = ft_split(next_line, ' ');
        matrix[i] = convert_array(line_split);
        next_line = get_next_line(fd);
        i++;
    }
    // ft_printf("%d", i); 
    // ft_printf("%s", mapbuf);

    // line_split = ft_split(next_line, ' ');
    // matrix[0] = convert_array(line_split);
    // free(next_line);
    // free(line_split);
    // next_line = get_next_line(fd);
    // line_split = ft_split(next_line, ' ');
//    *arr[1] = convert_arr(line_split);
//     row = 0;
//     col = 0;
//     while(row < 2)
//     {
//         while(col < 2)
//         {
//             ft_printf("%d ", matrix[row][col]);
//             col++;
//         }
//         col = 0;
//         ft_printf("\n");
//         row++;
//     } 
// }
}

int *convert_array(char **strarray)
{
    int *arr;
    int arrsize;
    int i;

    arrsize = 0;
    i = 0;
    while (strarray[i])
    {    
        arrsize++;
        i++;
    }
    ft_printf("arr width: %d\n", arrsize);
    arr = (int *) malloc(sizeof(int) * (arrsize));
    i = 0;
    while (i < arrsize)
    {
        arr[i] = ft_atoi(strarray[i]);
        i++;
    }
//    ft_printf("arr[i] %d, strarray[i] %s\n", arr[i-1], strarray[i-1]);
    return(arr);
}