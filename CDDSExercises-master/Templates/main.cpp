#include "raylib.h"
#include "Templates.h"
#include"Ninja.h"
#include"Soldier.h"
#include<iostream>

using namespace std;

int main()
{
	// Initialization
	int screenWidth = 640;
	int screenHeight = 640;

	InitWindow(screenWidth, screenHeight, "Templates");

	SetTargetFPS(60);

	int a = min(3, 4);  // 3
	int b = min(3, 3);  // 3
	int c = min(99, 0); // 0

	int d = max(7, 10); // 10
	int e = max(5, 0);  // 5
	int f = max(6, 6);  // 6

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;
	cout << e << endl;
	cout << f << endl;

	Texture2D ninjaTex = LoadTexture("ninja.png");
	Texture2D soldierTex = LoadTexture("solider.png");
	Ninja myNinja(ninjaTex, { 100,100 }, 2.5f);

	gameObject<Ninja> newNinja(&myNinja);
	newNinja.enabled = true;
	//gameObject<Soldier> mySoldier(soldierTex, { 200,200 });

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update

		// Draw
		BeginDrawing();

		ClearBackground(GRAY);

		newNinja.update();

		//mySoldier.render();

		EndDrawing();
	}
	CloseWindow();

	return 0;
}