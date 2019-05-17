#include <iostream>
#include "raylib.h"
#pragma once

template<typename T>
T min(T a, T b)
{
	if (a <= b)
	{
		return a;
	}
	return b;
}

template<typename T>
T max(T a, T b)
{
	if (a >= b)
	{
		return a;
	}
	return b;
}

template <typename T>
class gameObject
{
public:

	bool enabled;   // is this gameObject enabled?
	T * object;     // pointer to underlying instance of type T

	//gameObject(bool _enabled, Texture2D _tex, Vector2 _position)
	//{
	//	enabled = _enabled;
	//	(*object).tex = _tex;
	//	(*object).position = _position;
	//};
	gameObject(T * _object)
	{
		object = _object;
	};
	gameObject() {};
	~gameObject()
	{

	};

	void update()
	{
		if (!enabled)
		{
			return;
		}
		(*object).update();
	}
};