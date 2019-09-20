#pragma once
#include"vec2.h"
#include"raylib.h"

class Player
{
public:

	//Drawing
	Texture2D tex;
	float rotation;
	float rotationSpeed;
	
	Color tint;

	//Physics/Colliders
	Rectangle rec;
	vec2 velocity;
	float gravityScale;
	float moveSpeed;
	float jumpVelocity;

	//Functions
	void Update();
	void Draw();

	//Constructors/Destructors
	Player();
	Player(Texture2D _tex, Rectangle _rec);
	~Player();
};