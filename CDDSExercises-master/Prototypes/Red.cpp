#include "Red.h"
Red::Red() {}
Red::~Red() {}

std::string Red::Diagnose()
{
	return "RED:Can cause mood swings, and erratic behaviour!";
}

Kryptonite * Red::Clone()
{
	return new Red();
}