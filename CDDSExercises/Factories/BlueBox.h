#pragma once
#include <iostream>
#include "IBox.h"

class BlueBox : public IBox
{
public:
	std::string Color(void);
};