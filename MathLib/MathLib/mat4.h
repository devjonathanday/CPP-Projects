#pragma once
#include"vec2.h"
#include"vec3.h"
#include"vec4.h"

//ROW-MAJOR!!

struct mat4
{
	union
	{
		struct
		{
			vec4 xAxis, yAxis, zAxis, wAxis;
		};
		vec4 axis[4];
		struct
		{
			float m1,  m2,  m3,  m4,
				  m5,  m6,  m7,  m8,
				  m9,  m10, m11, m12,
				  m13, m14, m15, m16;
		};
		struct { float m[16]; };
		struct { float mm[4][4]; };
	};

	mat4();
	mat4(float *ptr);
	mat4(float _m1,  float _m2,  float _m3,  float _m4,
		 float _m5,  float _m6,  float _m7,  float _m8,
		 float _m9, float _m10, float _m11, float _m12,
		 float _m13, float _m14, float _m15, float _m16 );
	operator float *();
	vec4 &operator[](const int index);
	mat4  operator*(const mat4 &rhs) const;
	mat4 &operator*=(const mat4 &rhs);
	bool operator==(const mat4 &rhs) const;
	bool operator!=(const mat4 &rhs) const;
	static mat4 identity();
	void set(float _m1,  float _m2,  float _m3,  float _m4,
			 float _m5,  float _m6,  float _m7,  float _m8,
			 float _m9,  float _m10, float _m11, float _m12,
			 float _m13, float _m14, float _m15, float _m16);
	void set(float *ptr);
	void transpose();
	mat4 getTranspose();
	static mat4 translation(float x, float y, float z);
	static mat4 translation(const vec3 &vec);
	static mat4 rotation(float rot, int axis);
	static mat4 scale(float xScale, float yScale, float zScale);
	vec4 operator*(const vec4 &rhs) const;
	vec3 operator*(const vec3 &rhs) const;
	mat4 setRotation(float rot, int axis);
};