#ifndef UGINE_GLYPH_H
#define UGINE_GLYPH_H
#include "types.h"
class Glyph {
public:
	Glyph(uint32 height, uint32 width);
	uint32 seWidth(uint32 width) { this->width = width; }
	uint32 geWidth() { return this->width; }
	uint32 seHeight(uint32 height) { this->height = height; }
	uint32 geHeight() { return this->height; }
private:
	uint32 height;
	uint32 width;
};
#endif
