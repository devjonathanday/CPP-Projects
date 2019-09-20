#pragma once
#include"transform2d.h"
#include<iostream>
#include"raylib.h"

class Player
{
public:

	Player();
	Player(float screenWidth, float screenHeight);
	~Player();

	transform2d tankBody;
	transform2d tankTurret;

	Texture2D bodyTex;
	Texture2D turretTex;

	void Draw();
	void Update();
};