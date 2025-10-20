#include "../include/fdf.h"
#include "assert.h"

int make_tmp_file_with(const char *content);

int test_convert_map_to_lines_basic() {
    int fd = make_tmp_file_with("10 20 30\n\n40 50 60\n70 80 90\n");
    ASSERT(fd >=0, "Failed to create temporary file");
    t_list *lines = read_lines(fd);

    t_map *map;
    map = (t_map *)malloc(sizeof(t_map));
    map->w = 0;
    map->h = 0;

    get_map_size(lines, &map->w, &map->h);
    convert_lines_to_map(map, lines);
    ASSERT_EQ_INT(map->points[0][0].z, 10);
    ASSERT_EQ_INT(map->points[0][1].z, 20);
    ASSERT_EQ_INT(map->points[0][2].z, 30);
    ASSERT_EQ_INT(map->points[1][0].z, 40);
    ASSERT_EQ_INT(map->points[1][1].z, 50);
    ASSERT_EQ_INT(map->points[1][2].z, 60);
    ASSERT_EQ_INT(map->points[2][0].z, 70);
    ASSERT_EQ_INT(map->points[2][1].z, 80);
    ASSERT_EQ_INT(map->points[2][2].z, 90);
    free_lines(lines);
    //Free map points
    free(map->points[0]);
    free(map->points);
    free(map);
    close(fd);
    return 0;
}

int test_convert_map_to_lines_trailing_spaces() {
    int fd = make_tmp_file_with("1 2 3    \n-4 -5 6   \n7 8 9   \n");
    ASSERT(fd >=0, "Failed to create temporary file");
    t_list *lines = read_lines(fd);

    t_map *map;
    map = (t_map *)malloc(sizeof(t_map));
    map->w = 0;
    map->h = 0;

    get_map_size(lines, &map->w, &map->h);
    convert_lines_to_map(map, lines);
    ASSERT_EQ_INT(map->points[0][0].z, 1);
    ASSERT_EQ_INT(map->points[0][1].z, 2);
    ASSERT_EQ_INT(map->points[0][2].z, 3);
    ASSERT_EQ_INT(map->points[1][0].z, -4);
    ASSERT_EQ_INT(map->points[1][1].z, -5);
    ASSERT_EQ_INT(map->points[1][2].z, 6);
    ASSERT_EQ_INT(map->points[2][0].z, 7);
    ASSERT_EQ_INT(map->points[2][1].z, 8);
    ASSERT_EQ_INT(map->points[2][2].z, 9);  
    free_lines(lines);
    //Free map points
    free(map->points[0]);
    free(map->points);
    free(map);
    close(fd);
    return 0;
}
