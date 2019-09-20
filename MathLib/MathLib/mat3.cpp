#include"mat3.h"

mat3::mat3()
{
	m1 = 0; m2 = 0; m3 = 0;
	m4 = 0; m5 = 0; m6 = 0;
	m7 = 0; m8 = 0; m9 = 0;
};
mat3::mat3(float *ptr)
{
	if (ptr != nullptr)
	{
		m1 = ptr[0]; m2 = ptr[1]; m3 = ptr[2];
		m4 = ptr[3]; m5 = ptr[4]; m6 = ptr[5];
		m7 = ptr[6]; m8 = ptr[7]; m9 = ptr[8];
	}
}
mat3::mat3(float _m1, float _m2, float _m3,
		   float _m4, float _m5, float _m6,
		   float _m7, float _m8, float _m9)
{
	m1 = _m1; m2 = _m2; m3 = _m3;
	m4 = _m4; m5 = _m5; m6 = _m6;
	m7 = _m7; m8 = _m8; m9 = _m9;
}
mat3::operator float *()
{
	float *ptr = m;
	return ptr;
}
vec3 &mat3::operator[](const int index)
{
	return axis[index];
}
mat3 mat3::operator*(const mat3 & rhs) const
{
	mat3 newMat3;
	for (int i = 0; i < 3; i++) //Iterate through this.rows
		for (int j = 0; j < 3; j++) //Iterate through rhs.columns
			for (int k = 0; k < 3; k++) //Iterate through this.columns/rhs.rows
				newMat3.mm[i][j] += mm[i][k] * rhs.mm[k][j];
	return newMat3;
}
mat3 & mat3::operator*=(const mat3 & rhs)
{
	return *this = (*this * rhs);
}
bool mat3::operator==(const mat3 & rhs) const
{
	for (int i = 0; i < 9; i++)
		if (m[i] - rhs.m[i] > FLT_EPSILON * 1000)
			return false;
	return true;
}
bool mat3::operator!=(const mat3 & rhs) const
{
	return !(*this == rhs);
}
mat3 mat3::identity()
{
	return mat3(1, 0, 0,
				0, 1, 0,
				0, 0, 1);
}
void mat3::set(float _m1, float _m2, float _m3,
			   float _m4, float _m5, float _m6,
			   float _m7, float _m8, float _m9)
{
	m1 = _m1; m2 = _m2; m3 = _m3;
	m4 = _m4; m5 = _m5; m6 = _m6;
	m7 = _m7; m8 = _m8; m9 = _m9;
}
void mat3::set(float *ptr)
{
	if (ptr != nullptr)
	{
		m1 = ptr[0]; m2 = ptr[1]; m3 = ptr[2];
		m4 = ptr[3]; m5 = ptr[4]; m6 = ptr[5];
		m7 = ptr[6]; m8 = ptr[7]; m9 = ptr[8];
	}
}
void mat3::transpose()
{
	set(getTranspose());
}
mat3 mat3::getTranspose()
{
	mat3 newMat3;
	for (int i = 0; i < 3; i++) //Iterate through this.rows
		for (int j = 0; j < 3; j++) //Iterate through rhs.columns
			newMat3.mm[j][i] = mm[i][j];
	return newMat3;
}
mat3 mat3::translation(float x, float y)
{
	return mat3(1, 0, x,
				0, 1, y,
				0, 0, 1);
}
mat3 mat3::translation(const vec2 &vec)
{
	return translation(vec.x, vec.y);
}
mat3 mat3::rotation(float rot)
{
	return mat3(cos(rot),   -sin(rot), 0,
				sin(rot),  cos(rot), 0,
				0,		    0,		  1);
}
mat3 mat3::scale(float xScale, float yScale)
{
	return mat3(xScale, 0,		0,
				0,		yScale, 0,
				0,		0,		1);
}
vec3 mat3::operator*(const vec3 &rhs) const
{
	vec3 newVec;
	for (int i = 0; i < 3; i++) //Iterate through this.rows
		for (int j = 0; j < 3; j++) //Iterate through rhs.columns
			newVec[i] += mm[i][j] * rhs[j];
	return newVec;
}
vec2 mat3::operator*(const vec2 &rhs) const
{
	vec2 newVec;
	for (int i = 0; i < 2; i++) //Iterate through this.rows
		for (int j = 0; j < 2; j++) //Iterate through rhs.columns
			newVec[i] += mm[i][j] * rhs[j];
	return newVec;
}
mat3 mat3::setRotation(float rot, int axis)
{
	switch (axis)
	{
	case 0: //Rotate about X axis
		return (*this = mat3(1,		0,		 0,
							 0,		cos(rot), -sin(rot),
							 0,		sin(rot), cos(rot)));
		break;
	case 1: //Rotate about Y axis
		return (*this = mat3(cos(rot),  0, sin(rot),
							 0,		    1, 0, 
							 -sin(rot), 0, cos(rot)));
		break;
	case 2: //Rotate about Z axis
		return (*this = mat3(cos(rot), -sin(rot), 0,
							 sin(rot), cos(rot),  0,
							 0,		   0,		  1));
		break;
	}
	return identity();
}
void mat3::print()
{
	std::cout << "{ " << m1 << ", "<< m2 << ", " << m3 << " }" << std::endl;
	std::cout << "{ " << m4 << ", " << m5 << ", " << m6 << " }" << std::endl;
	std::cout << "{ " << m7 << ", " << m8 << ", " << m9 << " }" << std::endl;
}