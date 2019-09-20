#include"Point.h"

bool Point::CheckBounds()
{
	Vector2 mousePos = GetMousePosition();
	return (mousePos.x > rec.x && mousePos.y > rec.y &&
		mousePos.x < rec.x + rec.width &&
		mousePos.y < rec.y + rec.height);
}
Point::Point() {};
Point::Point(Rectangle _rec) { rec = _rec; grabbed = false; };
Point::~Point() {};