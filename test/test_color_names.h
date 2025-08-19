#ifndef __TEST_COLOR_NAMES_H__
#define __TEST_COLOR_NAMES_H__

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

#include "../src/color_code_wire.h"

void testGetMajorColor(int index, const char *expected);
void testGetMinorColor(int index, const char *expected);

#ifdef __cplusplus
}
#endif

#endif /* __TEST_COLOR_NAMES_H__ */
