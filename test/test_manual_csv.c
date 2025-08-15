#include "./test_manual_csv.h"
#include "../src/generate_manual.h"
#include <assert.h>

#define TEST_CSV_FILE ("./test/manual.csv")

void testGenerateManualCSV(void) {
  char buffer[BUFFER_SIZE_MAX] = {0};
  GenerateManualErrorType_t result;
  result = generateManual(buffer, BUFFER_SIZE_MAX, TEST_CSV_FILE,
                          MANUAL_HEADER_FORMAT_CSV, MANUAL_BODY_FORMAT_CSV);
  printf("testGenerateManualCSV: %d\n", result);
  printf("%s", buffer);
  assert(result == GMERROR_NULL);
}

void testGenerateManualCSVBufferEmpty(void) {
  GenerateManualErrorType_t result;
  result = generateManual(NULL, BUFFER_SIZE_MAX, TEST_CSV_FILE,
                          MANUAL_HEADER_FORMAT_CSV, MANUAL_BODY_FORMAT_CSV);
  printf("testGenerateManualCSVBufferEmpty: %d\n", result);
  assert(result == GMERROR_BUFFER_EMPTY);
}

void testGenerateManualCSVTruncation(void) {
  GenerateManualErrorType_t result;
  char buffer[100] = {0};
  result = generateManual(buffer, 100, TEST_CSV_FILE, MANUAL_HEADER_FORMAT_CSV,
                          MANUAL_BODY_FORMAT_CSV);
  printf("testGenerateManualCSVTruncation: %d\n", result);
  assert(result == GMERROR_DATA_TRUNCATED);
}
