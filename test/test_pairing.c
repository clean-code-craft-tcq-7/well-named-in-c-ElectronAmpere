#include "./test_pairing.h"
#include "../src/color_code_wire.h"
#include <assert.h>
#include <string.h>

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

void testNumberToPairInvalidLow(void) {
  ColorPair_t colorPair = GetColorFromPairNumber(0);
  const char *major = GetMajorColor(colorPair.majorColor);
  const char *minor = GetMinorColor(colorPair.minorColor);
  assert(strcmp(major, "White") == 0);
  assert(strcmp(minor, "Unknown") == 0);
}

void testNumberToPairInvalidHigh(void) {
  ColorPair_t colorPair = GetColorFromPairNumber(26);
  const char *major = GetMajorColor(colorPair.majorColor);
  const char *minor = GetMinorColor(colorPair.minorColor);
  assert(strcmp(major, "Invalid") == 0);
  assert(strcmp(minor, "Blue") == 0);
}

void testPairToNumberInvalidMajor(void) {
  ColorPair_t colorPair;
  colorPair.majorColor = (MajorColor_t)-1;
  colorPair.minorColor = BLUE;
  int pairNumber = GetPairNumberFromColor(&colorPair);
  assert(pairNumber < 0); // Negative as indicator of invalid
}
