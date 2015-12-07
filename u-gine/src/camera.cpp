#include "../include/camera.h"

Camera::Camera(){
	this->x = 0;
	this->y = 0;
	this->boundx0 = 0;
	this->boundy0 = 0;
	this->boundx1 = 0;
	this->boundy1 = 0;
	this->followingSprite = nullptr;
}

void Camera::Update()
{
	int nextX, nextY;
	nextX= nextY=0;
	if (this->followingSprite) {
		
		nextX = (this->followingSprite->GetScreenX() - this->x) - Screen::Instance().GetWidth() / 2;
		nextY = (this->followingSprite->GetScreenY() - this->y)- Screen::Instance().GetHeight() / 2;
		if (this->x+nextX >= this->boundx0 && this->x + nextX <= this->boundx1 - Screen::Instance().GetWidth()) {
			this->x += nextX;
		}
		if (this->y+nextY >= this->boundy0 && this->y + nextY <= this->boundy1 - Screen::Instance().GetHeight()) {
			this->y += nextY;
		}
	}
	
}
