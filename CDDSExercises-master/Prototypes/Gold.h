#pragma once
#include "Kryptonite.h"
class Gold : public Kryptonite
{
public:
	Gold();
	~Gold();

	// Inherited via Kryptonite
	virtual std::string Diagnose() override;

	// Inherited via Kryptonite
	virtual Kryptonite * Clone() override;
};