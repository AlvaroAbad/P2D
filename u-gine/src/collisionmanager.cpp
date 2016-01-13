#include "..\include\collisionmanager.h"
#include "..\include\math.h"
CollisionManager* CollisionManager::manager = nullptr;
CollisionManager & CollisionManager::Instance()
{
	if (!manager) {
		manager=new CollisionManager();
	}
	return *manager;
}

bool CollisionManager::CircleToCircle(double x1, double y1, double r1, double x2, double y2, double r2) const
{
	double centerX1, centerY1, centerX2, centerY2;
	centerX1 = x1 + r1;
	centerY1 = y1 + r1;
	centerX2 = x2 + r2;
	centerY2 = y2 + r2;
	double distC;
	distC=Distance(centerX1, centerY1, centerX2, centerY2);
	if (r1 + r2 >= distC) {
		return true;
	}
	else {
		return false;
	}
}

bool CollisionManager::CircleToRect(double cx, double cy, double cr, double rx, double ry, double rw, double rh) const
{
	double cCenterX, cCenterY;
	cCenterX = cx + cr;
	cCenterY = cy + cr;
	double dist1, dist2, dist3, dist4;
	dist1 = Distance(cCenterX, cCenterY, rx, ry);
	dist2 = Distance(cCenterX, cCenterY, rx+rw, ry);
	dist3 = Distance(cCenterX, cCenterY, rx, ry+rh);
	dist4 = Distance(cCenterX, cCenterY, rx+rw, ry+rh);
	if (cr >= dist1 || cr >= dist2 || cr >= dist3 || cr >= dist4) {
		return true;
	}
	else {

		return RectsOverlap(cx,cy,cr*2,cr*2,rx,ry,rw,rh);
	}
}

bool CollisionManager::RectToRect(double x1, double y1, double w1, double h1, double x2, double y2, double w2, double h2) const
{
	return RectsOverlap(x1, y1, w1, h1, x2, y2, w2, h2);
}
