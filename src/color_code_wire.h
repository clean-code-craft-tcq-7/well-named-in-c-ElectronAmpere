#ifndef __COLOR_CODE_WIRE_H__
#define __COLOR_CODE_WIRE_H__

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

const char *GetMajorColor(int index);
const char *GetMinorColor(int index);
ColorPair_t GetColorFromPairNumber(int pairNumber);
int GetPairNumberFromColor(const ColorPair_t *colorPair);

#ifdef __cplusplus
}
#endif

#endif /* __COLOR_CODE_WIRE_H__ */
