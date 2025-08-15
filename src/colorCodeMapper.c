#include "./colorCodeMapper.h"
#include <stdio.h>

const char *MajorColorNames[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char *MinorColorNames[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

void ColorPairToString(const ColorPair_t *colorPair, char *buffer) {
  sprintf(buffer, "%s %s", MajorColorNames[colorPair->majorColor],
          MinorColorNames[colorPair->minorColor]);
}

ColorPair_t GetColorFromPairNumber(int pairNumber) {
  ColorPair_t colorPair;
  int zeroBasedPairNumber = pairNumber - 1;
  colorPair.majorColor =
      (MajorColor_t)(zeroBasedPairNumber / numberOfMinorColors);
  colorPair.minorColor =
      (MinorColor_t)(zeroBasedPairNumber % numberOfMinorColors);
  return colorPair;
}

int GetPairNumberFromColor(const ColorPair_t *colorPair) {
  return colorPair->majorColor * numberOfMinorColors + colorPair->minorColor +
         1;
}
