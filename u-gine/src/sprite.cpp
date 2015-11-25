#include "../include/sprite.h"
//#include "../include/rectcollision.h"
#include "../include/image.h"
//#include "../include/map.h"
#include "../include/math.h"
//#include "../include/pixelcollision.h"
#include "../include/renderer.h"
//#include "../include/circlecollision.h"
#include <math.h>

Sprite::Sprite(Image* image) {
	this->image = image;
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->angle = 0;
	this->scalex = 0;
	this->scaley = 0;
	this->colx = 0;
	this->coly = 0;
	this->colheight = 0;
	this->colwidth = 0;
	this->radius = 0;
	this->animFPS = 0;
	this->firstFrame = 0;
	this->lastFrame = 0;
	this->currentFrame = 0;
	this->blendMode = Renderer::SOLID;
	this->r = 255;
	this->g = 255;
	this->b = 255;
	this->a = 255;
	this->collision = nullptr;
	this->colPixelData = nullptr;
	this->colSprite = nullptr;
	this->collided = false;
	this->rotating = false;
	this->toAngle = 0;
	this->rotatingSpeed = 0;
	this->degreesToRotate = 0;
	this->moving = false;
	this->toX = 0;
	this->toY = 0;
	this->movingSpeedX = 0; this->movingSpeedY = 0;
	this->prevX = 0;
	this->prevY = 0;
	this->userData = nullptr;
}

Sprite::~Sprite() {
	// TAREA: Implementar
}

void Sprite::SetCollision(CollisionMode mode) {
	this->collision = nullptr;
}

bool Sprite::CheckCollision(Sprite* sprite) {
	return false;
	// TAREA: Implementar
}

bool Sprite::CheckCollision(const Map* map) {
	return false;
	// TAREA: Implementar
}

void Sprite::RotateTo(int32 angle, double speed) {
	this->toAngle = WrapValue(angle,360);
	this->rotating = true;
	/*if (angle > 180) {
		angle =angle-360;
	}*/
	if (angle - this->angle < this->angle - angle) {
		this->degreesToRotate = abs(angle - this->angle);
		this->rotatingSpeed = speed*-1;
	}
	else {
		this->degreesToRotate = abs(this->angle - angle);
		this->rotatingSpeed = speed;
	}
}

void Sprite::MoveTo(double x, double y, double speed) {
	int angle = Angle(this->x, this->y, x,y);
	this->toX = x;
	this->toY = y;
	this->moving = true;
	this->movingSpeedX = speed * DegCos(angle);
	this->movingSpeedY = speed * DegSin(angle)*-1;

}

void Sprite::Update(double elapsed, const Map* map) {
	// Informacion inicial de colision
	colSprite = NULL;
	collided = false;

	// TAREA: Actualizar animacion
	
	// TAREA: Actualizar rotacion animada
	if (this->rotating) {
		this->degreesToRotate-= abs(this->rotatingSpeed)*elapsed;
		this->angle += this->rotatingSpeed*elapsed;
		if (degreesToRotate <= 0) {
			this->angle = this->toAngle;
			this->rotating = false;
		}
	}

	// TAREA: Actualizar movimiento animado
	if (this->moving) {
		if (this->x - this->toX != 0) {
			this->x += this->movingSpeedX*elapsed;
		}
		if(this->y - this->toY != 0){
		this->y += this->movingSpeedY*elapsed;
		}
		if (this->x - this->toX ==0 && this->y-this->toY ==0 ) {
			this->moving = false;
		}
	}
	// Informacion final de colision
	UpdateCollisionBox();
}

void Sprite::Render() const {
	Renderer::Instance().SetBlendMode(this->blendMode);
	Renderer::Instance().SetColor(this->r, this->g, this->b, this->a);
	Renderer::Instance().DrawImage(this->image, this->x, this->y, this->currentFrame, this->image->GetWidth()*this->scalex, this->image->GetHeight()*this->scaley, this->angle);
}

void Sprite::UpdateCollisionBox() {
	// TAREA: Implementar
}

void Sprite::UpdateCollisionBox(double x, double y, double w, double h) {
	// TAREA: Implementar
}
