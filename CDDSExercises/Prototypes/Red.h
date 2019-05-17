#pragma once
#include "Kryptonite.h"
class Red : public Kryptonite
{
public:
	Red();
	~Red();

	// Inherited via Kryptonite
	virtual std::string Diagnose() override;

	// Inherited via Kryptonite
	virtual Kryptonite * Clone() override;
};