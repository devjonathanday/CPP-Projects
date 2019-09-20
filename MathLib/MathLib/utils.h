#pragma once

//Clipping

int min(int a, int b);
int max(int a, int b);
int sum(int a, int b);
int clamp(int value, int lower, int upper);

//Constants

const double _PI = 3.141592653589793;
const double _HALF_PI = 1.570796326794897;
const double _DEG_TO_RAD = _PI/180;
const double _RAD_TO_DEG = 180/_PI;

//Operations

int absVal(int val);
int pow(int base, int power);
bool isPowerOfTwo(int val);
int nextPowerOfTwo(int val);
float moveTowards(float current, float target, float maxDelta);
//float angleFromVector(float x, float y);