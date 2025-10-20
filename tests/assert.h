// tests/assert.h
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASSERT(cond, msg) do { \
  if (!(cond)) { \
    fprintf(stderr, "[FAIL] %s:%d: %s\n", __FILE__, __LINE__, msg); \
    return 1; \
  } \
} while (0)

#define ASSERT_EQ_INT(a,b) ASSERT((a)==(b), "ints not equal")
#define ASSERT_NE_PTR(p)   ASSERT((p)!=NULL, "unexpected NULL")
#define ASSERT_EQ_STR(a,b) ASSERT(strcmp((a),(b))==0, "strings not equal")