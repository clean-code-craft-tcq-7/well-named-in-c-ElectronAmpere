#ifndef __TEST_MANUAL_CSV_H__
#define __TEST_MANUAL_CSV_H__

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

#include "../src/color_code_wire.h"
#include "../src/generate_manual.h"

void testGenerateManualCSV(void);
void testGenerateManualCSVBufferEmpty(void);
void testGenerateManualCSVTruncation(void);

#ifdef __cplusplus
}
#endif

#endif /* __TEST_MANUAL_CSV_H__ */
