#include "raylib.h"
#include "Tile.h"
#include<iostream>
#include<string>
#include<time.h>
#include<fstream>

using namespace std;

int main()
{
	// Initialization
	int screenWidth = 640;
	int screenHeight = 640;

	fstream file;

	srand(time(NULL));

	InitWindow(screenWidth, screenHeight, "CDDS Exercises");
	
	//int(*Map)[10] = new int[10][10]

	int Map[10][10] = 
	{{0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
	{ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
	{ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
	{ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
	{ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
	{ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
	{ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
	{ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
	{ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
	{ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0 } };


	Tile * masterTiles[188];
	for (int i = 0; i < 188; i++)
	{
		string fileName;
		fileName = "PNG/mapTile_";
		if (i < 100)
		{
			fileName.append("0");
		}
		if (i < 10)
		{
			fileName.append("0");
		}
		fileName.append(to_string(i));
		fileName.append(".png");
		masterTiles[i] = new Tile(fileName);
	}
	Texture2D backgroundTex = LoadTexture("PNG/mapTile_188.png");

	int activeNum = 0;

	SetTargetFPS(60);

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		
		if (IsKeyPressed(KEY_S))
		{
			file.open("save.txt", ios::out);
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					file << Map[i][j] << " ";
				}
				file << "\n";
			}
			file.flush();
			file.close();
		}
		if (IsKeyPressed(KEY_L))
		{
			file.open("save.txt", ios::in);

			string readOut;

			for (int i = 0; i < 10; i++)
			{
				getline(file, readOut);

				string currentNum;

				int numCounter = 0;

				for (int j = 0; j < strlen(readOut.c_str()); j++)
				{
					if (readOut[j] == ',' && strlen(currentNum.c_str()) > 0)
					{
						Map[i][numCounter] = stoi(currentNum);
						numCounter++;
						currentNum.clear();
					}
					else
					{
						currentNum.append(to_string((int)readOut[j]));
					}
				}
			}
			file.flush();
			file.close();
		}

		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
		{
			int posX = GetMouseX() / 64;
			int posY = GetMouseY() / 64;
			if (posX < 0)
			{
				posX = 0;
			}
			if (posX > 9)
			{
				posX = 9;
			}
			if (posY < 0)
			{
				posY = 0;
			}
			if (posY > 9)
			{
				posY = 9;
			}
			Map[posY][posX] = activeNum;
		}
		if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON))
		{
			int posX = GetMouseX() / 64;
			int posY = GetMouseY() / 64;
			if (posX < 0)
			{
				posX = 0;
			}
			if (posX > 9)
			{
				posX = 9;
			}
			if (posY < 0)
			{
				posY = 0;
			}
			if (posY > 9)
			{
				posY = 9;
			}
			Map[posY][posX] = 0;
		}
		if (GetMouseWheelMove() > 0)
		{
			
			if (activeNum < 187)
			{
				activeNum++;
			}
		}
		if (GetMouseWheelMove() < 0)
		{
			
			if (activeNum > 0)
			{
				activeNum--;
			}
		}

		// Draw
		BeginDrawing();

		ClearBackground(RAYWHITE);

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				DrawTexture(backgroundTex, j * 64, i * 64, WHITE);
			}
		}

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				DrawTexture((*masterTiles[Map[i][j]]).texture, j*64, i*64, (*masterTiles[Map[i][j]]).tint);
			}
		}
		DrawTexture((*masterTiles[activeNum]).texture, 0, 0, (*masterTiles[activeNum]).tint);
		DrawRectangleLines(0, 0, 64, 64, { 255,0,0,255 });
		string tileNum = to_string(activeNum+1);
		tileNum.append("/188");
		DrawText(tileNum.c_str(), 4, 68, 10, { 255,0,0,255 });

		EndDrawing();
	}
	CloseWindow();

	delete Map;

	return 0;
}