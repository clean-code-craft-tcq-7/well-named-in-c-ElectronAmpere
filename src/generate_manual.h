#ifndef __GENERATE_MANUAL_H__
#define __GENERATE_MANUAL_H__

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

#define BUFFER_SIZE_EMPTY (0)
#define BUFFER_SIZE_MAX (1024)
#define HEADER_LENGTH_EMPTY (0)
#define BODY_LENGTH_EMPTY (0)

typedef enum {
  GPERROR_DATA_TRUNCATED = -4,
  GPERROR_BODY_EMPTY = -3,
  GPERROR_HEADER_EMPTY = -2,
  GPERROR_BUFFER_EMPTY = -1,
  GPERROR_NULL = 0,

} GeneratePrintErrorType_t;

GeneratePrintErrorType_t generateManualTypePrint(char *buffer,
                                                 size_t bufferSize);
int generateManualTypeMarkdown(const char *fileName);
int generateManualTypeCSV(const char *fileName);

#ifdef __cplusplus
}
#endif

#endif /* __GENERATE_MANUAL_H__ */
