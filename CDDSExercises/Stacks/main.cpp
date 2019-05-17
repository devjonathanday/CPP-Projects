#include"tStack.h"
#include"Spell.h"
#include"raylib.h"
#include<iostream>
#include"tQueue.h"
#include"Player.h"
#include"Command.h"

using std::cout;
using std::endl;

int main()
{
	int screenWidth = 800;
	int screenHeight = 400;

	InitWindow(screenWidth, screenHeight, "CDDS Exercises");

	/*Texture2D waterTex = LoadTexture("waterSpell.png");
	Texture2D fireTex = LoadTexture("fireSpell.png");
	Texture2D earthTex = LoadTexture("earthSpell.png");
	Texture2D lightningTex = LoadTexture("lightningSpell.png");*/
	//tQueue<Spell> spellStack;

	SetTargetFPS(60);

	Player player(LoadTexture("player.png"), 4);
	tQueue<Vector2> positionQueue;

	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update

		if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
		{
			//commandQueue.push_back(Command({(float)GetMouseX(), (float)GetMouseY()}));
			positionQueue.push_back({(float)GetMouseX(), (float)GetMouseY()});
		}
		//Spellcasting
		{
			/*if (IsKeyPressed(KEY_Q))
				spellStack.push_back({ WATER, waterTex,{ 0,0 } });
			if (IsKeyPressed(KEY_W))
				spellStack.push_back({ FIRE, fireTex,{ 0,0 } });
			if (IsKeyPressed(KEY_E))
				spellStack.push_back({ EARTH, earthTex,{ 0,0 } });
			if (IsKeyPressed(KEY_R))
				spellStack.push_back({ LIGHTNING, lightningTex,{ 0,0 } });
			if (IsKeyPressed(KEY_A))
				spellStack.push_front({ WATER, waterTex,{ 0,0 } });
			if (IsKeyPressed(KEY_S))
				spellStack.push_front({ FIRE, fireTex,{ 0,0 } });
			if (IsKeyPressed(KEY_D))
				spellStack.push_front({ EARTH, earthTex,{ 0,0 } });
			if (IsKeyPressed(KEY_F))
				spellStack.push_front({ LIGHTNING, lightningTex,{ 0,0 } });
			if (IsKeyPressed(KEY_ENTER))
			{
				spellStack.pop_front();
			}
			if (IsKeyPressed(KEY_BACKSPACE))
			{
				spellStack.pop_back();
			}*/
		}

		// Draw
		BeginDrawing();

		ClearBackground(BLACK);

		if (positionQueue.size() > 0)
		{
			player.moveTo(positionQueue);
		}
		DrawTexture(player.texture, player.position.x - player.texture.width / 2, player.position.y - player.texture.height / 2, WHITE);

		/*for (int i = 0; i < spellStack.size(); i++)
		{
			DrawTexture(spellStack[i].tex, i * 20, 10, WHITE);
		}*/

		EndDrawing();
	}

	CloseWindow();

	return 0;
}