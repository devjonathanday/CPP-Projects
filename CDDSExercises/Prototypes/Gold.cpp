#include "Gold.h"
Gold::Gold() {}
Gold::~Gold() {}

std::string Gold::Diagnose()
{
	return "GOLD:Atomic variety will remove Superpowers completely";
}

Kryptonite * Gold::Clone()
{
	return new Gold();
}