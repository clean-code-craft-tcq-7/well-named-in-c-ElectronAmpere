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

void testGenerateManualPrint(void) {
  char buffer[BUFFER_SIZE_MAX] = {0};
  GenerateManualErrorType_t result;
  result = generateManualTypePrint(buffer, BUFFER_SIZE_MAX);
  printf("%s", buffer);
  assert(result == GMERROR_NULL);
}

void testGenerateManualBufferEmpty(void) {
  GenerateManualErrorType_t result;
  result = generateManualTypePrint(NULL, BUFFER_SIZE_MAX);
  printf("generateManualTypePrint: %d\n", result);
  assert(result == GMERROR_BUFFER_EMPTY);
}

void testGenerateManualHeaderEmpty(void) {
  // Remark: Not testable unless manipulated or the funtion snprintf fails
  // Note: Need to update implementation for better tests
  GenerateManualErrorType_t result;
  char buffer[30] = {0};
  result = generateManualTypePrint(buffer, 30);
  printf("generateManualTypePrint: %d\n", result);
  assert(result == GMERROR_HEADER_EMPTY);
}

void testGenerateManualBodyEmpty(void) {
  // Remark: Not testable unless manipulated or the funtion snprintf fails
  // Note: Need to update implementation for better tests
  GenerateManualErrorType_t result;
  char buffer[100] = {0};
  result = generateManualTypePrint(buffer, 100);
  printf("generateManualTypePrint: %d\n", result);
  assert(result == GMERROR_BODY_EMPTY);
}

void testGenerateManualTruncation(void) {
  GenerateManualErrorType_t result;
  char buffer[100] = {0};
  result = generateManualTypePrint(buffer, 100);
  printf("generateManualTypePrint: %d\n", result);
  assert(result == GMERROR_DATA_TRUNCATED);
}

void testGenerateManualMarkdown(void) {
  char buffer[1500] = {0};
  GenerateManualErrorType_t result;
  result = generateManualTypeMarkdown(buffer, 1500, "./test/manual.md");
  printf("generateManualTypeMarkdown: %d\n", result);
  printf("%s", buffer);
  assert(result == GMERROR_NULL);
}

void testGenerateManualCSV(void) {
  char buffer[BUFFER_SIZE_MAX] = {0};
  GenerateManualErrorType_t result;
  result = generateManualTypeCSV(buffer, BUFFER_SIZE_MAX, "./test/manual.csv");
  printf("generateManualTypeCSV: %d\n", result);
  printf("%s", buffer);
  assert(result == GMERROR_NULL);
}

int main() {
  testNumberToPair(4, WHITE, BROWN);
  testNumberToPair(5, WHITE, SLATE);

  testPairToNumber(BLACK, ORANGE, 12);
  testPairToNumber(VIOLET, SLATE, 25);

  testGenerateManualPrint();
  testGenerateManualBufferEmpty();
  testGenerateManualTruncation();

  testGenerateManualMarkdown();
  testGenerateManualCSV();

  return 0;
}
