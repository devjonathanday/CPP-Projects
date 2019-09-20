#include"transform2d.h"

transform2d::transform2d()
{
	localPos = { 0, 0 };
	localRot = 0;
	localScale = { 1, 1 };
	parent = nullptr;
}
transform2d::transform2d(vec2 pos, float rot, vec2 scale)
{
	localPos = pos;
	localRot = rot;
	localScale = scale;
	parent = nullptr;
}
void transform2d::translate(const vec2 &offset)
{
	mat3 newMat = getTRSMatrix();
	newMat = mat3::translation(offset.x, offset.y);
	localPos += {newMat.m3, newMat.m6};
	//localPos += offset;
}
void transform2d::rotate(const float angle)
{
	//mat3 newMat = getTRSMatrix();
	//newMat = mat3::rotation(angle);
	//localRot += atan2f( newMat.m4, newMat.m1 );
	localRot += angle;
}
void transform2d::lookAt(vec2 &target)
{
	localRot = atan2(target.y - worldPosition().y, target.x - worldPosition().x);
}
vec2 transform2d::forward() const
{
	return vec2(cos(_DEG_TO_RAD * localRot), sin(_DEG_TO_RAD * localRot) ).getNormalized();
}
void transform2d::setForward(const vec2 &newFwd)
{
	localRot = atan2(newFwd.y, newFwd.x);
}
mat3 transform2d::getTRSMatrix() const
{
	return mat3::translation(localPos) * mat3::rotation(_DEG_TO_RAD * localRot) * mat3::scale( localScale.x, localScale.y );
}
mat3 transform2d::worldTRS() const
{
	if (getParent() != nullptr)
		return (parent->worldTRS() * getTRSMatrix());
	return getTRSMatrix();
}
vec2 transform2d::worldPosition() const
{
	return { worldTRS().m3, worldTRS().m6 };
	/*if (getParent() != nullptr) {
		float tA = atan2(localPos.x, localPos.y) + parent->worldRotation();
		float tR = sqrt(localPos.x*localPos.x + localPos.y*localPos.y);
		return { cos(tA) * tR + parent->worldPosition().x, sin(tA) * tR + parent->worldPosition().y };
	}
	return localPos;*/
	/*
	if (parent == nullptr)
		return localPos;

	transform2d * temp = parent;

	vec2 worldPos = { 0, 0 };

	while (temp != nullptr)
	{
		worldPos.x += temp->localPos.x + localPos.x * (cos(temp->localRot) * temp->localScale.x);
		worldPos.y += temp->localPos.y + localPos.y * (-sin(temp->localRot) * temp->localScale.y);
		temp = temp->parent;
	}
	delete temp;
	return worldPos;
	*/
}
float transform2d::worldRotation() const
{
	return atan2(worldTRS().m4, worldTRS().m1);
	/*mat3 newMat = getTRSMatrix();
	if (getParent() != nullptr) 
	{
		newMat *= parent->getTRSMatrix();
		return atan2(newMat.m4, newMat.m1);
	}
	return localRot;*/
}
vec2 transform2d::worldScale() const
{
	//if (getParent() == nullptr) 
	//	return localScale;
	//return { localScale.x * parent->worldScale().x,localScale.y * parent->worldScale().y };
	return { sqrt((worldTRS().m1 * worldTRS().m1) + (worldTRS().m4 * worldTRS().m4)), sqrt((worldTRS().m2 * worldTRS().m2) + (worldTRS().m5 * worldTRS().m5)) };
}
void transform2d::setParent(transform2d *_parent)
{
	parent = _parent;
	parent->children.push_back(this);
}
transform2d * transform2d::getParent()
{
	return parent;
}
transform2d const * transform2d::getParent() const
{
	return parent;
}
transform2d * transform2d::getChildren()
{
	return children[0];
}
transform2d * const * transform2d::getChildren() const
{
	return &children[0];
}
size_t transform2d::getChildrenCount() const
{
	return children.size();
}