#include "./test_pairing.h"
#include "../src/color_code_wire.h"
#include <assert.h>

void testNumberToPair(int pairNumber, MajorColor_t expectedMajor,
                      MinorColor_t expectedMinor) {
  ColorPair_t colorPair = GetColorFromPairNumber(pairNumber);
  assert(colorPair.majorColor == expectedMajor);
  assert(colorPair.minorColor == expectedMinor);
}

void testPairToNumber(MajorColor_t major, MinorColor_t minor,
                      int expectedPairNumber) {
  ColorPair_t colorPair;
  colorPair.majorColor = major;
  colorPair.minorColor = minor;
  int pairNumber = GetPairNumberFromColor(&colorPair);
  printf("testPairToNumber %d\n", pairNumber);
  assert(pairNumber == expectedPairNumber);
}
