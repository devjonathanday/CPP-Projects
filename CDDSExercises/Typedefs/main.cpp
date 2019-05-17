#include "raylib.h"
#include "DialFace.h"

typedef DialFace Clock;

Vector2 Clock::position = { 200,200 };
float Clock::radius = 200;

float Clock::seconds = 0;
int Clock::minutes = 0;
int Clock::hours = 0;

int main()
{
	// Initialization
	int screenWidth = 400;
	int screenHeight = 400;

	InitWindow(screenWidth, screenHeight, "CDDS Exercises");

	SetTargetFPS(60);

	Clock clock;

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update

		// Draw
		BeginDrawing();
		ClearBackground(BLACK);
		clock.Tick();
		clock.DrawFace();
		EndDrawing();
	}
	CloseWindow();

	return 0;
}