#include "./test_manual_markdown.h"
#include "../src/generate_manual.h"
#include <assert.h>

#define TEST_MARKDOWN_FILE ("./test/manual.md")

void testGenerateManualMarkdown(void) {
  char buffer[1500] = {0};
  GenerateManualErrorType_t result;
  result = generateManual(buffer, 1500, TEST_MARKDOWN_FILE,
                          MANUAL_HEADER_FORMAT_MARKDOWN,
                          MANUAL_BODY_FORMAT_MARKDOWN);
  printf("testGenerateManualMarkdown: %d\n", result);
  printf("%s", buffer);
  assert(result == GMERROR_NULL);
}

void testGenerateManualMarkdownBufferEmpty(void) {
  GenerateManualErrorType_t result;
  result = generateManual(NULL, BUFFER_SIZE_MAX, TEST_MARKDOWN_FILE,
                          MANUAL_HEADER_FORMAT_MARKDOWN,
                          MANUAL_BODY_FORMAT_MARKDOWN);
  printf("testGenerateManualMarkdownBufferEmpty: %d\n", result);
  assert(result == GMERROR_BUFFER_EMPTY);
}

void testGenerateManualMarkdownTruncation(void) {
  GenerateManualErrorType_t result;
  char buffer[100] = {0};
  result = generateManual(buffer, 100, TEST_MARKDOWN_FILE,
                          MANUAL_HEADER_FORMAT_MARKDOWN,
                          MANUAL_BODY_FORMAT_MARKDOWN);
  printf("testGenerateManualMarkdownBufferEmpty: %d\n", result);
  assert(result == GMERROR_DATA_TRUNCATED);
}
