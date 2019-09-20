#include"Player.h"
#include<string>

Player::Player(float screenWidth, float screenHeight)
{
	bodyTex = LoadTexture("Assets/tankBody.png");
	turretTex = LoadTexture("Assets/tankTurret.png");
	tankBody = { { screenWidth / 2, screenHeight / 2 }, 0, { 2,2 } };
	tankTurret = { { 0, 0 }, 0, { 1,1 } };
	tankTurret.setParent(&tankBody);
}
Player::~Player() {}

void Player::Update()
{
		if (IsKeyDown(KEY_A))
			tankBody.rotate(-3.0f * (GetFrameTime() * 60));
		if (IsKeyDown(KEY_D))
			tankBody.rotate(3.0f * (GetFrameTime() * 60));
		if (IsKeyDown(KEY_W))
			tankBody.translate(tankBody.forward() * (GetFrameTime() * 60));
			//tankBody.localPos += tankBody.forward() * 3;
		if (IsKeyDown(KEY_S))
			tankBody.translate(-tankBody.forward() * (GetFrameTime() * 60));
			//tankBody.localPos -= tankBody.forward() * 3;
		if (IsKeyDown(KEY_LEFT))
			tankTurret.rotate(-3.0f * (GetFrameTime() * 60));
		if (IsKeyDown(KEY_RIGHT))
			tankTurret.rotate(3.0f * (GetFrameTime() * 60));
		if (IsKeyDown(KEY_UP))
		{
			tankBody.localScale.x += 0.1f;
			tankBody.localScale.y += 0.1f;
		}
		if (IsKeyDown(KEY_DOWN))
		{
			tankBody.localScale.x -= 0.1f;
			tankBody.localScale.y -= 0.1f;
		}
}
void Player::Draw()
{
	DrawTexturePro(bodyTex, { 0,0, (float)bodyTex.width, (float)bodyTex.height },
		{ tankBody.worldPosition().x, tankBody.worldPosition().y, (float)bodyTex.width * tankBody.worldScale().x, (float)bodyTex.height * tankBody.worldScale().y },
		{ ((float)bodyTex.width / 2) * tankBody.worldScale().x, ((float)bodyTex.height / 2) * tankBody.worldScale().y }, _RAD_TO_DEG * tankBody.worldRotation(), GREEN);
	DrawTexturePro(turretTex, { 0,0, (float)turretTex.width, (float)turretTex.height },
		{ tankTurret.worldPosition().x, tankTurret.worldPosition().y, (float)turretTex.width * tankTurret.worldScale().x, (float)turretTex.height * tankTurret.worldScale().y },
		{ tankTurret.worldScale().x * (float)turretTex.width / 4, tankTurret.worldScale().y * (float)turretTex.height / 2 }, _RAD_TO_DEG * tankTurret.worldRotation(), GREEN);
}