#pragma once
#include"vec2.h"
#include"vec3.h"

//ROW-MAJOR!!

struct mat3
{
	union
	{
		struct
		{ vec3 xAxis, yAxis, zAxis; };
		vec3 axis[3];
		struct
		{
			float m1, m2, m3,
				m4, m5, m6,
				m7, m8, m9;
		};
		struct { float m[9]; };
		struct { float mm[3][3]; };
	};

	mat3();
	mat3(float *ptr);
	mat3(float _m1, float _m2, float _m3,
		 float _m4, float _m5, float _m6,
		 float _m7, float _m8, float _m9);
	operator float *();
	vec3 &operator[](const int index);
	mat3 operator*(const mat3 &rhs) const;
	mat3 &operator*=(const mat3 &rhs);
	bool operator==(const mat3 &rhs) const;
	bool operator!=(const mat3 &rhs) const;
	static mat3 identity();
	void set(float _m1, float _m2, float _m3,
			 float _m4, float _m5, float _m6,
			 float _m7, float _m8, float _m9);
	void set(float *ptr);
	void transpose();
	mat3 getTranspose();
	static mat3 translation(float x, float y);
	static mat3 translation(const vec2 &vec);
	static mat3 rotation(float rot);
	static mat3 scale(float xScale, float yScale);
	vec3 operator*(const vec3 &rhs) const;
	vec2 operator*(const vec2 &rhs) const;
	mat3 setRotation(float rot, int axis);
	void print();
};