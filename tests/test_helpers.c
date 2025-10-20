// tests/test_helpers.c
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int make_tmp_file_with(const char *content) {
  char tmpl[] = "/tmp/fdfXXXXXX";
  int fd = mkstemp(tmpl);
  if (fd < 0) return -1;
  unlink(tmpl); // auto-clean after close
  write(fd, content, (unsigned)strlen(content));
  lseek(fd, 0, SEEK_SET);
  return fd;
}
