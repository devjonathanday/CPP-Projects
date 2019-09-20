#include"mat4.h"

mat4::mat4()
{
	m1 = 0;  m2 = 0;  m3 = 0;  m4 = 0;
	m5 = 0;  m6 = 0;  m7 = 0;  m8 = 0;
	m9 = 0;  m10 = 0; m11 = 0; m12 = 0;
	m13 = 0; m14 = 0; m15 = 0; m16 = 0;
};
mat4::mat4(float *ptr)
{
	if (ptr != nullptr)
	{
		m1 = ptr[0];   m2 = ptr[1];   m3 = ptr[2];   m4 = ptr[3];
		m5 = ptr[4];   m6 = ptr[5];   m7 = ptr[6];   m8 = ptr[7];
		m9 = ptr[8];   m10 = ptr[9];  m11 = ptr[10]; m12 = ptr[11];
		m13 = ptr[12]; m14 = ptr[13]; m15 = ptr[14]; m16 = ptr[15];
	}
}
mat4::mat4(float _m1,  float _m2,  float _m3,  float _m4,
		   float _m5,  float _m6,  float _m7,  float _m8,
		   float _m9,  float _m10, float _m11, float _m12,
		   float _m13, float _m14, float _m15, float _m16)
{
	m1 = _m1;   m2 = _m2;   m3 = _m3;   m4 = _m4;
	m5 = _m5;   m6 = _m6;   m7 = _m7;   m8 = _m8;
	m9 = _m9;   m10 = _m10; m11 = _m11; m12 = _m12;
	m13 = _m13; m14 = _m14; m15 = _m15; m16 = _m16;
}
mat4::operator float *()
{
	float *ptr = m;
	return ptr;
}
vec4 &mat4::operator[](const int index)
{
	return axis[index];
}
mat4 mat4::operator*(const mat4 & rhs) const
{
	mat4 newMat4;
	for (int i = 0; i < 4; i++) //Iterate through this.rows
		for (int j = 0; j < 4; j++) //Iterate through rhs.columns
			for (int k = 0; k < 4; k++) //Iterate through this.columns/rhs.rows
				newMat4.mm[i][j] += mm[i][k] * rhs.mm[k][j];
	return newMat4;
}
mat4 & mat4::operator*=(const mat4 & rhs)
{
	return *this = (*this * rhs);
}
bool mat4::operator==(const mat4 & rhs) const
{
	for (int i = 0; i < 16; i++)
		if (m[i] - rhs.m[i] > FLT_EPSILON * 1000)
			return false;
	return true;
}
bool mat4::operator!=(const mat4 & rhs) const
{
	return !(*this == rhs);
}
mat4 mat4::identity()
{
	return mat4(1, 0, 0, 0,
				0, 1, 0, 0,
				0, 0, 1, 0,
				0, 0, 0, 1);
}
void mat4::set(float _m1,  float _m2,  float _m3,  float _m4,
			   float _m5,  float _m6,  float _m7,  float _m8,
			   float _m9,  float _m10, float _m11, float _m12,
			   float _m13, float _m14, float _m15, float _m16)
{
	m1 = _m1;   m2 = _m2;   m3 = _m3;   m4 = _m4;
	m5 = _m5;   m6 = _m6;   m7 = _m7;   m8 = _m8;
	m9 = _m9;   m10 = _m10; m11 = _m11; m12 = _m12;
	m13 = _m13; m14 = _m14; m15 = _m15; m16 = _m16;
}
void mat4::set(float *ptr)
{
	if (ptr != nullptr)
	{
		m1 = ptr[0];   m2 = ptr[1];   m3 = ptr[2];   m4 = ptr[3];
		m5 = ptr[4];   m6 = ptr[5];   m7 = ptr[6];   m8 = ptr[7];
		m9 = ptr[8];   m10 = ptr[9];  m11 = ptr[10]; m12 = ptr[11];
		m13 = ptr[12]; m14 = ptr[13]; m15 = ptr[14]; m16 = ptr[15];
	}
}
void mat4::transpose()
{
	set(getTranspose());
}
mat4 mat4::getTranspose()
{
	mat4 newMat4;
	for (int i = 0; i < 4; i++) //Iterate through this.rows
		for (int j = 0; j < 4; j++) //Iterate through rhs.columns
			newMat4.mm[j][i] = mm[i][j];
	return newMat4;
}
mat4 mat4::translation(float x, float y, float z)
{
	return mat4(1, 0, 0, x,
				0, 1, 0, y,
				0, 0, 1, z,
				0, 0, 0, 1);
}
mat4 mat4::translation(const vec3 &vec)
{
	return translation(vec.x, vec.y, vec.z);
}
mat4 mat4::rotation(float rot, int axis)
{
	switch (axis)
	{
	case 0: //Rotate about X axis
		return mat4(1, 0,		 0,			0,
					0, cos(rot), -sin(rot), 0,
					0, sin(rot), cos(rot),  0,
					0, 0,		 0,		    1);
		break;
	case 1: //Rotate about Y axis
		return mat4(cos(rot),  0, sin(rot), 0,
					0,		   1, 0,	    0,
					-sin(rot), 0, cos(rot), 0,
					0,		   0, 1,		0);
		break;
	case 2: //Rotate about Z axis
		return mat4(cos(rot), -sin(rot), 0, 0,
					sin(rot), cos(rot),  0, 0,
					0,		  0,		 1, 0,
					0,		  0,		 0, 1);

		break;
	}
	return identity();
}
mat4 mat4::scale(float xScale, float yScale, float zScale)
{
	return mat4(xScale, 0,		0,		0,
				0,		yScale, 0,		0,
				0,		0,		zScale, 0,
				0,		0,		0,		1);
}
vec4 mat4::operator*(const vec4 &rhs) const
{
	vec4 newVec;
	for (int i = 0; i < 4; i++) //Iterate through this.rows
		for (int j = 0; j < 4; j++) //Iterate through rhs.columns
			newVec[i] += mm[i][j] * rhs[j];
	return newVec;
}
vec3 mat4::operator*(const vec3 &rhs) const
{
	vec3 newVec;
	for (int i = 0; i < 3; i++) //Iterate through this.rows
		for (int j = 0; j < 3; j++) //Iterate through rhs.columns
			newVec[i] += mm[i][j] * rhs[j];
	return newVec;
}
mat4 mat4::setRotation(float rot, int axis)
{
	switch (axis)
	{
	case 0: //Rotate about X axis
		return (*this = mat4(1,  m2,		m3,		  m4,
							 m5, cos(rot),  sin(rot), m8,
							 m9, -sin(rot), cos(rot), m12, 
							 m13, m14,		m15,	  1));
		break;
	case 1: //Rotate about Y axis
		return (*this = mat4(cos(rot), m2, -sin(rot), m4,
							 m5,	   1,   m7,		  m8,
							 sin(rot), m10, cos(rot), m12,
							 m13,	   m14, m15,	  1));
		break;
	case 2: //Rotate about Z axis
		return (*this = mat4(cos(rot),  -sin(rot), m3,  m4,
							 sin(rot), cos(rot), m7,  m8,
							 m9,		m10,	  1,   m12, 
							 m13,		m14,	  m15, 1));
		break;
	}
	return identity();
}