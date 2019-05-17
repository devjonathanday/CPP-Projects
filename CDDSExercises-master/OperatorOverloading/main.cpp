#include "raylib.h"
#include"MyHero.h"
#include"Potion.h"
#include"Color.h"

int main()
{
	// Initialization
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "CDDS Exercises");

	//Texture2D guyTex = LoadTexture("ouch1.png");
	//*guyTex = LoadTexture("ouch5.png");

	MyHero * hero = new MyHero("DoomGuy", "SpecialAttack", 30, 1, 50, {200, 200});
	Potion healingPotion;

	MyColor * boxColor = new MyColor();

	SetTargetFPS(60);

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update

		// Draw
		BeginDrawing();

		ClearBackground(RAYWHITE);

		if (IsKeyPressed(KEY_SPACE))
		{
			if ((*hero + healingPotion).HP < 6)
			{
				*hero += healingPotion;
			}
		}
		if (IsKeyPressed(KEY_W))
		{
			*boxColor += MyColor(31,12,51,0);
		}

		DrawRectangle(300, 300, 50, 50, boxColor->GetRealColor(*boxColor));

		hero->update();

		EndDrawing();
	}
	CloseWindow();

	delete hero;
	delete boxColor;

	return 0;
}