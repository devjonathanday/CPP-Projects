#include "raylib.h"
#include"Wizard.h"
#include"Barbarian.h"
#include"Player.h"

int main()
{
	// Initialization
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "CDDS Exercises");

	Player player;

	//Wizard wiz;
	//Barbarian barbar;

	SetTargetFPS(60);

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update

		// Draw
		BeginDrawing();

		ClearBackground(RAYWHITE);

		player.update();

		//barbar = wiz;

		EndDrawing();
	}

	CloseWindow();

	return 0;
}