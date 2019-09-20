#pragma once
#include"utils.h"
#include<cfloat>
#include<cmath>
#include<iostream>

struct vec2
{
#ifdef RAYLIB_H
	//operator Vector2();
	vec2(Vector2 vec)
	{
		x = vec.x;
		y = vec.y;
	}
	vec2& operator=(const Vector2 &rhs)
	{
		x = rhs.x;
		y = rhs.y;
		return *this;
	}
	operator Vector2()
	{
		return { x , y };
	}
#endif

	float x, y;

	vec2();
	vec2(float x, float y);

	float magnitude() const;
	float dot(const vec2 &rhs) const;

	vec2 &normalize();
	vec2 getNormalized() const;

	vec2 &scale(const vec2 &rhs);
	vec2 getScaled(const vec2 &rhs) const;

	vec2 getPerpCW() const;
	vec2 getPerpCCW() const;

	float angleBetween(const vec2 &rhs) const;

	vec2 operator+(const vec2 &rhs) const;
	vec2 operator-(const vec2 &rhs) const;
	vec2 operator*(const float rhs) const;
	friend vec2 operator*(const float lhs, const vec2 &rhs);
	vec2 operator/(const float rhs) const;

	vec2 &operator+=(const vec2 &rhs);
	vec2 &operator-=(const vec2 &rhs);
	vec2 &operator*=(const float rhs);
	vec2 &operator/=(const float rhs);

	bool operator==(const vec2 &rhs) const;
	bool operator!=(const vec2 &rhs) const;

	vec2 operator-() const;

	operator float *();
	operator const float *() const;

	bool near(const vec2 &rhs, float variance);
};

vec2 operator*(const float lhs, const vec2 &rhs);