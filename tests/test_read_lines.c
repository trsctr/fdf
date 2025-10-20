#include "../include/fdf.h"
#include "assert.h"

int make_tmp_file_with(const char *content);

int test_read_lines_basic() {
    int fd = make_tmp_file_with("10 20 30\n40 50 60\n70 80 90\n");
    ASSERT(fd >=0, "Failed to create temporary file");
    t_list *ls = read_lines(fd);
    ASSERT_NE_PTR(ls);
    ASSERT_NE_PTR(ls->content);
    ASSERT_EQ_STR((char *)ls->content, "10 20 30\n");
    ASSERT_NE_PTR(ls->next);
    ASSERT_EQ_STR((char *)ls->next->content, "40 50 60\n");
    ASSERT_NE_PTR(ls->next->next);
    ASSERT_EQ_STR((char *)ls->next->next->content, "70 80 90\n");
    ASSERT_EQ_INT(ft_lstsize(ls), 3);
    ASSERT(lseek(fd, 0, SEEK_CUR) != -1, "fd closed by read_map_list");
    free_lines(ls), close(fd);
    // Free list
    return 0;
}

int test_read_lines_empty() {
    int fd = make_tmp_file_with("");
    ASSERT(fd >=0, "Failed to create temporary file");
    t_list *ls = read_lines(fd);
    ASSERT_EQ_INT(ft_lstsize(ls), 0);
    free_lines(ls), close(fd);
    return 0;
}

int test_read_lines_only_newlines() {
    int fd = make_tmp_file_with("\n\n\n");
    ASSERT(fd >=0, "Failed to create temporary file");
    t_list *ls = read_lines(fd);
    ASSERT_EQ_INT(ft_lstsize(ls), 3);
    ASSERT_EQ_STR((char *)ls->content, "\n");
    ASSERT_EQ_STR((char *)ls->next->content, "\n");
    ASSERT_EQ_STR((char *)ls->next->next->content, "\n");
    free_lines(ls), close(fd);
    return 0;
}

