#include "PixelBufferGray.hpp"
#include "DrawingContext.hpp"
#include "colors.hpp"
#include "pbm.hpp"

void main()
{
    PixelBufferGray fb(640, 640);
    DrawingContext dc(fb);

    dc.setBackground(colors.white);
    dc.clear();

    // default black stroke
    dc.setStroke(colors.gray50);
    for (int row = 0; row < 639; row += 3)
    {
        dc.strokeHorizontalLine(0, row, row);
    }

    PBM::writePPMBinary("testdcgray.ppm", fb);
}
