#pragma once

#include <stdint.h>

#if BUILD_AS_DLL
  #define GPROC_API		__declspec(dllexport)
#else
//  #define GPROC_API		__declspec(dllimport)
  #define GPROC_API
#endif

//#define GPROC_EXPORT		__declspec(dllexport)
#define GPROC_EXPORT

typedef struct RGBA_t {
    union {
        uint32_t intValue;
        uint8_t data[4];
        struct {uint8_t r, g, b, a;};
    };
} PixRGBA;

// Some well known types
typedef float	float32;
typedef double	float64;
typedef float32 REAL;
typedef float coord;

typedef uint32_t GRSIZE;
typedef uint16_t GRCOORD;

// Some useful routines
// returns the sign of the value
// value  < 0 --> -1
// value  > 0 -->  1
// value == 0 -->  0
// this will only work in cases where 0 represents false
// and 1 represents true
inline int sgn(REAL val) { return ((0 < val) - (val < 0)); }
