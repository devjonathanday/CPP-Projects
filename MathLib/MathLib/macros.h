#pragma once
#include<iostream>

//assert(testName, expression)
#define boolAssert(x, y) \
{	if (y) std::cout << "[PASS] " << x << std::endl; \
	else std::cout << "[FAIL] " << x << std::endl; \
}
//assert(testName, actual, expected)
#define equalAssert(x, y, z) \
{   if (y == z) std::cout << "[PASS] " << x << " = " << z << std::endl; \
	else std::cout << "[FAIL] " << x << " = " << z << std::endl; \
}
#define nearAssert(x, y, z, w) \
{   if (y - z <= w) std::cout << "[PASS] " << x << std::endl; \
	else std::cout << "[FAIL] " << x << std::endl; \
}
//assert(testName, actual, expected)
#define TEST(testName, actual, expected) \
{	std::cout << testName; \
	if(actual == expected) std::cout << " [PASS]" << std::endl; \
	else std::cout << " [FAIL]" << std::endl; \
}