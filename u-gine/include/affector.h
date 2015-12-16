#ifndef UGINE_AFFECTOR_H
#define UGINE_AFFECTOR_H
#include "types.h"
class Affector {
public:
	Affector(){}
	Affector(uint32 id,double bound0X, double bound0Y, double bound1X, double bound1Y);
	virtual void setSpeed(double velocityX, double velocityY) {
		this->velocityX = velocityX;
		this->velocityY = velocityY;
	}
	virtual double getVelocityX() { return this->velocityX; }
	virtual double getVelocityY() { return this->velocityY; }
	virtual void setAngularVelocity(double angularVelocity) { this->angularVelocity = angularVelocity; }
	virtual double getAngularVelocity() { return this->angularVelocity; }
	virtual void setLifeTime(double lifeTime) { this->lifetime = lifeTime; }
	virtual double getLifeTime() { return this->lifetime; }
	virtual void setAutoFade(bool autofade) { this->autofade = autofade; }
	virtual bool getAutofade() { return this->autofade; }
private:
	uint32 id;
	double bound0X, bound0Y, bound1X, bound1Y;
	double velocityX, velocityY;
	double angularVelocity;
	double lifetime;
	bool autofade;
};
#endif
