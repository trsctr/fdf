#include <stdio.h>

int test_read_lines_basic();
int test_read_lines_empty();
int test_read_lines_only_newlines();

typedef int (*test_fn)();

int main(void) {
  struct { const char* name; test_fn fn; } tests[] = {
    {"read_lines_basic", test_read_lines_basic  },
    {"read_lines_empty", test_read_lines_empty    },
    {"read_lines_only_newlines", test_read_lines_only_newlines},
  };
  int fails = 0;
  for (size_t i = 0; i < sizeof(tests)/sizeof(*tests); ++i) {
    int rc = tests[i].fn();
    printf("%-22s : %s\n", tests[i].name, rc ? "FAIL" : "OK");
    fails += (rc != 0);
  }
  return fails ? 1 : 0;
}