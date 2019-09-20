#pragma once

template <typename T>
T quadraticBezier(const T& a, const T& b, const T& c, float t)
{
	T x = lerp(a, b, t);
	T y = lerp(b, c, t);
	return lerp(x, y, t);
}

template <typename T>
T cubicBezier(const T& a, const T& b, const T& c, const T& d, float t)
{
	T x = lerp(a, b, t);
	T y = lerp(b, c, t);
	T z = lerp(c, d, t);
	return quadraticBezier(x, y, z, t);
}

template <typename T> T hermite(const T& p0, const T& t0, const T& p1, const T& t1, float t)
{
	// calculate the time-step squared and cubed
	float tt = t * t;
	float ttt = tt * t;

	// calculate hermite basis curves
	float h00 = 2 * ttt - 3 * tt + 1;
	float h10 = ttt - 2 * tt + t;
	float h01 = -2 * ttt + 3 * tt;
	float h11 = ttt - tt;

	// combine points and tangents
	return p0 * h00 + t0 * h10 + p1 * h01 + t1 * h11;
}

template <typename T> T catmullRomSpline(const T* controlPoints, size_t count, float t)
{
	//assert(count > 1);

	// early out
	if (t <= 0) return controlPoints[0];
	if (t >= 1) return controlPoints[count - 1];

	// how long does a single curve segment last for
	float stepDuration = 1.0f / (count - 1);

	// find control point indices
	int p0 = int(t / stepDuration);
	int p1 = p0 + 1;

	// calculate tangents
	T t0, t1;
	if (p0 == 0)
		t0 = (controlPoints[p0 + 1] - controlPoints[p0]) * 0.5f;
	else if (p0 == count - 1)
		t0 = (controlPoints[p0] - controlPoints[p0 - 1]) * 0.5f;
	else
		t0 = (controlPoints[p0 + 1] - controlPoints[p0 - 1]) * 0.5f;

	if (p1 == 0)
		t1 = (controlPoints[p1 + 1] - controlPoints[p1]) * 0.5f;
	else if (p1 == count - 1)
		t1 = (controlPoints[p1] - controlPoints[p1 - 1]) * 0.5f;
	else
		t1 = (controlPoints[p1 + 1] - controlPoints[p1 - 1]) * 0.5f;

	// how far are we through this segment
	float s = fmod(t, stepDuration) / stepDuration;

	// return curve result
	return hermite(controlPoints[p0], t0, controlPoints[p1], t1, s);
}