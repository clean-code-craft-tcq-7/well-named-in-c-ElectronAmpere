#ifndef __TEST_MANUAL_PRINT_H__
#define __TEST_MANUAL_PRINT_H__

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

#include "../src/color_code_wire.h"
#include "../src/generate_manual.h"

void testGenerateManualPrint(void);
void testGenerateManualBufferEmpty(void);
void testGenerateManualHeaderEmpty(void);
void testGenerateManualBodyEmpty(void);
void testGenerateManualTruncation(void);

#ifdef __cplusplus
}
#endif

#endif /* __TEST_MANUAL_PRINT_H__ */
