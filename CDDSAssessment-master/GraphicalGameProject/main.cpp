#include "raylib.h"
#include"Player.h"
#include"GameState.h"
#include"Functions.h"
#include"ColorMenu.h"
#include"Alien.h"
#include<vector>
#include<string>

int main()
{
	// Initialization
	int screenWidth = 640;
	int screenHeight = 480;

	InitWindow(screenWidth, screenHeight, "CDDS Exercises");

	SetTargetFPS(120);

	bool quitGame = false;

	//Menu Buttons
	Rectangle startButton = { 32, 256, 576, 64 };
	Rectangle quitButton = { 32, 352, 576, 64 };
	Rectangle startGameButton = { 32, 352, 576, 64 };
	ColorMenu menu;

	//Game Variables/Instances
	Player player(LoadTexture("Assets/player.png"), { 125,125,125,255 }, 100, 4);
	Texture2D alienTex = LoadTexture("Assets/alien.png");
	Texture2D bulletTex = LoadTexture("Assets/bullet.png");
	Texture2D bulletTex2 = LoadTexture("Assets/bullet2.png");
	//Texture2D background = LoadTexture("Assets/background.png");
	GameState::GetInstance().setState(TITLE);
	int score = 0;
	int highScore = 0;
	float spawnTimer = 0;
	float spawnTime = 1;
	std::string scoreText = "0";
	std::string highScoreText = "0";

	std::vector<Alien> alienList;
	std::vector<Bullet> bulletList;
	Bullet playerBullet = { bulletTex2, { 0, 0, 16, 16}, 5, 5, {0, -1}, true };
	Bullet enemyBullet = { bulletTex,{ 0, 0, 16, 16 }, 5, 5,{ 0, -1 }, true };

	// Main game loop
	while (!quitGame && !WindowShouldClose())    // Detect window close button or ESC key
	{
		BeginDrawing();

		switch (GameState::GetInstance().getState())
		{
		case(TITLE):
		{
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				if (CheckButton(startButton)) GameState::GetInstance().setState(MENU);
				if (CheckButton(quitButton)) quitGame = true;
			}

			//Draw
			ClearBackground(BLACK);
			DrawRecLines(startButton, WHITE);
			DrawRecLines(quitButton, WHITE);
			DrawText("ATMOSPHERE\n INTRUDERS", 110, 64, 60, RED);
			DrawText("Start", 264, 270, 40, WHITE);
			DrawText("Quit", 282, 366, 40, WHITE);
		}
		break;
		case(MENU):
		{
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				if (CheckButton(startGameButton))
				{
					GameState::GetInstance().setState(GAME);
					score = 0;
					alienList.clear();
					bulletList.clear();
					player.rec.x = (GetScreenWidth() / 2) - (float)(player.tex.width / 2);
				}
			}
			menu.Update(player.color);

			//Draw
			ClearBackground(BLACK);
			DrawTextureEx(player.tex, { 400, 117 }, 0, 3, player.color);
			DrawRecLines(startGameButton, WHITE); DrawText("Start Game!", startGameButton.x + 165, startGameButton.y + 15, 40, WHITE);
			DrawText("Use A and D to move left and right.", 50, 250, 20, WHITE);
			DrawText("Click on the screen to shoot.", 50, 280, 20, WHITE);
			DrawText("Dodge the bullets and destroy the enemy ships!", 50, 310, 20, WHITE);
			menu.Draw();
		}
			break;
		case(GAME):
		{
			spawnTimer += GetFrameTime();
			
			player.Update(bulletList, playerBullet);
			
			if (spawnTimer >= spawnTime)
			{
				Alien newAlien(alienTex);
				alienList.push_back(newAlien);
				spawnTimer = 0;
				if (spawnTime > 0.3f)
					spawnTime -= 0.02f;
			}

			for (int i = 0; i < alienList.size(); i++)
			{
				alienList[i].Update({ player.rec.x, player.rec.y }, bulletList, enemyBullet);

				//Delete if alien is out of bounds
				if (alienList[i].rec.x < -32 || alienList[i].rec.x > 672 || alienList[i].rec.y < -32 || alienList[i].rec.y > 512)
					alienList.erase(alienList.begin() + i);

				for (int k = 0; k < bulletList.size(); k++)
				{
					if (bulletList[k].playerMade && CheckCollisionRecs(bulletList[k].rec, alienList[i].rec))
					{
						alienList.erase(alienList.begin() + i);
						bulletList.erase(bulletList.begin() + k);
						score++;
						if (score > highScore)
							highScore = score;

						continue;
					}
					if (!bulletList[k].playerMade && CheckCollisionRecs(player.rec, bulletList[k].rec))
						GameState::GetInstance().setState(GAMEOVER);
				}
			}
			for (int i = 0; i < bulletList.size(); i++)
			{
				bulletList[i].Update();
				//Delete if bullet is out of bounds
				if (bulletList[i].rec.x < -32 || bulletList[i].rec.x > 672 || bulletList[i].rec.y < -32 || bulletList[i].rec.y > 512)
					bulletList.erase(bulletList.begin() + i);
			}

			scoreText = std::to_string(score);
			highScoreText = std::to_string(highScore);

			//Draw
			ClearBackground(BLACK);
			player.Draw();
			for (int i = 0; i < alienList.size(); i++)
				alienList[i].Draw();
			for (int i = 0; i < bulletList.size(); i++)
				bulletList[i].Draw();
			DrawText("Score: ", 20, 20, 20, WHITE);
			DrawText("High Score: ", 20, 50, 20, GREEN);
			DrawText(scoreText.c_str(), 90, 20, 20, WHITE);
			DrawText(highScoreText.c_str(), 140, 50, 20, GREEN);
		}
			break;
		case(GAMEOVER):
		{
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				if (CheckButton(startGameButton)) GameState::GetInstance().setState(MENU);

			ClearBackground({90,0,0,255});
			DrawTextureEx(player.tex, { 288, 250 }, 0, 2, player.color);
			DrawText("GAME OVER", 70, 80, 80, WHITE);
			DrawRecLines(startGameButton, WHITE); DrawText("Restart?", startGameButton.x + 210, startGameButton.y + 15, 40, WHITE);
			DrawText("or Press ESC to quit", 220, 425, 20, WHITE);
			DrawText("Your Score: ", 200, 170, 30, WHITE);
			DrawText("High Score: ", 200, 210, 30, WHITE);
			DrawText(scoreText.c_str(), 400, 170, 30, WHITE);
			DrawText(highScoreText.c_str(), 400, 210, 30, GREEN);
		}
		break;
		}
		EndDrawing();
	}

	CloseWindow();

	return 0;
}