#include"transform3d.h"

vec3 transform3d::localPosition() const
{
	return { trsMatrix.m1, trsMatrix.m2, trsMatrix.m3 };
}
vec3 transform3d::localRotation() const
{
	return { trsMatrix.m5, trsMatrix.m6, trsMatrix.m7 };
}
vec3 transform3d::localScale() const
{
	return { trsMatrix.m9, trsMatrix.m10, trsMatrix.m11 };
}
void transform3d::setLocalPosition(const vec3 &newPos)
{
	trsMatrix.m1 = newPos.x;
	trsMatrix.m2 = newPos.y;
	trsMatrix.m3 = newPos.z;
}
void transform3d::setLocalRotation(const vec3 &newRot)
{
	trsMatrix.m5 = newRot.x;
	trsMatrix.m6 = newRot.y;
	trsMatrix.m7 = newRot.z;
}
void transform3d::setLocalScale(const vec3 &newScale)
{
	trsMatrix.m9 = newScale.x;
	trsMatrix.m10 = newScale.y;
	trsMatrix.m11 = newScale.z;
}
vec3 transform3d::forward() const
{
	return vec3(0, 0, 1);
}
void transform3d::setForward(const vec3 &newForward)
{
	setLocalRotation(newForward);
}
vec3 transform3d::right() const
{
	return vec3(1, 0, 0);
}
void transform3d::setRight(const vec3 &newRight)
{
	setLocalRotation(newRight);
}
vec3 transform3d::up() const
{
	return vec3(0, 1, 0);
}
void transform3d::setUp(const vec3 &newUp)
{
	setLocalRotation(newUp);
}
void transform3d::translate(const vec3& offset)
{
	trsMatrix.set(trsMatrix.translation(offset));
}
void transform3d::rotate(const vec3 &rot)
{
	trsMatrix.set(trsMatrix.rotation(rot.x, 0));
	trsMatrix.set(trsMatrix.rotation(rot.y, 1));
	trsMatrix.set(trsMatrix.rotation(rot.z, 2));
}
void transform3d::lookAt(const transform3d &target)
{

}