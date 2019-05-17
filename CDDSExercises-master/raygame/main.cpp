#include "raylib.h"
#include "Meep.h"
#include "Item.h"

int main()
{
	// Initialization
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "CDDS Exercises");

	//Texture2D * potionTex = new Texture2D();
	//*potionTex = LoadTexture("potion.png");
	//int * potionType;
	//*potionType = 0;

	Meep ** meeps = new Meep*[3];
	//Item * potion = new Item(potionType, 50, 0, potionTex, 0);

	int meepCount = 3;
	int currentMeep = 0;

	for (int i = 0; i < meepCount; i++)
	{
		meeps[i] = new Meep(true, "meep.png", false);
		(*meeps[i]).x = 100 + (i * 100);
	}

	(*meeps[0]).playerControlled = true;

	//Meep meep1(true, "meep.png", true);

	SetTargetFPS(60);

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update

		// Draw
		BeginDrawing();

		ClearBackground(RAYWHITE);

		//DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

		for (int i = 0; i < meepCount; i++)
		{
			(*meeps[i]).refresh();
			if (i == currentMeep)
			{
				(*meeps[i]).playerControlled = true;
			}
			else
			{
				(*meeps[i]).playerControlled = false;
			}
		}
		if (IsKeyPressed(KEY_SPACE))
		{
			currentMeep++;
			if (currentMeep > 2)
			{
				currentMeep = 0;
			}
		}

		EndDrawing();
	}

	for (int i = 0; i < meepCount; i++)
	{
		delete meeps[i];
	}
	delete meeps;

	CloseWindow();

	return 0;
}