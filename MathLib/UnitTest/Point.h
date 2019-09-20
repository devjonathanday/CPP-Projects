#pragma once
#include"raylib.h"

class Point
{
public:
	Rectangle rec;
	bool grabbed;

	Point();
	Point(Rectangle _rec);
	~Point();
	bool CheckBounds();
};