#include"vec2.h"

vec2::vec2()
{
	x = 0;
	y = 0;
}
vec2::vec2(float _x, float _y)
{
	x = _x;
	y = _y;
}
float vec2::magnitude() const
{
	return sqrt((x * x) + (y * y));
}
float vec2::dot(const vec2 &rhs) const
{
	return (x * rhs.x) + (y * rhs.y);
}
vec2 &vec2::normalize()
{
	return (*this) = getNormalized();
}
vec2 vec2::getNormalized() const
{
	return { x / magnitude(), y / magnitude() };
}
vec2 &vec2::scale(const vec2 &rhs)
{
	x *= rhs.x;
	y *= rhs.y;
	return *this;
}
vec2 vec2::getScaled(const vec2 &rhs) const
{
	return { x * rhs.x, y * rhs.y };
}
vec2 vec2::getPerpCW() const
{
	return { y, -x };
}
vec2 vec2::getPerpCCW() const
{
	return { -y, x };
}
float vec2::angleBetween(const vec2 &rhs) const
{
	return _RAD_TO_DEG * acos(dot(rhs) / (magnitude() * rhs.magnitude()));
}
vec2 vec2::operator+(const vec2 &rhs) const
{
	return { x + rhs.x, y + rhs.y };
}
vec2 vec2::operator-(const vec2 &rhs) const
{
	return { x - rhs.x, y - rhs.y };
}
vec2 vec2::operator*(const float rhs) const
{
	return { x * rhs, y * rhs };
}
vec2 vec2::operator/(const float rhs) const
{
	return { x / rhs, y / rhs };
}
vec2 &vec2::operator+=(const vec2 &rhs)
{
	x += rhs.x;
	y += rhs.y;
	return *this;
}
vec2 &vec2::operator-=(const vec2 &rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	return *this;
}
vec2 & vec2::operator*=(const float rhs)
{
	return (*this = { x * rhs, y * rhs });
}
vec2 & vec2::operator/=(const float rhs)
{
	return (*this = {x / rhs, y / rhs});
}
bool vec2::operator==(const vec2 &rhs) const
{
	vec2 dif = *this - rhs;
	return abs(dif.x) < (FLT_EPSILON * 1000) && abs(dif.y) < (FLT_EPSILON * 1000);
}
bool vec2::operator!=(const vec2 &rhs) const
{
	return !(*this == rhs);
}
vec2 vec2::operator-() const
{
	return { -x, -y };
}
vec2::operator float *()
{
	return &x;
}
vec2::operator const float *() const
{
	return &x;
}
bool vec2::near(const vec2 &rhs, float variance)
{
	vec2 dif = *this - rhs;
	return abs(dif.x) < variance && abs(dif.y) < variance;
}
vec2 operator*(const float lhs, const vec2 &rhs)
{
	return { rhs.x * lhs, rhs.y * lhs };
}