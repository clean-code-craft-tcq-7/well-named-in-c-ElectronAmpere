#include "./test_generate_file.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>

void testGenerateFileSuccess(void) {
  const char *fileName = "./test/test_file.txt";
  char buffer[] = "Hello, world!\n";
  size_t size = strlen(buffer);
  GenerateManualErrorType_t result = generateFile(fileName, buffer, size);
  printf("testGenerateFileSuccess: %d\n", result);
  assert(result == GMERROR_NULL);

  FILE *file = fopen(fileName, "r");
  assert(file != NULL);
  char *readBuffer = (char *)malloc(size + 1);
  size_t bytesRead = fread(readBuffer, 1, size, file);
  assert(bytesRead == size);
  readBuffer[bytesRead] = '\0';
  assert(strcmp(readBuffer, buffer) == 0);
  fclose(file);
  free(readBuffer);
  remove(fileName);
}

void testGenerateFileNullFileName(void) {
  char buffer[] = "test";
  GenerateManualErrorType_t result = generateFile(NULL, buffer, strlen(buffer));
  printf("testGenerateFileNullFileName: %d\n", result);
  assert(result == GMERROR_FILE_NONE);
}

void testGenerateFileOpenFailed(void) {
  char buffer[] = "test";
  GenerateManualErrorType_t result = generateFile("/", buffer, strlen(buffer));
  printf("testGenerateFileOpenFailed: %d\n", result);
  assert(result == GMERROR_FILE_OPEN_FAILED);
}
