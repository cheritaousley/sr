#pragma once

#include <stdint.h>

#include "PixelBuffer.hpp"

class PixelBufferGray : public PixelBuffer
{
public:
    PixelBufferGray(GRSIZE width, GRSIZE height)
        : PixelBuffer(width, height)
    {
        data = {new PixRGBA[width * height]{}};
    }
    // Virtual destructor so this can be sub-classed
    virtual ~PixelBufferGray()
    {
        // must delete the data element, as we
        // constructred it.
        delete[] data;
    }

    // Set the value of a single pixel
    bool setPixel(GRCOORD x, GRCOORD y, const PixRGBA pix)
    {
        if (x >= getWidth() || y >= getHeight())
        {
            return false; // outside bounds
        }
        size_t offset = y * getWidth() + x;
        data[offset] = pix;

        return true;
    }

    PixRGBA getPixel(GRCOORD x, GRCOORD y) const
    {
        size_t offset = y * getWidth() + x;
        return this->data[offset];
    }

    bool setSpan(GRCOORD x, GRCOORD y, const GRSIZE width, const PixRGBA *pix)
    {

        size_t offset = y * getWidth() + x;

        for (GRSIZE i = 0; i < width; i++)
        {
            data[offset + i] = pix[i];
        }

        return true;
    }

    bool setAllPixels(const PixRGBA value)
    {
        size_t nPixels = getWidth() * getHeight();
        while (nPixels > 0)
        {
            data[nPixels - 1] = value;
            nPixels = nPixels - 1;
        }

        return true;
    }

private:
    PixelBufferGray();

    PixRGBA *data;
};