#pragma once
#include"raylib.h"

bool CheckButtonClicked(Rectangle buttonRec);
bool CheckButtonHeld(Rectangle buttonRec);
void DrawRecLines(Rectangle rec, Color color);
int randomNumber(int minRange, int maxRange);