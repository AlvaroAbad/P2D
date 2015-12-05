#ifndef UGINE_GLYPH_H
#define UGINE_GLYPH_H
#include "types.h"
class Glyph {
public:
	Glyph(uint32 offsetX, uint32 offsetY, uint32 width, uint32 height);
	uint32 setWidth(uint32 width) { this->width = width; }
	uint32 getWidth() { return this->width; }
	uint32 setHeight(uint32 height) { this->height = height; }
	uint32 getHeight() { return this->height; }
	uint32 setOffsetX(uint32 offsetX) { this->offsetX = offsetX; }
	uint32 getOffsetX() { return this->offsetX; }
	uint32 setOffsetY(uint32 offsetY) { this->offsetY = offsetY; }
	uint32 getOffsetY() { return this->offsetY; }
private:
	uint32 offsetX;
	uint32 offsetY;
	uint32 height;
	uint32 width;
};
#endif
