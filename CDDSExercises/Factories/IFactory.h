#pragma once
#include "IBox.h"
#include <iostream>
class IFactory
{
public:
	//Make sure that all derived classes HAVE a create method
	virtual IBox* Create(std::string type) = 0;
};