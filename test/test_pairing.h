#ifndef __TEST_PAIRING_H__
#define __TEST_PAIRING_H__

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

#include "../src/color_code_wire.h"
#include "../src/generate_manual.h"

void testNumberToPair(int pairNumber, MajorColor_t expectedMajor,
                      MinorColor_t expectedMinor);
void testPairToNumber(MajorColor_t major, MinorColor_t minor,
                      int expectedPairNumber);
void testNumberToPairInvalidLow(void);
void testNumberToPairInvalidHigh(void);
void testPairToNumberInvalidMajor(void);

#ifdef __cplusplus
}
#endif

#endif /* __TEST_PAIRING_H__ */
