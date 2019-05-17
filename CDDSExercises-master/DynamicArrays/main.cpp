#include"tVector.h"
#include "raylib.h"
#include<iostream>
#include"Object.h"
#include<time.h>
#include"Functions.h"

using std::cout;
using std::endl;

int main()
{
	//Testing vector functionality
	{
		/*
		tVector<int> original;
		original.push_back(4);
		original.push_back(5);
		original.push_back(6);

		for (int i = 0; i < original.size(); i++)
		{
			cout << original[i] << endl;
		}

		tVector<int> copy;
		copy = original;
		original.pop_back(); // removes from the original array, but not the copy
		original.pop_back();
		original.pop_back();

		cout << copy.size() << endl;
		cout << copy.capacity() << endl;
		cout << original.size() << endl;
		cout << original.capacity() << endl;
		*/
	}

	int screenWidth = 800;
	int screenHeight = 400;

	srand(time(NULL));

	InitWindow(screenWidth, screenHeight, "CDDS Exercises");

	Texture2D objectTex = LoadTexture("objectTex.png");

	SetTargetFPS(120);

	tVector<Object> objects;

	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update

		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
		{
			objects.push_back({ {(float)randomNumber(-20, 20) / 10,(float)randomNumber(-20, 20) / 10},
				                {(float)GetMouseX(), (float)GetMouseY()}, objectTex, randomNumber(0, 360), 1.0f });
		}

		// Draw
		BeginDrawing();

		ClearBackground(BLACK);

		for(int i = 0; i < objects.size(); i++)
		{
			objects[i].position.x += objects[i].movementDir.x;
			objects[i].position.y += objects[i].movementDir.y;
			objects[i].scale += 0.1f;
			objects[i].rotation++;
			DrawTextureEx(objects[i].tex, objects[i].position, objects[i].rotation, objects[i].scale, GRAY);
		}

		EndDrawing();
	}

	CloseWindow();

	return 0;
}