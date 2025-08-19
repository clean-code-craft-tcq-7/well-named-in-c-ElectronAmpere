#include "./generate_manual.h"
#include <stdio.h>

GenerateManualErrorType_t generateFile(const char *fileName, char *buffer,
                                       size_t bufferSize) {

  // Write buffer to file
  if (!fileName) {
    return GMERROR_FILE_NONE;
  }
  FILE *file = fopen(fileName, "w");
  if (!file) {
    return GMERROR_FILE_OPEN_FAILED;
  }
  size_t bytesWritten = fwrite(buffer, 1, bufferSize, file);
  if (bytesWritten != (size_t)bufferSize) {
    fclose(file);
    return GMERROR_FILE_WRITE_FAILED;
  }
  fclose(file);
  return GMERROR_NULL;
}
