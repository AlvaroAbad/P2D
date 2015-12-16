#include "..\include\affector.h"

Affector::Affector(uint32 id,double bound0X, double bound0Y, double bound1X, double bound1Y)
{
	this->id = id;
	this->bound0X = bound0X;
	this->bound0Y = bound0Y;
	this->bound1X = bound1X;
	this->bound1Y = bound1Y;
}
