#include "./color_code_wire.h"
#include "./generate_manual.h"
#include <stdio.h>

GenerateManualErrorType_t generateManualTypeMarkdown(char *buffer,
                                                     size_t bufferSize,
                                                     const char *fileName) {
  if (!buffer || BUFFER_SIZE_EMPTY == bufferSize) {
    return GMERROR_BUFFER_EMPTY;
  }

  size_t headerLength = 0;
  size_t bodyLength = 0;
  char *currentBufferPosition = buffer;

  // Generate header with proper Markdown table formatting
  headerLength = snprintf(currentBufferPosition, bufferSize,
                          "| %-8s | %-11s | %-11s |\n"
                          "|----------|-------------|-------------|\n",
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
                          "| %8d | %11s | %11s |\n", index + 1,
                          GetMajorColor(majorIndex), GetMinorColor(minorIndex));
    if (bodyLength <= BODY_LENGTH_EMPTY) {
      return GMERROR_BODY_EMPTY;
    }
    if (bufferSize - (currentBufferPosition - buffer) <= bodyLength) {
      return GMERROR_DATA_TRUNCATED;
    }
    currentBufferPosition += bodyLength;
  }

  // Write buffer to file
  FILE *file = fopen(fileName, "w");
  if (!file) {
    return GMERROR_FILE_OPEN_FAILED;
  }
  size_t bytesWritten = fwrite(buffer, 1, currentBufferPosition - buffer, file);
  if (bytesWritten != (size_t)(currentBufferPosition - buffer)) {
    fclose(file);
    return GMERROR_FILE_WRITE_FAILED;
  }
  fclose(file);

  return GMERROR_NULL; // Success indicator as per the original
}
