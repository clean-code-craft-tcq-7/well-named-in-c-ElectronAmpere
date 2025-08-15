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

#define MANUAL_HEADER_FORMAT_PRINT ("%-8s | %-11s | %-11s\n")
#define MANUAL_BODY_FORMAT_PRINT ("%8d | %11s | %11s\n")

#define MANUAL_HEADER_FORMAT_MARKDOWN                                          \
  ("| %-8s | %-11s | %-11s |\n"                                                \
   "|----------|-------------|-------------|\n")
#define MANUAL_BODY_FORMAT_MARKDOWN ("| %8d | %11s | %11s |\n")

#define MANUAL_HEADER_FORMAT_CSV ("\"%s\",\"%s\",\"%s\"\n")
#define MANUAL_BODY_FORMAT_CSV ("%d,\"%s\",\"%s\"\n")

typedef enum {
  GMERROR_FILE_WRITE_FAILED = -7,
  GMERROR_FILE_OPEN_FAILED = -6,
  GMERROR_FILE_NONE = -5,
  GMERROR_DATA_TRUNCATED = -4,
  GMERROR_BODY_EMPTY = -3,
  GMERROR_HEADER_EMPTY = -2,
  GMERROR_BUFFER_EMPTY = -1,
  GMERROR_NULL = 0,
} GenerateManualErrorType_t;

GenerateManualErrorType_t generateFile(const char *fileName, char *buffer,
                                       size_t bufferSize);
GenerateManualErrorType_t generateManual(char *buffer, size_t bufferSize,
                                         const char *fileName,
                                         const char *headerFormat,
                                         const char *bodyFormat);
#ifdef __cplusplus
}
#endif

#endif /* __GENERATE_MANUAL_H__ */
