#include"vec3.h"

vec3::vec3()
{
	x = 0;
	y = 0;
	z = 0;
}
vec3::vec3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}
float vec3::magnitude() const
{
	return sqrt((x * x) + (y * y) + (z * z));
}
float vec3::dot(const vec3 &rhs) const
{
	return (x * rhs.x) + (y * rhs.y) + (z * rhs.z);
}
vec3 vec3::cross(const vec3 &rhs) const
{
	return { y * rhs.z - z * rhs.y,
		   	 z * rhs.x - x * rhs.z,
			 x * rhs.y - y * rhs.x };
}
vec3 &vec3::normalize()
{
	return (*this) = getNormalized();
}
vec3 vec3::getNormalized() const
{
	return { x / magnitude(), y / magnitude(), z / magnitude() };
}
vec3 &vec3::scale(const vec3 &rhs)
{
	x *= rhs.x;
	y *= rhs.y;
	z *= rhs.z;
	return *this;
}
vec3 vec3::getScaled(const vec3 &rhs) const
{
	return { x * rhs.x, y * rhs.y, z * rhs.z };
}
vec3 vec3::operator+(const vec3 &rhs) const
{
	return { x + rhs.x, y + rhs.y, z + rhs.z };
}
vec3 vec3::operator-(const vec3 &rhs) const
{
	return { x - rhs.x, y - rhs.y, z - rhs.z };
}
vec3 vec3::operator*(const float rhs) const
{
	return { x * rhs, y * rhs, z * rhs };
}
vec3 vec3::operator/(const float rhs) const
{
	return { x / rhs, y / rhs, z / rhs };
}
vec3 &vec3::operator+=(const vec3 &rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	return *this;
}
vec3 &vec3::operator-=(const vec3 &rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	return *this;
}
vec3 & vec3::operator*=(const float rhs)
{
	return (*this = { x * rhs, y * rhs, z * rhs });
}
vec3 & vec3::operator/=(const float rhs)
{
	return (*this = { x / rhs, y / rhs, z / rhs });
}
bool vec3::operator==(const vec3 &rhs) const
{
	vec3 dif = *this - rhs;
	return abs(dif.x) < (FLT_EPSILON * 1000) && abs(dif.y) < (FLT_EPSILON * 1000) && abs(dif.z) < (FLT_EPSILON * 1000);
}
bool vec3::operator!=(const vec3 &rhs) const
{
	return !(*this == rhs);
}
vec3 vec3::operator-() const
{
	return { -x, -y, -z };
}
vec3::operator float *()
{
	return &x;
}
vec3::operator const float *() const
{
	return &x;
}
vec3 operator*(const float lhs, const vec3 &rhs)
{
	return { rhs.x * lhs, rhs.y * lhs, rhs.z * lhs };
}