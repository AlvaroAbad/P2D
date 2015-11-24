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
	this->blendMode=Renderer::SOLID;
	this->r=255; 
	this->g = 255;
	this->b = 255;
	this->a = 255;
	this->collision=nullptr;
	this->colPixelData=nullptr;
	this->colSprite=nullptr;
	this->collided=false;
	this->rotating=false;
	this->toAngle=0;
	this->rotatingSpeed=0;
	this->degreesToRotate=0;
	this->moving=false;
	this->toX = 0;
	this->toY=0;
	this->movingSpeedX = 0; this->movingSpeedY=0;
	this->prevX = 0; 
	this->prevY = 0;
	this->userData=nullptr;
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
	// TAREA: Implementar
}

void Sprite::MoveTo(double x, double y, double speed) {
	// TAREA: Implementar
}

void Sprite::Update(double elapsed, const Map* map) {
	// Informacion inicial de colision
	colSprite = NULL;
	collided = false;

	// TAREA: Actualizar animacion

	// TAREA: Actualizar rotacion animada

	// TAREA: Actualizar movimiento animado

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
