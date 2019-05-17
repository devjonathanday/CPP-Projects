#pragma once
#include <iostream>
#include "IBox.h"
class RedBox : public IBox
{
public:
	std::string Color(void);
};