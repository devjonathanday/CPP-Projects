#pragma once
#include"raylib.h"

class Command
{
public:
	enum commandType {ATTACK};
	commandType type;

	Command();
	~Command();
};