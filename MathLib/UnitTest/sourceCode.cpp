//#include<iostream>
//#include<cassert>
//#include"utils.h"
//#include"vec2.h"
//#include"vec3.h"
//#include"raylib.h"
//#include"Player.h"
//#include"Ball.h"
//#include<vector>
//
//using std::vector;
//
////int main()
////{
//	////utils.h testing
//	/*//assert(min(2, 3) == 2);
//	//assert(max(7, 3) == 7);
//	//assert(clamp(5, 7, 10) == 7);
//	//assert(absVal(-5) == 5);
//	//assert(pow(5, 3) == 125);
//	//assert(isPowerOfTwo(7) == false);
//	//assert(nextPowerOfTwo(100) == 128);
//	//assert(moveTowards(50, 15, 5) == 45);*/
//
//	////vec2.h testing
//	/*//vec2 vecA = { 2.1f, 3 };
//	//vec2 vecB = { 2.5f, 3 };
//	//bool equal = vecA == vecB;
//	//bool unequal = vecA != vecB;
//	//vec2 vecC = vecA + vecB;
//	//vecA += vecC;
//	//vecB -= vecA;
//	//vec2 vecD = -vecB;
//	//float test = vecA[size_t(0)];
//	//float * vectorStart = vecA;*/
//
//	////vec3.h testing
//	/*vec3 vecA = { 2.1f, 3, 7 };
//	vec3 vecB = { 2.1001f, 3, 7 };
//	bool equal = vecA == vecB;
//	bool unequal = vecA != vecB;
//	vec3 vecC = vecA + vecB;
//	vecA += vecC;
//	vecB -= vecA;
//	vec3 vecD = -vecB;
//	float * vectorStart = vecA;*/
//
//
//	//Raylib testing
//  //SINE WAVES
//
//	int screenWidth = 640;
//	int screenHeight = 480;
//
//	InitWindow(screenWidth, screenHeight, "MathLib Test");
//
//	SetTargetFPS(60);
//	HideCursor();
//	Player player{ LoadTexture("Assets/ball.png"),{ (float)screenWidth / 2,(float)screenHeight / 2 }, 4 };
//	Ball defaultBall = { LoadTexture("Assets/ball.png"),{ (float)screenWidth / 2,(float)screenHeight / 2 },{ 2, 0 },{ 1, 1 },{ 1, -1 }, 0, 0 };
//	vector<Ball> particles;
//	vec2 mousePos((float)GetMouseX(), (float)GetMouseY());
//	vec2 newPosition(0, 0);
//
//	vec2 spawnLoc = { 0, 0 };
//	float distFactor = 50;
//	float speedFactor = 5;
//	float spawnTimer = 0;
//	float timer = 0;
//	float amount = 10;
//	float spawnTime = 0.5f;
//
//	vector<double> xPos;
//	vector<double> yPos;
//	for (int i = 0; i < 64; i += 1)
//	{
//		xPos.push_back(i * 10);
//		yPos.push_back(sin(i) * 40 + 240);
//	}
//
//	// Main game loop
//	while (!WindowShouldClose())  // Detect window close button or ESC key
//	{
//		// Update
//
//		spawnTimer += GetFrameTime();
//		timer += GetFrameTime();
//
//		//spawnLoc = { -cos(timer * distFactor) * 20 + particles[i].offset, -sin(timer * distFactor) * 20 + particles[i].offset };
//
//		mousePos = { (float)GetMouseX(), (float)GetMouseY() };
//
//		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
//		{
//			newPosition = mousePos;
//		}
//
//		distFactor = (sin(timer) * 50);
//
//		if (spawnTimer > spawnTime && particles.size() < amount)
//		{
//			Ball newBall = defaultBall;
//			newBall.offset = timer;
//			particles.push_back(newBall);
//			spawnTimer = 0;
//		}
//
//		//if (IsKeyPressed(KEY_SPACE))
//		//{
//		//	if (ball.velocity.getNormalized().dot((player.position - ball.position).getNormalized()) < 0)
//		//	{
//		//		ball.position = { -100, -100 }; //"dead"
//		//	}
//		//}
//		//player.position += (newPosition - player.position).getNormalized() * player.speed * (GetFrameTime() * 60);
//		player.position = { mousePos.x - player.tex.width / 2, mousePos.y - player.tex.height / 2 };
//		//ball.position += ball.velocity * GetFrameTime() * 60;
//
//		//Ball ball2{ LoadTexture("Assets/ball.png"),{ (float)screenWidth / 2,(float)screenHeight / 2 },{ 2, 0 },{ 1, 1 },{ 1, -1 }, 0 };
//		for (size_t i = 0; i < particles.size(); i++)
//		{
//			particles[i].position = { player.position.x + -cos((timer * speedFactor) + particles[i].offset) * distFactor,
//				player.position.y + -sin((timer * speedFactor) + particles[i].offset) * distFactor };
//
//			if (particles[i].position.x > GetScreenWidth() - particles[i].tex.width || particles[i].position.x < 0)
//				particles[i].velocity.x = -particles[i].velocity.x;
//			if (particles[i].position.y > GetScreenHeight() - particles[i].tex.height || particles[i].position.y < 0)
//				particles[i].velocity.y = -particles[i].velocity.y;
//			//particles[i].aimAngle = particles[i].leftEdge.angleBetween(particles[i].rightEdge);
//		}
//
//		// Draw
//		BeginDrawing();
//
//		ClearBackground(BLACK);
//
//		DrawTexture(player.tex, (int)player.position.x, (int)player.position.y, WHITE);
//
//		for (size_t i = 0; i < particles.size(); i++)
//			DrawTexture(particles[i].tex, (int)particles[i].position.x, (int)particles[i].position.y, WHITE);
//
//		//Water Wave
//		for (size_t i = 0; i < xPos.size() - 1; i += 1)
//		{
//			DrawLineEx({ (float)xPos[i], (float)yPos[i] }, { (float)xPos[i + 1], (float)yPos[i + 1] }, 4, BLUE);
//		}
//
//		//vec2 drawBox = { 100, 200 };
//
//		//const char * declOfIndependence = "When in the Course of human events, it becomes necessary for one people to dissolve the political bands which have connected them with another, and to assume among the powers of the earth, the separate and equal station to which the Laws of Nature and of Nature's God entitle them, a decent respect to the opinions of mankind requires that they should declare the causes which impel them to the separation.";
//		//int textWidth = MeasureText(declOfIndependence, 20);
//		//int chunk = textWidth / drawBox.x;
//
//		//for (int i = 0; i < drawBox.y; i++)
//		//	DrawText((SubText(declOfIndependence, chunk * i, chunk)), 0, i * 20, 20, WHITE);
//
//		EndDrawing();
//	}
//
//	CloseWindow();
//
//
//	float scalar = 3.5f;
//	vec2 dir = { 0, 1 };
//
//	vec2 newVelocity = scalar * dir;
//	//Testing angle between vectors
//	/*vec2 vecA = { 1,4 };
//	vec2 vecB = { 1, -1 };
//	float testAng = RAD_TO_DEG * vecA.angleBetween(vecB);*/
//
//	//return 0;
////}
//--------------------------------------------------------------------------------------------------
//PARTICLES, LINEAR INTERPOLATION
/*
{
float screenWidth = 640;
float screenHeight = 480;

InitWindow((int)screenWidth, (int)screenHeight, "Unit Test");

SetTargetFPS(60);

struct Player
{
Texture2D tex;
vec2 pos;
float speed;
int destIndex;
float health;
float maxHealth;
};

struct Spark
{
Texture2D tex;
vec2 position;
Vector2 direction;
float speed;
float lifeTimer;
};

enum BUTTONSTATE { IDLE, HOVER, PRESSED, DISABLED };

struct Button
{
Texture2D tex;
BUTTONSTATE state;
Color tint;
};

Texture2D pointTex = LoadTexture("Assets/point.png");
vector<vec2> points;
points.push_back({ 100, 100 });
points.push_back({ 170, 130 });
points.push_back({ 220, 170 });
points.push_back({ 240, 200 });
points.push_back({ 400, 230 });
points.push_back({ 360, 300 });
points.push_back({ 240, 290 });

Texture2D sparkTex = LoadTexture("Assets/spark.png");

vector<Spark> particles;

Player player{ LoadTexture("Assets/ball.png"), {screenWidth / 2, screenHeight / 2}, 1, 0, 100, 100 };

Texture2D buttonIdle = LoadTexture("Assets/button.png");
Texture2D buttonPressed = LoadTexture("Assets/buttonPressed.png");

Button button{buttonIdle};

float timer = 0;
float sparkTimer = 0;
float sparkTime = 0.01f;

while (!WindowShouldClose())
{
// Update

timer += GetFrameTime();
sparkTimer += GetFrameTime();
if (sparkTimer >= sparkTime)
{
sparkTimer = 0;
Spark newSpark = { sparkTex,{ player.pos.x, player.pos.y },{ randomNumber(-10, 10), randomNumber(-10, 10) }, randomNumber(1, 4), 1 };
particles.push_back(newSpark);
}

for (size_t i = 0; i < particles.size(); i++)
{
particles[i].position.x += NormalizeVector2(particles[i].direction).x * particles[i].speed;
particles[i].position.y += NormalizeVector2(particles[i].direction).y * particles[i].speed;
particles[i].lifeTimer -= GetFrameTime();
if (particles[i].lifeTimer <= 0)
particles.erase(particles.begin() + i);
}

player.pos = lerp(player.pos, points[player.destIndex], timer * player.speed);

if (player.pos.near(points[player.destIndex], player.speed))
{
player.destIndex++;
timer = 0;
}
if (player.destIndex == points.size())
player.destIndex = 0;

if (IsKeyDown(KEY_P))
{
player.health -= 1;
}
if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
{
points.push_back({(float)GetMouseX(), (float)GetMouseY() });
}

// Draw
BeginDrawing();
ClearBackground(DARKGRAY);

for (size_t i = 0; i < points.size(); i++)
DrawTexture(pointTex, points[i].x - pointTex.width / 2, points[i].y - pointTex.height / 2, WHITE);

float maxWidth = screenWidth - 64;
DrawRectangle(32, screenHeight - 64, maxWidth, 32, { 180, 0, 0, 255 });
DrawRectangle(32, screenHeight - 64, lerp(0.0f, 1.0f, player.health / player.maxHealth) * maxWidth, 32, { 255, 0, 0, 255 });

for (size_t i = 0; i < particles.size(); i++)
DrawTexture(particles[i].tex, particles[i].position.x, particles[i].position.y, { 255, 255, 255, (unsigned char)(255 * particles[i].lifeTimer) });

DrawTexture(player.tex, player.pos.x - player.tex.width / 2, player.pos.y - player.tex.height / 2, WHITE);
DrawText("Right Click to add more waypoints!", 140, 16, 20, WHITE);

EndDrawing();
}

CloseWindow();
}
//-----------------------------------------------------------------------
// BEZIER CURVES AND SPLINES

int screenWidth = 1000;
int screenHeight = 1000;

InitWindow(screenWidth, screenHeight, "CDDS Exercises");

SetTargetFPS(60);

vector<Point> anchors;
anchors.push_back({ { 100, 100, 16, 16 } });
anchors.push_back({ { 200, 100, 16, 16 } });
anchors.push_back({ { 200, 200, 16, 16 } });
anchors.push_back({ { 300, 200, 16, 16 } });

Texture2D anchorTex = LoadTexture("Assets/anchor.png");
Texture2D pointTex = LoadTexture("Assets/point.png");
Texture2D followerTex = LoadTexture("Assets/lineFollower.png");

float interval = 0.01f;
float timer = 0;
float speed = 1.0f;

// Main game loop
while (!WindowShouldClose())    // Detect window close button or ESC key
{
// Update

for (size_t i = 0; i < anchors.size(); i++)
{
	if (IsMouseButtonPressed(0) && anchors[i].CheckBounds())
		anchors[i].grabbed = true;
	if (IsMouseButtonUp(0) && anchors[i].CheckBounds())
		anchors[i].grabbed = false;

	if (anchors[i].grabbed)
	{
		anchors[i].rec.x = GetMouseX() - anchors[i].rec.width / 2;
		anchors[i].rec.y = GetMouseY() - anchors[i].rec.height / 2;
	}
}

// Draw

BeginDrawing();

ClearBackground(BLACK);

for (size_t i = 0; i < anchors.size(); i++)
	DrawTexture(anchorTex, anchors[i].rec.x, anchors[i].rec.y, WHITE);

vec2 pos0 = { anchors[0].rec.x + anchors[0].rec.width / 2, anchors[0].rec.y + anchors[0].rec.height / 2 };
vec2 pos1 = { anchors[1].rec.x + anchors[1].rec.width / 2, anchors[1].rec.y + anchors[1].rec.height / 2 };
vec2 pos2 = { anchors[2].rec.x + anchors[2].rec.width / 2, anchors[2].rec.y + anchors[2].rec.height / 2 };
vec2 pos3 = { anchors[3].rec.x + anchors[3].rec.width / 2, anchors[3].rec.y + anchors[3].rec.height / 2 };

timer += GetFrameTime() * speed;
if (timer >= 1)
timer = 0;

for (float i = 0; i < 1; i += interval)
{
	vec2 posA = cubicBezier(pos0, pos1, pos2, pos3, i);
	vec2 posB = cubicBezier(pos0, pos1, pos2, pos3, i - interval);
	if (i > 0)
		DrawLineEx({ posA.x, posA.y }, { posB.x, posB.y }, 1, RED);
	//DrawTextureEx(followerTex, { posA.x, posA.y }, angleFromVector(posA.x - posB.x, posA.y - posB.y) + 270, 1, WHITE);
	//DrawTexture(pointTex, pos.x, pos.y, WHITE);
}
vec2 posA = cubicBezier(pos0, pos1, pos2, pos3, timer);
vec2 posB = cubicBezier(pos0, pos1, pos2, pos3, timer + interval);
DrawTextureEx(followerTex, { posA.x + followerTex.width / 2, posA.y - followerTex.height / 2 }, angleFromVector(posA.x - posB.x, posA.y - posB.y) + 90, 1, WHITE);

EndDrawing();
	}

	CloseWindow();

*/
//---------------------------------------------------------------
//RANDOM NUMBER GENERATION
// Initialization
/*
int screenWidth = 800;
int screenHeight = 800;

InitWindow(screenWidth, screenHeight, "no");

SetTargetFPS(60);

struct Wanderer
{
	Texture2D tex;
	Vector2 position;
	Vector2 direction;
};

Texture2D enemyTex = LoadTexture("Assets/ball.png");

Wanderer enemy{ enemyTex,{ 200,200 },{ 0,0 } };
RandomGenerator gen;

float timer = 0;
float time = 0.5f;
float speed = 5;

// Main game loop
while (!WindowShouldClose())    // Detect window close button or ESC key
{
	// Update
	timer += GetFrameTime();
	if (timer >= time)
	{
		timer = 0;
		if (enemy.direction.x > -1)
			enemy.direction.x += gen.randDecimal(-speed, 0.0f, 1);
		if (enemy.direction.x < 1)
			enemy.direction.x += gen.randDecimal(0.0f, speed, 1);
		if (enemy.direction.y > -1)
			enemy.direction.y += gen.randDecimal(-speed, 0.0f, 1);
		if (enemy.direction.y < 1)
			enemy.direction.y += gen.randDecimal(0.0f, speed, 1);
	}

	if (enemy.position.x < -16)
		enemy.position.x = screenWidth;
	if (enemy.position.x > screenWidth)
		enemy.position.x = -16;
	if (enemy.position.y < 0)
		enemy.position.y = screenHeight;
	if (enemy.position.y > screenHeight)
		enemy.position.y = -enemyTex.height;

	enemy.position.x += enemy.direction.x;
	enemy.position.y += enemy.direction.y;

	// Draw
	BeginDrawing();

	ClearBackground(BLACK);

	DrawTexture(enemyTex, enemy.position.x, enemy.position.y, WHITE);

	EndDrawing();
}

CloseWindow();

return 0;
*/