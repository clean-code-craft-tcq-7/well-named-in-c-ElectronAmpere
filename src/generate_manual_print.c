#include "./color_code_wire.h"
#include "./generate_manual.h"
#include <stdio.h>

GenerateManualErrorType_t generateManualTypePrint(char *buffer,
                                                  size_t bufferSize) {

  if (!buffer || BUFFER_SIZE_EMPTY == bufferSize) {
    return GMERROR_BUFFER_EMPTY;
  }
  size_t headerLength = 0;
  size_t bodyLength = 0;

  headerLength = snprintf(buffer, bufferSize, "%-8s | %-11s | %-11s\n",
                          "Pair No.", "Major Color", "Minor Color");

  // Remark: Not testable unless manipulated or the funtion snprintf fails
  // Note: Need to update code for better tests
  if (HEADER_LENGTH_EMPTY > headerLength) {
    return GMERROR_HEADER_EMPTY;
  }

  char *currentBufferPosition = buffer + headerLength;
  int index = 0;
  int totalPairs = (numberOfMinorColors * numberOfMajorColors);

  for (index = 0; index < totalPairs; index++) {
    bodyLength = snprintf(currentBufferPosition,
                          bufferSize - (currentBufferPosition - buffer),
                          "%8d | %11s | %11s\n", index + 1,
                          GetMajorColor(index / numberOfMajorColors),
                          GetMinorColor(index % numberOfMinorColors));

    if (BODY_LENGTH_EMPTY > bodyLength) {
      return GMERROR_BODY_EMPTY;
    }

    if (bufferSize - (currentBufferPosition - buffer) <= bodyLength) {
      return GMERROR_DATA_TRUNCATED;
    }

    currentBufferPosition += bodyLength;
  }

  return GMERROR_NULL;
}
