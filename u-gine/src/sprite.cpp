#include "../include/sprite.h"
#include "../include/rectcollision.h"
#include "../include/image.h"
//#include "../include/map.h"
#include "../include/math.h"
#include "../include/pixelcollision.h"
#include "../include/renderer.h"
#include "../include/circlecollision.h"
#include <math.h>

Sprite::Sprite(Image* image) {
	this->image = image;
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->angle = 0;
	this->scalex = 1;
	this->scaley = 1;
	this->colx = 0;
	this->coly = 0;
	this->colheight = (this->image ? this->image->GetHeight() : 0);
	this->colwidth = (this->image ? this->image->GetWidth() : 0);
	this->radius = (this->image ? (this->image->GetHeight()>this->image->GetWidth()? this->image->GetHeight()/2: this->image->GetWidth()/2) : 0);;
	this->animFPS = 0;
	this->firstFrame = 0;
	this->lastFrame = (this->image? this->image->GetNumFrames():0);
	this->currentFrame = 0;
	this->blendMode = Renderer::ALPHA;
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
	this->movingSpeedX = 0;
	this->movingSpeedY = 0;
	this->prevX = 0;
	this->prevY = 0;
	this->userData = nullptr;
}

Sprite::~Sprite() {
	if (this->collision) {
		delete this->collision;
	}
}

void Sprite::SetCollision(CollisionMode mode) {
	if (this->collision) {
		delete this->collision;
	}
	switch (mode)
	{
	case Sprite::COLLISION_NONE:
		this->collision = nullptr;
		break;
	case Sprite::COLLISION_CIRCLE:
		this->collision = new CircleCollision(&this->colx, &this->coly, &this->radius);
		break;
	case Sprite::COLLISION_PIXEL:
		this->collision = new PixelCollision(this->image->GetFilename().StripExt()+"Col."+ this->image->GetFilename().ExtractExt(), &this->x, &this->y);
		break;
	case Sprite::COLLISION_RECT:
		this->collision = new RectCollision(&this->colx, &this->coly, &this->colwidth, &this->colheight);
		break;
	}
}

bool Sprite::CheckCollision(Sprite* sprite) {
	this->collided=this->collision->DoesCollide(sprite->GetCollision());
	if (this->collided) {
		this->colSprite = sprite;
		sprite->collided = true;
		sprite->colSprite = this;
	}
	return this->collided;
}

bool Sprite::CheckCollision(const Map* map) {
	return false;
	// TAREA: Implementar
}

void Sprite::RotateTo(int32 angle, double speed) {
	this->toAngle = WrapValue(angle, 360);
	if (this->toAngle == this->angle || !speed) {
		this->rotating = false;
	}
	else {
		this->rotating = true;
		double ccw = WrapValue(this->toAngle - this->angle, 360);
		double cw = WrapValue(this->angle - this->toAngle, 360);
		if (ccw < cw) {
			this->degreesToRotate = ccw;
			this->rotatingSpeed = fabs(speed);
		}
		else {
			this->degreesToRotate = cw;
			this->rotatingSpeed = -fabs(speed);
		}
	}
}

void Sprite::MoveTo(double x, double y, double speed) {
	if (!speed) {
		this->x = x;
		this->y = y;
	}
	else {
		int angle = Angle(this->x, this->y, x, y);
		this->toX = x;
		this->toY = y;
		this->moving = true;
		this->movingSpeedX = speed * DegCos(angle);
		this->movingSpeedY = speed * DegSin(angle)*-1;
	}

}

void Sprite::Update(double elapsed, const Map* map) {
	// Informacion inicial de colision
	colSprite = NULL;
	collided = false;

	//Actualizar animacion
	this->currentFrame += this->animFPS*elapsed;
	if (this->currentFrame > this->lastFrame) {
		this->currentFrame -= (this->lastFrame - this->firstFrame);
	}
	if (this->currentFrame < this->firstFrame) {
		this->currentFrame += (this->lastFrame - this->firstFrame);
	}
	//Actualizar angulo
	if (this->rotating) {
		this->degreesToRotate -= fabs(this->rotatingSpeed)*elapsed;
		this->angle += this->rotatingSpeed*elapsed;
		if (degreesToRotate <= 0) {
			this->angle = this->toAngle;
			this->rotating = false;
		}
	}
	//actualizar posicion
	if (this->moving) {
		if (this->x - this->toX != 0) {
			this->x += this->movingSpeedX*elapsed;
			if (this->movingSpeedX>0) {
				if (this->x > this->toX) {
					this->x = this->toX;
				}
			}
			else {
				if (this->x < this->toX) {
					this->x = this->toX;
				}
			}
		}

		if (this->y - this->toY != 0) {
			this->y += this->movingSpeedY*elapsed;
			if (this->movingSpeedY>0) {
				if (this->y > this->toY) {
					this->y = this->toY;
				}
			}
			else {
				if (this->y < this->toY) {
					this->y = this->toY;

				}
			}
		}

		if (this->x - this->toX == 0 && this->y - this->toY == 0) {
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
	this->colx = this->x-this->image->GetHandleX()*fabs(this->scalex);
	this->coly = this->y - this->image->GetHandleY()*fabs(this->scaley);
	this->colheight = this->image->GetHeight() * fabs(this->scaley);
	this->colwidth = this->image->GetWidth() * fabs(this->scalex);
}

void Sprite::UpdateCollisionBox(double x, double y, double w, double h) {
	this->colx = x;
	this->coly = y;
	this->colheight =h;
	this->colwidth = w;
}
