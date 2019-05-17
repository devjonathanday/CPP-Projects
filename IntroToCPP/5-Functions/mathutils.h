//mathutils.h
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#pragma once
void Pause();
int sum(int a, int b);
float sum(float a, float b);
void HelloFunctions();
int squareInt(int x);
float fractionToDecimal(float top, float bottom);
float largestDifference(int x, int y, int z);
void printTwoNums(int x, int y);
int sumOfThree(int x, int y, int z);
int minimumNum(int x, int y);
int maximumNum(int x, int y);
int clamp(int lower, int upper, int num);
float pythagoreanTheorem(int x1, int y1, int x2, int y2);
float timeOfArrival(int x1, int y1, int x2, int y2, int speed);
float linearInterpolation(int x, int y, float range);