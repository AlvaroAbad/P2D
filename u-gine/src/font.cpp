#include "../include/font.h"
#include "../include/image.h"
Font::Font(const String & filename) :Image(filename, 16, 16) {

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
