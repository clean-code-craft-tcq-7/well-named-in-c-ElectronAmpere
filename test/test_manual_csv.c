#include "./test_manual_csv.h"
#include <assert.h>

void testGenerateManualCSV(void) {
  char buffer[BUFFER_SIZE_MAX] = {0};
  GenerateManualErrorType_t result;
  result = generateManual(buffer, BUFFER_SIZE_MAX, "./test/manual.csv",
                          "\"%s\",\"%s\",\"%s\"\n", "%d,\"%s\",\"%s\"\n");
  printf("generateManual: %d\n", result);
  printf("%s", buffer);
  assert(result == GMERROR_NULL);
}

void testGenerateManualCSVBufferEmpty(void) {
  GenerateManualErrorType_t result;
  result = generateManual(NULL, BUFFER_SIZE_MAX, "./test/manual.csv",
                          "\"%s\",\"%s\",\"%s\"\n", "%d,\"%s\",\"%s\"\n");
  printf("generateManualTypePrint: %d\n", result);
  assert(result == GMERROR_BUFFER_EMPTY);
}

void testGenerateManualCSVHeaderEmpty(void) {
  // Remark: Not testable unless manipulated or the funtion snprintf fails
  // Note: Need to update implementation for better tests
  GenerateManualErrorType_t result;
  char buffer[30] = {0};
  result = generateManual(buffer, 30, "./test/manual.csv",
                          "\"%s\",\"%s\",\"%s\"\n", "%d,\"%s\",\"%s\"\n");
  printf("generateManualTypePrint: %d\n", result);
  assert(result == GMERROR_HEADER_EMPTY);
}

void testGenerateManualCSVBodyEmpty(void) {
  // Remark: Not testable unless manipulated or the funtion snprintf fails
  // Note: Need to update implementation for better tests
  GenerateManualErrorType_t result;
  char buffer[100] = {0};
  result = generateManual(buffer, 100, "./test/manual.csv",
                          "\"%s\",\"%s\",\"%s\"\n", "%d,\"%s\",\"%s\"\n");
  printf("generateManualTypePrint: %d\n", result);
  assert(result == GMERROR_BODY_EMPTY);
}

void testGenerateManualCSVTruncation(void) {
  GenerateManualErrorType_t result;
  char buffer[100] = {0};
  result = generateManual(buffer, 100, "./test/manual.csv",
                          "\"%s\",\"%s\",\"%s\"\n", "%d,\"%s\",\"%s\"\n");
  printf("generateManualTypePrint: %d\n", result);
  assert(result == GMERROR_DATA_TRUNCATED);
}
