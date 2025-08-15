#include "./test_manual_print.h"
#include <assert.h>

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
