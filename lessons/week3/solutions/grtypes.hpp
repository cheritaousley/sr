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

// Declaration of 2D Point structure
// This is convenient when representing multiple
// coordinates in an array in particular
struct Point2D {
    GRCOORD x, y;
    
    // Convenient constructor, but if you create this constructor,
    // you MUST then explicitly create a default constructor as well
    Point2D(GRCOORD ax, GRCOORD ay) : x(ax), y(ay) {}

    // default constructor
    Point2D() :x(0), y(0) {}


    Point2D operator + (const Point2D &b) {return Point2D{this->x + b.x, this->y + b.y};}
    Point2D operator - (const Point2D &b) {return Point2D{this->x - b.x, this->y - b.y};}
    Point2D operator - () {return Point2D(-x, -y);}
};



/*
// Find the vertex which has the smallest 'y' value, which puts it at
// the 'top' of the screen when the origin is 0,0 topleft.
inline int FindTopmostPolyVertex(const Point2D *poly, const size_t nelems)
{
    int ymin = INT32_MAX;
    int vmin = 0;

    size_t idx = 0;
    while (idx < nelems) {
      if (poly[idx].y < ymin) {
          ymin = poly[idx].y;
          vmin = idx;
      }
      idx++;
    }

    return vmin;
}
*/


/*
  GRTriangle

  A geometric triangle
*/
struct GRTriangle  {
    Point2D verts[3];   // A triangle has 3 vertices

    // Basic constructor take coordinates in any order, sorts them
    // so that subsequent drawing will be faster.
    GRTriangle(GRCOORD x1, GRCOORD y1,
      GRCOORD x2, GRCOORD y2,
      GRCOORD x3, GRCOORD y3)
    {

      verts[0] = {x1, y1};
      verts[1] = {x2, y2};
      verts[2] = {x3, y3};

      // sort the coordinates from topmost
      // to bottommost, so drawing is easier
      // This is essentially a 3 element bubble sort
      Point2D tmp;
      if (verts[0].y > verts[1].y) {
        tmp = verts[0];
        verts[0] = verts[1];
        verts[1] = tmp;
      }

      if (verts[1].y > verts[2].y) {
        tmp = verts[1];
        verts[1] = verts[2];
        verts[2] = tmp;
      }

      // One more round to ensure the second isn't the smallest
      if (verts[0].y > verts[1].y) {
        tmp = verts[0];
        verts[0] = verts[1];
        verts[1] = tmp;
      }
    }
} ;

// Some useful routines
// returns the sign of the value
// value  < 0 --> -1
// value  > 0 -->  1
// value == 0 -->  0
// this will only work in cases where 0 represents false
// and 1 represents true
inline int sgn(REAL val) { return ((0 < val) - (val < 0)); }
#define swap16(a, b) { int16_t t = a; a = b; b = t; }

