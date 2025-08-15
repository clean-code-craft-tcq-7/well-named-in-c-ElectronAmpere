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
  GMERROR_FILE_WRITE_FAILED = -6,
  GMERROR_FILE_OPEN_FAILED = -5,
  GMERROR_DATA_TRUNCATED = -4,
  GMERROR_BODY_EMPTY = -3,
  GMERROR_HEADER_EMPTY = -2,
  GMERROR_BUFFER_EMPTY = -1,
  GMERROR_NULL = 0,
} GenerateManualErrorType_t;

GenerateManualErrorType_t generateManualTypePrint(char *buffer,
                                                  size_t bufferSize);
GenerateManualErrorType_t generateManualTypeMarkdown(char *buffer,
                                                     size_t bufferSize,
                                                     const char *fileName);
GenerateManualErrorType_t generateManualTypeCSV(char *buffer, size_t bufferSize,
                                                const char *fileName);

#ifdef __cplusplus
}
#endif

#endif /* __GENERATE_MANUAL_H__ */
