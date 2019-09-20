#pragma once

template <typename T>
T lerp(const T& a, const T& b, float t)
{
	return a + (b - a) * t;
}

template <typename T>
T linearEase(float t, const T& b, const T& c, float d)
{
	return b + c * (t / d);
}

template <typename T>
T easeInSine(float t, const T& b, const T& c, float d)
{
	return b + c - c * cosf(t / d * _HALF_PI);
}