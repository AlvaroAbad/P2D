#ifndef UGINE_PARTICLE_H
#define UGINE_PARTICLE_H
#include "sprite.h"
#include "affector.h"
class Particle: public Sprite{
public:
	Particle();
	Particle(Image* image, double velx, double vely, double angularVel,	double lifetime,bool autofade);
	virtual double GetLifetime()const { return this->lifetime; };
	virtual void Update(double elapsed);
	virtual bool isAffectable() { return posibleAffectors > affectedBy.Size();	}
	virtual void affect(Affector affector);
private:
	double velocityx,velocityy;
	double angularVelocity;
	double lifetime;
	double initialLifetime;
	bool autofade;
	uint32 posibleAffectors;
	Array<uint32> affectedBy;
};

#endif