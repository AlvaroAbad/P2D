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

bool CollisionManager::CircleToPixels(double cx, double cy, double cr, const CollisionPixelData * pixels, double px, double py) const
{

	return false;
}

bool CollisionManager::CircleToRect(double cx, double cy, double cr, double rx, double ry, double rw, double rh) const
{
	double closestX, closestY;
	ClosestPointToRect(cx + cr, cy + cr, rx, ry, rw, rh, &closestX, &closestY);
	if (Distance(cx + cr, cy + cr, closestX, closestY) <= cr) {
		return true;
	}
	else {
		return false;
	}
}

bool CollisionManager::PixelsToPixels(const CollisionPixelData * p1, double x1, double y1, const CollisionPixelData * p2, double x2, double y2) const
{
	double overlapRectX, overlapRectY, overlapRectW, overlapRectH;
	OverlappingRect(x1, y1, p1->GetWidth(), p1->GetHeight(), x2, y2, p2->GetWidth(), p2->GetHeight(), overlapRectX, overlapRectY, overlapRectW, overlapRectH);
	return false;
}

bool CollisionManager::PixelsToRect(const CollisionPixelData * pixels, double px, double py, double rx, double ry, double rw, double rh) const
{
	return false;
}

bool CollisionManager::RectToRect(double x1, double y1, double w1, double h1, double x2, double y2, double w2, double h2) const
{
	return RectsOverlap(x1, y1, w1, h1, x2, y2, w2, h2);
}
