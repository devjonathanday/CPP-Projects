#include"raylib.h"
#pragma once

enum spellTypes {WATER, FIRE, EARTH, LIGHTNING};

struct Spell
{
	spellTypes type;
	Texture2D tex;
	Vector2 position;
};