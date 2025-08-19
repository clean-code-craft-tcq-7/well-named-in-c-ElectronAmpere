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

void testColorNames(void) {
  testGetMajorColor(0, "White");
  testGetMajorColor(1, "Red");
  testGetMajorColor(2, "Black");
  testGetMajorColor(3, "Yellow");
  testGetMajorColor(4, "Violet");
  testGetMajorColor(-1, "Unknown");
  testGetMajorColor(5, "Invalid");

  testGetMinorColor(0, "Blue");
  testGetMinorColor(1, "Orange");
  testGetMinorColor(2, "Green");
  testGetMinorColor(3, "Brown");
  testGetMinorColor(4, "Slate");
  testGetMinorColor(-1, "Unknown");
  testGetMinorColor(5, "Invalid");
}
