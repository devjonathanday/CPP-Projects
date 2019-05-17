#pragma once
#include"raylib.h"

class MyColor
{
public:
	MyColor();
	MyColor(int red, int green, int blue, int alpha);

	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a = 255;

	MyColor operator+(const MyColor &rhs) const;
	MyColor operator-(const MyColor &rhs) const;
	MyColor operator*(const MyColor &rhs) const;
	MyColor operator/(const MyColor &rhs) const;

	MyColor& operator+=(const MyColor &rhs);
	MyColor& operator-=(const MyColor &rhs);
	MyColor& operator*=(const MyColor &rhs);
	MyColor& operator/=(const MyColor &rhs);

	bool operator==(const MyColor &rhs) const;
	bool operator!=(const MyColor &rhs) const;

	MyColor operator!() const;

	Color GetRealColor(MyColor color);
};