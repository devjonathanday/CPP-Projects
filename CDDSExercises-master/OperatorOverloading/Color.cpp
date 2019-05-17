#pragma once
#include"raylib.h"
#include"Color.h"

MyColor::MyColor()
{

}
MyColor::MyColor(int red, int green, int blue, int alpha)
{
	r = red;
	g = green;
	b = blue;
	a = alpha;
}
MyColor MyColor::operator+(const MyColor &rhs) const
{
	MyColor color = *this;
	color.r += rhs.r;
	color.g += rhs.g;
	color.b += rhs.b;
	color.a += rhs.a;
	return color;
}
MyColor MyColor::operator-(const MyColor &rhs) const
{
	MyColor color = *this;
	color.r -= rhs.r;
	color.g -= rhs.g;
	color.b -= rhs.b;
	color.a -= rhs.a;
	return color;
}
MyColor MyColor::operator*(const MyColor &rhs) const
{
	MyColor color = *this;
	color.r *= rhs.r;
	color.g *= rhs.g;
	color.b *= rhs.b;
	color.a *= rhs.a;
	return color;
}
MyColor MyColor::operator/(const MyColor &rhs) const
{
	MyColor color = *this;
	color.r /= rhs.r;
	color.g /= rhs.g;
	color.b /= rhs.b;
	color.a /= rhs.a;
	return color;
}
MyColor& MyColor::operator+=(const MyColor &rhs)
{
	(*this) = (*this) + rhs;
	return (*this);
}
MyColor& MyColor::operator-=(const MyColor &rhs)
{
	(*this) = (*this) - rhs;
	return (*this);
}
MyColor& MyColor::operator*=(const MyColor &rhs)
{
	(*this) = (*this) * rhs;
	return (*this);
}
MyColor& MyColor::operator/=(const MyColor &rhs)
{
	(*this) = (*this) / rhs;
	return (*this);
}

bool MyColor::operator==(const MyColor &rhs) const
{
	return ((*this).r == rhs.r && (*this).g == rhs.g && (*this).b == rhs.b && (*this).a == rhs.a);
}
bool MyColor::operator!=(const MyColor &rhs) const
{
	return ((*this).r != rhs.r && (*this).g != rhs.g && (*this).b != rhs.b && (*this).a != rhs.a);
}

MyColor MyColor::operator!() const //Not color? idk
{
	MyColor newColor;
	newColor.r = -((*this).r);
	newColor.g = -((*this).g);
	newColor.b = -((*this).b);
	newColor.a = -((*this).a);
	return newColor;
}

Color MyColor::GetRealColor(MyColor color)
{
	Color newColor;
	newColor.r = color.r;
	newColor.g = color.g;
	newColor.b = color.b;
	newColor.a = color.a;
	return newColor;
}