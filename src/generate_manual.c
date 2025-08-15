#include "./generate_manual.h"
#include "./color_code_wire.h"
#include <stdio.h>

GenerateManualErrorType_t generateManual(char *buffer, size_t bufferSize,
                                         const char *fileName,
                                         const char *headerFormat,
                                         const char *bodyFormat) {
  if (!buffer || BUFFER_SIZE_EMPTY == bufferSize) {
    return GMERROR_BUFFER_EMPTY;
  }

  size_t headerLength = 0;
  size_t bodyLength = 0;
  char *currentBufferPosition = buffer;

  // Remark: Not testable unless manipulated or the funtion snprintf fails
  // Note: Need to update code for better tests
  headerLength = snprintf(currentBufferPosition, bufferSize, headerFormat,
                          "Pair No.", "Major Color", "Minor Color");
  if (headerLength <= HEADER_LENGTH_EMPTY || headerLength >= bufferSize) {
    return GMERROR_HEADER_EMPTY;
  }
  currentBufferPosition += headerLength;

  // Generate body rows
  int totalPairs = numberOfMajorColors * numberOfMinorColors; // 25 pairs
  for (int index = 0; index < totalPairs; ++index) {
    int majorIndex = index / numberOfMajorColors;
    int minorIndex = index % numberOfMinorColors;
    bodyLength = snprintf(currentBufferPosition,
                          bufferSize - (currentBufferPosition - buffer),
                          bodyFormat, index + 1, GetMajorColor(majorIndex),
                          GetMinorColor(minorIndex));
    if (bodyLength <= BODY_LENGTH_EMPTY) {
      return GMERROR_BODY_EMPTY;
    }
    if (bufferSize - (currentBufferPosition - buffer) <= bodyLength) {
      return GMERROR_DATA_TRUNCATED;
    }
    currentBufferPosition += bodyLength;
  }

  GenerateManualErrorType_t result =
      generateFile(fileName, buffer, (currentBufferPosition - buffer));
  if (result != GMERROR_NULL && result != GMERROR_FILE_NONE) {
    return result;
  }

  return GMERROR_NULL; // Success indicator as per the original
}
