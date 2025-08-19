#ifndef __TEST_MANUAL_MARKDOWN_H__
#define __TEST_MANUAL_MARKDOWN_H__

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

#include "../src/color_code_wire.h"
#include "../src/generate_manual.h"

void testGenerateManualMarkdown(void);
void testGenerateManualMarkdownBufferEmpty(void);
void testGenerateManualMarkdownTruncation(void);

#ifdef __cplusplus
}
#endif

#endif /* __TEST_MANUAL_MARKDOWN_H__ */
