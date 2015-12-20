#include "../include/particle.h"
Particle::Particle(): Sprite(nullptr)
{
}
Particle::Particle(Image * image, double velx, double vely, double angularVel, double lifetime, bool autofade, uint32 posibleAffectors): Sprite(image)
{
	this->velocityx = velx;
	this->velocityy = vely;
	this->angularVelocity = angularVel;
	this->initialLifetime = lifetime;
	this->lifetime = lifetime;
	this->autofade = autofade;
	this->posibleAffectors = posibleAffectors;
}
void Particle::Update(double elapsed)
{

	double posX = this->GetX();
	double posY = this->GetY();
	double angle = this->GetAngle();

	posX += this->velocityx*elapsed;
	posY += this->velocityy*elapsed;
	angle += this->angularVelocity*elapsed;

	this->SetPosition(posX, posY);
	this->SetAngle(angle);

	if (this->autofade) {
		double alpha = this->GetAlpha();
		double alphaDecrement=255/ this->initialLifetime;
		alphaDecrement = alphaDecrement*elapsed;
		if (alpha - alphaDecrement > 0) {
			alpha -= alphaDecrement*elapsed;
		}
		else {
			alpha = 0;
		}
		this->SetColor(this->GetRed(), this->GetGreen(), this->GetBlue(), alpha);
	}
	this->lifetime -= elapsed;
	if (this->lifetime<=0) {
		this->SetColor(0, 0,0, 0);
	}
}
bool Particle::hasbeenAffectedBy(String * id)
{
	uint32 numAffector = 0;
	if (affectedBy.Size() == 0) {
		return false;
	}
	while (affectedBy.Size()>numAffector && affectedBy[numAffector] != *id) {
		numAffector++;
	}
	if (affectedBy.Size() == numAffector) {
		return false;
	}
	return true;
}