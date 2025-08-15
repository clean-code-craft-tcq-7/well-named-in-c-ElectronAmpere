#include "./color_code_wire.h"
#include <stdio.h>

const char *MajorColorNames[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char *MinorColorNames[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

const char *GetMajorColor(int index) {
  if (index < 0)
    return "Unknown";
  if (index >= numberOfMajorColors)
    return "Invalid";
  return MajorColorNames[index];
}

const char *GetMinorColor(int index) {
  if (index < 0)
    return "Unknown";
  if (index >= numberOfMinorColors)
    return "Invalid";
  return MinorColorNames[index];
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
