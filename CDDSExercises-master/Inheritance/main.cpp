#include "raylib.h"
#include"Sprite.h"
#include"Button.h"
#include<iostream>
#include<string.h>

int main()
{
	// Initialization
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "CDDS Exercises");

	SetTargetFPS(60);

	float gameTimer = 0;

	std::string playerSprites[] = 
	{
		"playerSprite01.png",
		"playerSprite02.png",
		"playerSprite03.png",
		"playerSprite04.png",
		"playerSprite05.png",
		"playerSprite06.png",
		"playerSprite07.png",
		"playerSprite08.png",
		"playerSprite09.png",
		"playerSprite10.png",
		"playerSprite11.png",
		"playerSprite12.png",
		"playerSprite13.png",
		"playerSprite14.png",
		"playerSprite15.png"
	};
	std::string buttonSprites[] =
	{
		"buttonSprite01.png",
		"buttonSprite02.png"
	};

	Sprite playerSprite(playerSprites, sizeof(playerSprites) / sizeof(playerSprites[0]), 4);
	Button pressButton(buttonSprites, {100,100}, 1);

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update

		gameTimer += GetFrameTime();

		// Draw
		BeginDrawing();

		ClearBackground(RAYWHITE);

		playerSprite.Animate(gameTimer, sizeof(playerSprites) / sizeof(playerSprites[0]));
		pressButton.Update();

		EndDrawing();
	}
	CloseWindow();

	return 0;
}