#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_COLORPAIR_NAME_CHARS 16

enum MajorColor { WHITE, RED, BLACK, YELLOW, VIOLET };
enum MinorColor { BLUE, ORANGE, GREEN, BROWN, SLATE };

typedef struct {
  enum MajorColor majorColor;
  enum MinorColor minorColor;
} ColorPair;

extern const char *MajorColorNames[];
extern const char *MinorColorNames[];
extern int numberOfMajorColors;
extern int numberOfMinorColors;

ColorPair GetColorFromPairNumber(int pairNumber);
void ColorPairToString(const ColorPair *colorPair, char *buffer);
int GetPairNumberFromColor(const ColorPair *colorPair);

#ifdef __cplusplus
}
#endif
