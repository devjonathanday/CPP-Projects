#include"vec4.h"

vec4::vec4()
{
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}
vec4::vec4(float _x, float _y, float _z, float _w)
{
	x = _x;
	y = _y;
	z = _z;
	w = _w;
}
float vec4::magnitude() const
{
	return sqrt((x * x) + (y * y) + (z * z) + (w * w));
}
float vec4::dot(const vec4 &rhs) const
{
	return (x * rhs.x) + (y * rhs.y) + (z * rhs.z) + (w * rhs.w);
}
vec4 vec4::cross(const vec4 & rhs) const
{
	return { y*rhs.z - z * rhs.y,
			 z*rhs.x - x * rhs.z,
			 x*rhs.y - y * rhs.x, 0 };
}
vec4 &vec4::normalize()
{
	return (*this) = getNormalized();
}
vec4 vec4::getNormalized() const
{
	return { x / magnitude(), y / magnitude(), z / magnitude(), w / magnitude() };
}
vec4 &vec4::scale(const vec4 &rhs)
{
	x *= rhs.x;
	y *= rhs.y;
	z *= rhs.z;
	w *= rhs.w;
	return *this;
}
vec4 vec4::getScaled(const vec4 &rhs) const
{
	return { x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w };
}
vec4 vec4::operator+(const vec4 &rhs) const
{
	return { x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w };
}
vec4 vec4::operator-(const vec4 &rhs) const
{
	return { x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w };
}
vec4 vec4::operator*(const float rhs) const
{
	return { x * rhs, y * rhs, z * rhs, w * rhs };
}
vec4 vec4::operator/(const float rhs) const
{
	return { x / rhs, y / rhs, z / rhs, w / rhs };
}
vec4 &vec4::operator+=(const vec4 &rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	w += rhs.w;
	return *this;
}
vec4 &vec4::operator-=(const vec4 &rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	w -= rhs.w;
	return *this;
}
vec4 & vec4::operator*=(const float rhs)
{
	return (*this = { x * rhs, y * rhs, z * rhs, w * rhs });
}
vec4 & vec4::operator/=(const float rhs)
{
	return (*this = { x / rhs, y / rhs, z / rhs, w / rhs });
}
bool vec4::operator==(const vec4 &rhs) const
{
	vec4 dif = *this - rhs;
	return abs(dif.x) < (FLT_EPSILON * 1000) &&
		abs(dif.y) < (FLT_EPSILON * 1000) &&
		abs(dif.z) < (FLT_EPSILON * 1000) &&
		abs(dif.w) < (FLT_EPSILON * 1000);
}
bool vec4::operator!=(const vec4 &rhs) const
{
	return !(*this == rhs);
}
vec4 vec4::operator-() const
{
	return { -x, -y, -z, -w };
}
vec4::operator float *()
{
	return &x;
}
vec4::operator const float *() const
{
	return &x;
}
vec4 operator*(const float lhs, const vec4 &rhs)
{
	return { rhs.x * lhs, rhs.y * lhs, rhs.z * lhs, rhs.w * lhs };
}