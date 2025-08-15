#include "./test_manual_markdown.h"
#include <assert.h>

void testGenerateManualMarkdown(void) {
  char buffer[1500] = {0};
  GenerateManualErrorType_t result;
  result = generateManualTypeMarkdown(buffer, 1500, "./test/manual.md");
  printf("generateManualTypeMarkdown: %d\n", result);
  printf("%s", buffer);
  assert(result == GMERROR_NULL);
}
