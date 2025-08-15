#include "./test_manual_markdown.h"
#include <assert.h>

void testGenerateManualMarkdown(void) {
  char buffer[1500] = {0};
  GenerateManualErrorType_t result;
  result = generateManual(buffer, 1500, "./test/manual.md",
                          "| %-8s | %-11s | %-11s |\n"
                          "|----------|-------------|-------------|\n",
                          "| %8d | %11s | %11s |\n");
  printf("generateManual: %d\n", result);
  printf("%s", buffer);
  assert(result == GMERROR_NULL);
}

void testGenerateManualMarkdownBufferEmpty(void) {
  GenerateManualErrorType_t result;
  result = generateManual(NULL, BUFFER_SIZE_MAX, "./test/manual.md",
                          "| %-8s | %-11s | %-11s |\n"
                          "|----------|-------------|-------------|\n",
                          "| %8d | %11s | %11s |\n");
  printf("generateManualTypePrint: %d\n", result);
  assert(result == GMERROR_BUFFER_EMPTY);
}

void testGenerateManualMarkdownTruncation(void) {
  GenerateManualErrorType_t result;
  char buffer[100] = {0};
  result = generateManual(buffer, 100, "./test/manual.md",
                          "| %-8s | %-11s | %-11s |\n"
                          "|----------|-------------|-------------|\n",
                          "| %8d | %11s | %11s |\n");
  printf("generateManualTypePrint: %d\n", result);
  assert(result == GMERROR_DATA_TRUNCATED);
}
