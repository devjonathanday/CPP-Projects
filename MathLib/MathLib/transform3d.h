#pragma once
#include"vec3.h"
#include"mat4.h"

struct transform3d
{
	vec3 localPosition() const;
	vec3 localRotation() const;
	vec3 localScale() const;

	void setLocalPosition(const vec3 &newPos);
	void setLocalRotation(const vec3 &newRot);
	void setLocalScale(const vec3 &newScale);

	vec3 forward() const;
	void setForward(const vec3 &newForward);

	vec3 right() const;
	void setRight(const vec3 &newRight);

	vec3 up() const;
	void setUp(const vec3 &newUp);

	void translate(const vec3& offset);
	void rotate(const vec3 &rot);

	void lookAt(const transform3d &target);

private:
	mat4 trsMatrix;
};