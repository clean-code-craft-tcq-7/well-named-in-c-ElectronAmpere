#include "./test_manual_csv.h"
#include <assert.h>

void testGenerateManualCSV(void) {
  char buffer[BUFFER_SIZE_MAX] = {0};
  GenerateManualErrorType_t result;
  result = generateManualTypeCSV(buffer, BUFFER_SIZE_MAX, "./test/manual.csv");
  printf("generateManualTypeCSV: %d\n", result);
  printf("%s", buffer);
  assert(result == GMERROR_NULL);
}
