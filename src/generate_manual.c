#include "./generate_manual.h"
#include "./color_code_wire.h"
#include <stdio.h>

GeneratePrintErrorType_t generateManualTypePrint(char *buffer,
                                                 size_t bufferSize) {

  GeneratePrintErrorType_t resultError = GPERROR_NULL;
  if (!buffer || BUFFER_SIZE_EMPTY == bufferSize) {
    resultError = GPERROR_BUFFER_EMPTY;
    return resultError;
  }

  size_t headerLength = 0;
  size_t bodyLength = 0;

  // Initialize buffer with header
  headerLength = snprintf(buffer, bufferSize, "%-8s | %-11s | %-11s\n",
                          "Pair No.", "Major Color", "Minor Color");

  if (HEADER_LENGTH_EMPTY > headerLength) {
    resultError = GPERROR_HEADER_EMPTY;
    return resultError;
  }
  char *currentBufferPosition = buffer + headerLength;
  for (int index = 0; index < (numberOfMinorColors * numberOfMajorColors);
       index++) {
    bodyLength = snprintf(currentBufferPosition,
                          bufferSize - (currentBufferPosition - buffer),
                          "%8d | %11s | %11s\n", index + 1,
                          GetMajorColor(index / numberOfMajorColors),
                          GetMinorColor(index % numberOfMinorColors));

    if (BODY_LENGTH_EMPTY > bodyLength) {
      resultError = GPERROR_BODY_EMPTY;
      return resultError;
    }

    if (bufferSize - (currentBufferPosition - buffer) <= bodyLength) {
      resultError = GPERROR_DATA_TRUNCATED;
      break;
    }
    currentBufferPosition += bodyLength;
  }

  return resultError;
}

int generateManualTypeMarkdown(const char *fileName) { return 0; }

int generateManualTypeCSV(const char *fileName) { return 0; }
