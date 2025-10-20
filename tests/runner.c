#include <stdio.h>

int test_read_lines_basic();
int test_read_lines_empty();
int test_read_lines_only_newlines();
int test_count_tokens();
int test_get_map_size_basic();
int test_get_map_size_inconsistent();
int test_get_map_size_only_newlines();
int test_convert_map_to_lines_basic();
int test_convert_map_to_lines_trailing_spaces();

typedef int (*test_fn)();

int main(void) {
  struct { const char* name; test_fn fn; } tests[] = {
    {"read_lines_basic", test_read_lines_basic  },
    {"read_lines_empty", test_read_lines_empty    },
    {"read_lines_only_newlines", test_read_lines_only_newlines},
    {"count_tokens", test_count_tokens},
    {"get_map_size_basic", test_get_map_size_basic},
    {"get_map_size_inconsistent", test_get_map_size_inconsistent},
    {"get_map_size_only_newlines", test_get_map_size_only_newlines},
    {"convert_map_to_lines_basic", test_convert_map_to_lines_basic},
    {"convert_map_to_lines_trailing_spaces", test_convert_map_to_lines_trailing_spaces},
};
  int fails = 0;
  for (size_t i = 0; i < sizeof(tests)/sizeof(*tests); ++i) {
    int rc = tests[i].fn();
    printf("%-22s : %s\n", tests[i].name, rc ? "FAIL" : "OK");
    fails += (rc != 0);
  }
  return fails ? 1 : 0;
}