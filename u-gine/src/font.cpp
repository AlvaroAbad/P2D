#include "../include/font.h"
#include "../include/image.h"
#include "../include/glinclude.h"
Font::Font(const String & filename) :Image(filename, 16, 16) {
	uint8 row, column;
	uint32 rowOffset = this->GetBufferWidth();
	uint32 beginX, beginY, endX, endY;
	this->glyphs = new Array<Glyph *>(16 * 16);
	uint32 * buffer = static_cast<uint32 *>(malloc(this->GetBufferWidth()*this->GetBufferHeight() * 4));
	glGetTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE, buffer);
	for (uint32 i = 0; i < 256; i++)
	{
		row = i / 16;
		row = row*rowOffset;
		column = i % 16;
		column = column * this->GetWidth();
		beginX = beginY = 0;
		endX = endY = 16;
		for (uint32 pixelRow = 0; pixelRow < this->GetHeight(); pixelRow++) {
			for (uint32 pixelColumn = 0; pixelColumn < this->GetWidth(); pixelColumn++) {
				switch (buffer[pixelRow*(row + column) + pixelColumn]) {
				case 0xFF000000:
					buffer[pixelRow*(row + column) + pixelColumn] = 0;
					break;
				case 0xFF00FFFF:
					buffer[pixelRow*(row + column) + pixelColumn] = 0;
					beginX = pixelRow;
					beginY = pixelColumn;
					break;
				case 0xFF0000FF:
					buffer[pixelRow*(row + column) + pixelColumn] = 0;
					endX = pixelRow;
					endY = pixelColumn;
					break;
				}
			}
		}
		this->glyphs->Add(new Glyph(beginX, beginY, endX - beginX, endY - beginY));
	}
	Renderer::Instance().setTexPixeles(reinterpret_cast<uint8 *>(buffer), this->GetBufferHeight(), this->GetBufferWidth());
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
	for (uint32 i = 0; i < text.Length(); i++) {
		Renderer::Instance().DrawImage(this, textPosition, y, chars[i], this->GetWidth(), this->GetHeight(), 0);
		textPosition += (*this->glyphs)[chars[i]]->getWidth();
	}
}
