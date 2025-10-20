#include "../include/fdf.h"
#include "assert.h"

int make_tmp_file_with(const char *content);

int test_get_map_size_basic() {
    int fd = make_tmp_file_with("10 20 30\n40 50 60\n70 80 90\n");
    ASSERT(fd >=0, "Failed to create temporary file");
    t_list *ls = read_lines(fd);

    int width = 0, height = 0;
    int rc = get_map_size(ls, &width, &height);
    ASSERT_EQ_INT(rc, 0);
    ASSERT_EQ_INT(width, 3);
    ASSERT_EQ_INT(height, 3);

    free_lines(ls);
    return 0;
}

int test_get_map_size_inconsistent() {
    int fd = make_tmp_file_with("10 20 30\n40 50\n70 80 90\n");
    ASSERT(fd >=0, "Failed to create temporary file");
    t_list *ls = read_lines(fd);

    int width = 0, height = 0;
    int rc = get_map_size(ls, &width, &height);
    ASSERT_EQ_INT(rc, -1); // should return error

    free_lines(ls);
    return 0;
}

int test_get_map_size_only_newlines() {
    int fd = make_tmp_file_with("\n\n\n");
    ASSERT(fd >=0, "Failed to create temporary file");
    t_list *ls = read_lines(fd);

    int width = 0, height = 0;
    int rc = get_map_size(ls, &width, &height);
    ASSERT_EQ_INT(rc, 0);
    ASSERT_EQ_INT(width, 0);
    ASSERT_EQ_INT(height, 0);

    free_lines(ls);
    return 0;
}