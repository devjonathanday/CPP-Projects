#include "raylib.h"
#include"mathLib.h"
#include"Player.h"

int main()
{
	// Initialization
	float screenWidth = 640;
	float screenHeight = 480;

	InitWindow((int)screenWidth, (int)screenHeight, "GameProject");

	SetTargetFPS(60);

	//Initializing single-load data
	Texture2D playerTex = LoadTexture("Assets/player.png");

	//Initializing game objects
	Player player(playerTex, {screenWidth / 2, screenHeight / 2, (float)playerTex.width, (float)playerTex.height});

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		player.Update();

		// Draw
		BeginDrawing();

		ClearBackground(BLACK);

		player.Draw();

		EndDrawing();
	}

	CloseWindow();

	return 0;
}