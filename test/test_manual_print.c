#include "./test_manual_print.h"
#include "../src/generate_manual.h"
#include <assert.h>

#define TEST_PRINT_FILE (NULL)

void testGenerateManualPrint(void) {
  char buffer[BUFFER_SIZE_MAX] = {0};
  GenerateManualErrorType_t result;
  result = generateManual(buffer, BUFFER_SIZE_MAX, TEST_PRINT_FILE,
                          MANUAL_HEADER_FORMAT_PRINT, MANUAL_BODY_FORMAT_PRINT);
  printf("testGenerateManualPrint: %d\n", result);
  printf("%s", buffer);
  assert(result == GMERROR_NULL);
}

void testGenerateManualPrintBufferEmpty(void) {
  GenerateManualErrorType_t result;
  result = generateManual(NULL, BUFFER_SIZE_MAX, TEST_PRINT_FILE,
                          MANUAL_HEADER_FORMAT_PRINT, MANUAL_BODY_FORMAT_PRINT);
  printf("testGenerateManualPrintBufferEmpty: %d\n", result);
  assert(result == GMERROR_BUFFER_EMPTY);
}

void testGenerateManualPrintTruncation(void) {
  GenerateManualErrorType_t result;
  char buffer[100] = {0};
  result = generateManual(buffer, 100, TEST_PRINT_FILE,
                          MANUAL_HEADER_FORMAT_PRINT, MANUAL_BODY_FORMAT_PRINT);
  printf("testGenerateManualPrintTruncation: %d\n", result);
  assert(result == GMERROR_DATA_TRUNCATED);
}
