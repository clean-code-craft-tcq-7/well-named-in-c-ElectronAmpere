#include <assert.h>
#include <stdio.h>

#include "../src/colorCodeMapper.h"

void testNumberToPair(int pairNumber, MajorColor_t expectedMajor,
                      MinorColor_t expectedMinor) {
  ColorPair_t colorPair = GetColorFromPairNumber(pairNumber);
  char colorPairNames[MAX_COLORPAIR_NAME_CHARS];
  ColorPairToString(&colorPair, colorPairNames);
  printf("Got pair %s\n", colorPairNames);
  assert(colorPair.majorColor == expectedMajor);
  assert(colorPair.minorColor == expectedMinor);
}

void testPairToNumber(MajorColor_t major, MinorColor_t minor,
                      int expectedPairNumber) {
  ColorPair_t colorPair;
  colorPair.majorColor = major;
  colorPair.minorColor = minor;
  int pairNumber = GetPairNumberFromColor(&colorPair);
  printf("Got pair number %d\n", pairNumber);
  assert(pairNumber == expectedPairNumber);
}

int main() {
  testNumberToPair(4, WHITE, BROWN);
  testNumberToPair(5, WHITE, SLATE);

  testPairToNumber(BLACK, ORANGE, 12);
  testPairToNumber(VIOLET, SLATE, 25);

  return 0;
}
