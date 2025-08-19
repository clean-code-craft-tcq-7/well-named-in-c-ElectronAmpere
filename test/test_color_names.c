#include "./test_color_names.h"
#include <assert.h>
#include <string.h>

void testGetMajorColor(int index, const char *expected) {
  const char *result = GetMajorColor(index);
  assert(strcmp(result, expected) == 0);
}

void testGetMinorColor(int index, const char *expected) {
  const char *result = GetMinorColor(index);
  assert(strcmp(result, expected) == 0);
}
