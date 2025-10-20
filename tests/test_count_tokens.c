#include "../include/fdf.h"
#include "assert.h"

int test_count_tokens() {
    ASSERT_EQ_INT(count_tokens("10 20 30\n"), 3);
    ASSERT_EQ_INT(count_tokens("   10   20   30   \n"), 3);
    ASSERT_EQ_INT(count_tokens("10\t20\t30\n"), 3);
    ASSERT_EQ_INT(count_tokens("10  20\t  30  \n"), 3);
    ASSERT_EQ_INT(count_tokens("\n"), 0);
    ASSERT_EQ_INT(count_tokens("   \t   \n"), 0);
    ASSERT_EQ_INT(count_tokens("10\n"), 1);
    ASSERT_EQ_INT(count_tokens("-20 40 0x;fffff ------"), 3);
    ASSERT_EQ_INT(count_tokens("10 20\n30 40\n"), 2); // only first line counts
    return 0;
}