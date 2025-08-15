#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_COLORPAIR_NAME_CHARS 16

typedef enum { WHITE, RED, BLACK, YELLOW, VIOLET } MajorColor_t;
typedef enum { BLUE, ORANGE, GREEN, BROWN, SLATE } MinorColor_t;

typedef struct {
  MajorColor_t majorColor;
  MinorColor_t minorColor;
} ColorPair_t;

extern const char *MajorColorNames[];
extern const char *MinorColorNames[];
extern int numberOfMajorColors;
extern int numberOfMinorColors;

ColorPair_t GetColorFromPairNumber(int pairNumber);
void ColorPairToString(const ColorPair_t *colorPair, char *buffer);
int GetPairNumberFromColor(const ColorPair_t *colorPair);

#ifdef __cplusplus
}
#endif
