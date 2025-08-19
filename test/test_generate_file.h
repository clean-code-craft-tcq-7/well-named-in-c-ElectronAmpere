#ifndef __TEST_GENERATE_FILE_H__
#define __TEST_GENERATE_FILE_H__

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

#include "../src/generate_manual.h"

void testGenerateFileSuccess(void);
void testGenerateFileNullFileName(void);
void testGenerateFileOpenFailed(void);

#ifdef __cplusplus
}
#endif

#endif /* __TEST_GENERATE_FILE_H__ */
