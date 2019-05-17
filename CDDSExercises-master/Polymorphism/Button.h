#pragma once
#include"raylib.h"

class Button
{
public:
	Rectangle rec;

	Button();
	Button(Rectangle _rec);
	~Button();

	bool CheckClicked();
	void DrawButtonRec(Color color);
};