#include"HeaderCollection.h"
#include"raylib.h"
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	// Initialization
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "CDDS Exercises");

	Vector2 destination = { 400, 225 };

	bool gameRunning = true;
	int gamePhase = 0;

	int ents = 5;
	int necromancers = 5;

	//Texture loading
	Texture2D wizardTex = LoadTexture("wizard.png");
	Texture2D barbarianTex = LoadTexture("barbarian.png");
	Texture2D entTex = LoadTexture("ent.png");
	Texture2D necromancerTex = LoadTexture("necromancer.png");

	//Object instances
	Player * player = new Player();
	Necromancer * necro = new Necromancer(necromancerTex);
	EvilEnt * ent = new EvilEnt(entTex);

	std::vector<Enemy*> enemies;

	Button wizardButton({ 64, 32, 672, 120});
	Button barbarianButton({ 64, 184, 672, 120 });

	Button lessEnts({ 64, 350, 64, 64 });
	Button moreEnts({ 300, 350, 64, 64 });

	Button lessNecromancers({ 400, 350, 64, 64 });
	Button moreNecromancers({ 700, 350, 64, 64 });

	SetTargetFPS(60);

	// Main game loop
	while (gameRunning) // Detect window close button or ESC key
	{
		if (IsKeyPressed(KEY_Q))
		{
			gameRunning = false;
		}
		switch (gamePhase)
		{
		case 0:
		{
			BeginDrawing();

			ClearBackground(BLACK);

			//Drawing menu buttons/text
			{
				wizardButton.DrawButtonRec(DARKGRAY);
				DrawText("Wizard", screenWidth / 2 - 80, 70, 50, BLUE);
				barbarianButton.DrawButtonRec(DARKGRAY);
				DrawText("Barbarian", screenWidth / 2 - 120, 230, 50, RED);

				DrawText("Ents", 170, 350, 30, RED);
				DrawText(to_string(ents).c_str(), 190, 380, 30, RED);

				DrawText("Necromancers", 500, 350, 25, PURPLE);
				DrawText(to_string(necromancers).c_str(), 570, 380, 30, PURPLE);

				lessNecromancers.DrawButtonRec(DARKGRAY);
				moreNecromancers.DrawButtonRec(DARKGRAY);

				lessEnts.DrawButtonRec(DARKGRAY);
				moreEnts.DrawButtonRec(DARKGRAY);
			}

			if(wizardButton.CheckClicked())
			{
					player = new Wizard(wizardTex);
					for (int i = 0; i < ents; i++)
					{
						//ent = new EvilEnt;
						enemies.push_back(new EvilEnt);
					}
					for (int i = 0; i < necromancers; i++)
					{
						//necro = new Necromancer;
						enemies.push_back(new Necromancer);
					}
					gamePhase = 1;
					
			}
			if (barbarianButton.CheckClicked())
			{
				player = new Barbarian(barbarianTex);
				for (int i = 0; i < ents; i++)
				{
					enemies.push_back(ent);
				}
				for (int i = 0; i < necromancers; i++)
				{
					enemies.push_back(necro);
				}
				gamePhase = 1;
			}
			if (moreEnts.CheckClicked()) { if (ents < 10) ents++; }
			if (lessEnts.CheckClicked()) { if (ents > 0) ents--; }
			if (moreNecromancers.CheckClicked()) { if (necromancers < 10) necromancers++; }
			if (lessNecromancers.CheckClicked()) { if (necromancers > 0) necromancers--; }
			EndDrawing();
		}
		break;
		case 1:
		{
			BeginDrawing();

			ClearBackground(BLACK);

			// Update

			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				destination = GetMousePosition();
			}

			(*player).moveTo(destination);
			for (auto i = enemies.begin(); i != enemies.end(); i++)
			{
				(*i)->update(player->position);
			}
			//ent.update(player->position);
			//necro.update(player->position);

			EndDrawing();
		}
		break;
		}
	}
	CloseWindow();

	delete player;

	return 0;
}