#include "../include/font.h"
#include "../include/image.h"
Font::Font(const String & filename) :Image(filename, 16, 16) {
	uint32 buffer;
	uint16 width, height;
	width = height=0;
	for (uint32 row = 0; row < this->GetHeight() * 4; row += (16 * 4)) {
		for (uint32 column = 0; column < this->GetWidth() * 4; column += (16 * 4)) {
			for (uint32 i = 0; i < 16 * 4; i+=2049) {
				for (uint32 j = 0; j < 16 * 4; j++) {
					buffer[row+i]
				}
			}
		}
	}
	
}
uint16 Font::GetSize() const{
	return this->GetHeight();
}

uint32 Font::GetTextWidth(const String & text) const{
	return text.Length()*this->GetWidth();
}

uint32 Font::GetTextHeight(const String & text) const{
	return this->GetHeight();
}

void Font::Render(const String & text, double x, double y) const{
	const char * chars = text.ToCString();
	for (uint32 i = 0; i < text.Length(); i++)
	{
		Renderer::Instance().DrawImage(this, x + (16 * i), y, chars[i], this->GetWidth(), this->GetHeight(), 0);
	}
}
