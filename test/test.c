#include <assert.h>
#include <stdio.h>

#include "./test_color_names.h"
#include "./test_generate_file.h"
#include "./test_manual_csv.h"
#include "./test_manual_markdown.h"
#include "./test_manual_print.h"
#include "./test_pairing.h"

int main() {
  testNumberToPair(4, WHITE, BROWN);
  testNumberToPair(5, WHITE, SLATE);

  testPairToNumber(BLACK, ORANGE, 12);
  testPairToNumber(VIOLET, SLATE, 25);

  testNumberToPairInvalidLow();
  testNumberToPairInvalidHigh();
  testPairToNumberInvalidMajor();

  testGetMajorColor(0, "White");
  testGetMajorColor(1, "Red");
  testGetMajorColor(2, "Black");
  testGetMajorColor(3, "Yellow");
  testGetMajorColor(4, "Violet");
  testGetMajorColor(-1, "Unknown");
  testGetMajorColor(5, "Invalid");

  testGetMinorColor(0, "Blue");
  testGetMinorColor(1, "Orange");
  testGetMinorColor(2, "Green");
  testGetMinorColor(3, "Brown");
  testGetMinorColor(4, "Slate");
  testGetMinorColor(-1, "Unknown");
  testGetMinorColor(5, "Invalid");

  testGenerateManualPrint();
  testGenerateManualPrintBufferEmpty();
  testGenerateManualPrintTruncation();

  testGenerateManualMarkdown();
  testGenerateManualMarkdownBufferEmpty();
  testGenerateManualMarkdownTruncation();

  testGenerateManualCSV();
  testGenerateManualCSVBufferEmpty();
  testGenerateManualCSVTruncation();

  testGenerateFileSuccess();
  testGenerateFileNullFileName();
  testGenerateFileOpenFailed();

  return 0;
}
