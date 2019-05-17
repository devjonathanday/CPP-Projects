#pragma once
#include <iostream>
class Kryptonite
{
public:
	Kryptonite() {};
	~Kryptonite() {};

	virtual std::string Diagnose() = 0;
	virtual Kryptonite * Clone() = 0;
};