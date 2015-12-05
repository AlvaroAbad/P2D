#include "../include/font.h"
#include "../include/image.h"
#include "../include/glinclude.h"
Font::Font(const String & filename) :Image(filename, 16, 16) {
	uint32 row, column;
	uint32 rowOffset = this->GetBufferWidth();
	uint32 beginX, beginY, endX, endY;
	this->glyphs = new Array<Glyph *>(16 * 16);
	uint32 * buffer = static_cast<uint32 *>(malloc(this->GetBufferWidth()*this->GetBufferHeight() * 4));
	glGetTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE, buffer);
	for (uint32 i = 0; i < 256; i++)
	{
		row = i / 16;
		row = row*(this->GetHeight()*rowOffset);
		column = i % 16;
		column = column * this->GetWidth();
		beginX = beginY = 0;
		endX = endY = this->GetWidth();
		for (uint32 pixelRow = 0; pixelRow <this->GetHeight(); pixelRow++) {
			for (uint32 pixelColumn = 0; pixelColumn <this->GetWidth(); pixelColumn++) {
				switch (buffer[row+ column+(pixelRow*rowOffset) + pixelColumn]) {
				case 0xFF000000:
					buffer[row + column + (pixelRow*rowOffset) + pixelColumn] &= 0x00000000;
					break;
				case 0xFF00FFFF:
					buffer[row + column + (pixelRow*rowOffset) + pixelColumn] &= 0x00000000;
					beginY = pixelRow;
					beginX = pixelColumn;
					break;
				case 0xFF0000FF:
					buffer[row + column + (pixelRow*rowOffset) + pixelColumn] &= 0x00000000;
					endY = pixelRow;
					endX = pixelColumn;
					break;
				}
			}
		}
		this->glyphs->Add(new Glyph(beginX, beginY%this->GetHeight(), endX - beginX, endY - beginY));
	}
	Renderer::Instance().setTexPixeles(reinterpret_cast<uint8 *>(buffer),this->GetTexId(), this->GetBufferHeight(), this->GetBufferWidth());
	free(buffer);
}

uint16 Font::GetSize() const {
	return this->GetHeight();
}

uint32 Font::GetTextWidth(const String & text) const {
	uint32 textSize = 0;
	const char * chars = text.ToCString();
	for (uint32 i = 0; i < text.Length(); i++) {
		textSize += (*this->glyphs)[chars[i]]->getWidth();
	}
	return textSize;
}

uint32 Font::GetTextHeight(const String & text) const {
	return this->GetHeight();
}

void Font::Render(const String & text, double x, double y) const {
	const char * chars = text.ToCString();
	uint32 textPosition = x;
	uint32 width;
	for (uint32 i = 0; i < text.Length(); i++) {
		Renderer::Instance().DrawImage(this, textPosition, y, chars[i], this->GetWidth(), this->GetHeight(), 0);
		uint32 width = (*this->glyphs)[chars[i]]->getWidth();
		textPosition += (*this->glyphs)[chars[i]]->getWidth();
	}
}
