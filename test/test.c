#include <assert.h>
#include <stdio.h>

#include "../src/color_code_wire.h"
#include "../src/generate_manual.h"

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
  printf("Got pair number %d\n", pairNumber);
  assert(pairNumber == expectedPairNumber);
}

void testGenerateManual(void) {
  char buffer[BUFFER_SIZE_MAX] = {0};
  GeneratePrintErrorType_t result;
  result = generateManualTypePrint(buffer, BUFFER_SIZE_MAX);
  printf("%s", buffer);
  assert(result == GPERROR_NULL);
}

int main() {
  testNumberToPair(4, WHITE, BROWN);
  testNumberToPair(5, WHITE, SLATE);

  testPairToNumber(BLACK, ORANGE, 12);
  testPairToNumber(VIOLET, SLATE, 25);

  testGenerateManual();
  return 0;
}
