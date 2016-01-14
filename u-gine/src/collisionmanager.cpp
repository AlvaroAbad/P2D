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
	double overlapRectX, overlapRectY, overlapRectW, overlapRectH;
	double x, y;
	//check overlap
	if (RectsOverlap(cx, cy, cr*2, cr*2, px, py, pixels->GetWidth(), pixels->GetHeight())) {
		//get overlapingRect
		OverlappingRect(cx, cy, cr * 2, cr * 2, px, py, pixels->GetWidth(), pixels->GetHeight(), &overlapRectX, &overlapRectY, &overlapRectW, &overlapRectH);
		//reference coords
		x = overlapRectX;
		y = overlapRectY;

		//cicle through pixels
		while ((!pixels->GetData(x -px, y -py) || Distance(x, y, cx + cr, cy + cr) > cr) && ((x <overlapRectX + overlapRectW || y < overlapRectY + overlapRectH))) {
			if (x == overlapRectX + overlapRectW) {
				x = overlapRectX;
				y++;
			}
			else {
				x++;
			}
		}
		if (x < overlapRectX + overlapRectW || y < overlapRectY + overlapRectH) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
return false;
	}

	
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
	double controlX, constrolY, p1x, p1y, p2x, p2y;
	if(RectsOverlap(x1, y1, p1->GetWidth(), p1->GetHeight(), x2, y2, p2->GetWidth(), p2->GetHeight())){
	OverlappingRect(x1, y1, p1->GetWidth(), p1->GetHeight(), x2, y2, p2->GetWidth(), p2->GetHeight(), &overlapRectX, &overlapRectY, &overlapRectW, &overlapRectH);
	controlX = overlapRectX;
	constrolY = overlapRectY;
	p1x = overlapRectX- x1;
	p1y = overlapRectY- y1;
	p2x = overlapRectX - x2;
	p2y= overlapRectY - y2;
	while ((!p1->GetData(p1x, p1y) || !p2->GetData(p2x, p2y)) && (controlX <overlapRectX + overlapRectW || constrolY < overlapRectY + overlapRectH)) {
		if (controlX == overlapRectX + overlapRectW) {
			p1x = overlapRectX - x1;
			p2x = overlapRectX - x2;
			controlX = overlapRectX;
			p1y++;
			p2y++;
			constrolY++;
		}
		else {
			p1x++;
			p2x++;
			controlX++;
		}
	}
	if (controlX <= overlapRectX + overlapRectW || constrolY <= overlapRectY + overlapRectH) {
		return true;
	}
	else {
		return false;
	}
	}
	else {
		return false;
	}
}

bool CollisionManager::PixelsToRect(const CollisionPixelData * pixels, double px, double py, double rx, double ry, double rw, double rh) const
{
	double overlapRectX, overlapRectY, overlapRectW, overlapRectH,x,y;
	if (RectsOverlap(px, py, pixels->GetWidth(), pixels->GetHeight(), rx, ry, rw, rh)) {
		OverlappingRect(px, py, pixels->GetWidth(), pixels->GetHeight(), rx, ry, rw, rh, &overlapRectX, &overlapRectY, &overlapRectW, &overlapRectH);
		x = overlapRectX;
		y = overlapRectY;
		while (pixels->GetData(x - px, y - py) && (x-px<overlapRectW || y-py<overlapRectH)) {
			if (x == overlapRectX + overlapRectW) {
				x = overlapRectX;
				y++;
			}
			else {
				x++;
			}
		}
		if (x < overlapRectX + overlapRectW || y < overlapRectY + overlapRectH) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
return false;
	}
	
}

bool CollisionManager::RectToRect(double x1, double y1, double w1, double h1, double x2, double y2, double w2, double h2) const
{
	return RectsOverlap(x1, y1, w1, h1, x2, y2, w2, h2);
}
