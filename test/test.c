#include <assert.h>
#include <stdio.h>

#include "./test_manual_csv.h"
#include "./test_manual_markdown.h"
#include "./test_manual_print.h"
#include "./test_pairing.h"

int main() {
  testNumberToPair(4, WHITE, BROWN);
  testNumberToPair(5, WHITE, SLATE);

  testPairToNumber(BLACK, ORANGE, 12);
  testPairToNumber(VIOLET, SLATE, 25);

  testGenerateManualPrint();
  testGenerateManualPrintBufferEmpty();
  testGenerateManualPrintTruncation();

  testGenerateManualMarkdown();
  testGenerateManualMarkdownBufferEmpty();
  testGenerateManualMarkdownTruncation();

  testGenerateManualCSV();
  testGenerateManualCSVBufferEmpty();
  testGenerateManualCSVTruncation();

  return 0;
}
