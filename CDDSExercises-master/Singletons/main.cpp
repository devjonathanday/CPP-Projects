#include "raylib.h"
#include "Player.h"
#include"Functions.h"
#include"GameState.h"
#include<iostream>
#include<string>
#include"FallingFactory.h"
#include<time.h>
#include<vector>
#include"tObjectPool.h"

using namespace std;

//SimpleSprite* FallingFactory::spriteMasters;
//size_t FallingFactory::spriteCount = 4;

int main()
{
	// Initialization
	int screenWidth = 400;
	int screenHeight = 400;

	srand(time(NULL));

	InitWindow(screenWidth, screenHeight, "CDDS Exercises");

	SetTargetFPS(60);
	Texture2D playerTex = LoadTexture("newPlayer.png");
	Player player(playerTex, { (float)screenWidth / 2 - playerTex.width / 2,(float)screenHeight - playerTex.height,30,31 }, 100, 2);

	Color playerColor = { 125, 125, 125, 255 };
	Rectangle rUp = { 85, 220, 40, 40 };
	Rectangle rDwn = { 85, 290, 40, 40 };
	Rectangle gUp = { 175, 220, 40, 40 };
	Rectangle gDwn = { 175, 290, 40, 40 };
	Rectangle bUp = { 265, 220, 40, 40 };
	Rectangle bDwn = { 265, 290, 40, 40 };
	Rectangle doneButton = { 160, 50, 80, 40 };

	//tObjectPool<SimpleSprite*>

	GameState::GetInstance().setState(MAINMENU);
	//FallingFactory::GetInstance().init(4);

	vector<SimpleSprite*> sprites;

	float gameTimer = 0;
	float spawnTimer = 1;

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		BeginDrawing();
		// Draw/GameState switching
		//Certain inputs and draws are called based on game state.
		switch (GameState::GetInstance().getState())
		{
		case MAINMENU:
		{
			ClearBackground(GRAY);

			if (IsKeyPressed(KEY_L))
				GameState::GetInstance().setState(PLAYERSELECT);

			DrawText("Press 'L' to start!", 100, 200, 20, BLACK);
			break;
		}
		case PLAYERSELECT:
		{
			ClearBackground(BLACK);

			if (CheckButtonClicked(doneButton))
			{
				GameState::GetInstance().setState(GAME);
				player.collider.x = screenWidth / 2 - playerTex.width / 2;
				gameTimer = 0;
				spawnTimer = 1;
			}
			//Menu
			{
				if (CheckButtonHeld(rUp))
					if (playerColor.r < 255)
						playerColor.r += 1;
				if (CheckButtonHeld(rDwn))
					if (playerColor.r > 50)
						playerColor.r -= 1;
				if (CheckButtonHeld(gUp))
					if (playerColor.g < 255)
						playerColor.g += 1;
				if (CheckButtonHeld(gDwn))
					if (playerColor.g > 50)
						playerColor.g -= 1;
				if (CheckButtonHeld(bUp))
					if (playerColor.b < 255)
						playerColor.b += 1;
				if (CheckButtonHeld(bDwn))
					if (playerColor.b > 50)
						playerColor.b -= 1;
				DrawTexture(player.tex, 180, 150, playerColor);
				DrawText("Select your color!", 100, 190, 20, WHITE);
				DrawText("/\\", 90, 230, 20, WHITE);
				DrawText("/\\", 180, 230, 20, WHITE);
				DrawText("/\\", 270, 230, 20, WHITE);
				DrawText("\\/", 90, 300, 20, WHITE);
				DrawText("\\/", 180, 300, 20, WHITE);
				DrawText("\\/", 270, 300, 20, WHITE);
				DrawText("R", 100, 265, 20, RED);
				DrawText("G", 190, 265, 20, GREEN);
				DrawText("B", 280, 265, 20, BLUE);
				DrawText("Done", 175, 60, 20, WHITE);
				DrawText("Use A and D to dodge\n   the falling rocks!", 80, 95, 20, WHITE);
				DrawRecLines(rUp, WHITE);
				DrawRecLines(rDwn, WHITE);
				DrawRecLines(gUp, WHITE);
				DrawRecLines(gDwn, WHITE);
				DrawRecLines(bUp, WHITE);
				DrawRecLines(bDwn, WHITE);
				DrawRecLines(doneButton, WHITE);
			}
			break;
		}
		case GAME:
		{
			gameTimer += GetFrameTime();

			ClearBackground(BLACK);

			//Update all SimpleSprites

			for (int i = 0; i < sprites.size(); i++)
			{
				(*sprites[i]).Update();
				//DrawRecLines((*sprites[i]).rec2, RED);
				if (CheckCollisionRecs(player.collider, (*sprites[i]).rec2))
				{
					GameState::GetInstance().setState(GAMEOVER);
				}
			}

			//DrawText(to_string(gameTimer).c_str(), 20, 20, 20, WHITE);

			if (IsKeyDown(KEY_A))
				if (player.collider.x > 0)
					player.collider.x -= player.moveSpeed;

			if (IsKeyDown(KEY_D))
				if (player.collider.x < screenWidth - playerTex.width)
					player.collider.x += player.moveSpeed;

			if (gameTimer >= spawnTimer)
			{
				//sprites.push_back(FallingFactory::GetInstance().getRandom());
				gameTimer = 0;
				if(spawnTimer > 0.2f)
				spawnTimer -= 0.01f;
			}

			//Drawing

			DrawTexture(player.tex, player.collider.x, player.collider.y, playerColor);

			break;
		}
		case GAMEOVER:
		{
			sprites.clear();
			ClearBackground(RED);

			DrawText("GAME OVER", 100, 200, 30, BLACK);
			DrawText("Press 'L' to restart", 90, 250, 20, BLACK);

			if (IsKeyPressed(KEY_L))
				GameState::GetInstance().setState(MAINMENU);

			break;
		}
		}
		EndDrawing();
	}

	CloseWindow();

	return 0;
}