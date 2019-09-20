#pragma once
#include"utils.h"
#include<cfloat>
#include<cmath>

struct vec4
{
public:
	float x, y, z, w;

	vec4();
	vec4(float _x, float _y, float _z, float _w);

	float magnitude() const;
	float dot(const vec4 &rhs) const;
	vec4 cross(const vec4 &rhs) const;

	vec4 &normalize();
	vec4 getNormalized() const;

	vec4 &scale(const vec4 &rhs);
	vec4 getScaled(const vec4 &rhs) const;

	vec4 operator+(const vec4 &rhs) const;
	vec4 operator-(const vec4 &rhs) const;
	vec4 operator*(const float rhs) const;
	friend vec4 operator*(const float lhs, const vec4 &rhs);
	vec4 operator/(const float rhs) const;

	vec4 &operator+=(const vec4 &rhs);
	vec4 &operator-=(const vec4 &rhs);
	vec4 &operator*=(const float rhs);
	vec4 &operator/=(const float rhs);

	bool operator==(const vec4 &rhs) const;
	bool operator!=(const vec4 &rhs) const;

	vec4 operator-() const;

	operator float *();
	operator const float *() const;
};

vec4 operator*(const float lhs, const vec4 &rhs);