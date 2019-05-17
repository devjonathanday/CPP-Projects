#include"DialFace.h"
#include"raylib.h"

void DialFace::DrawFace()
{
	DrawCircleLines(position.x, position.y, radius, WHITE);
	DrawLine(radius, radius, position.x + (sin(hours * 30 * PI / 180)) * (radius), position.y + (-cos(hours * 30 * PI / 180)) * (radius), DARKGRAY);
	DrawLine(radius, radius, position.x + (sin(minutes * 6 * PI / 180)) * (radius), position.y + (-cos(minutes * 6 * PI / 180)) * (radius), GRAY);
	DrawLine(radius, radius, position.x + (sin(seconds * 6 * PI / 180)) * (radius), position.y + (-cos(seconds * 6 * PI / 180)) * (radius), RED);
};
void DialFace::Tick()
{
	seconds += 1; //Replace 1 with GetFrameTime() for an actual clock.
	if (seconds >= 60)
	{
		seconds -= 60;
		minutes++;
		if (minutes >= 60)
		{
			minutes -= 60;
			hours++;
			if (hours >= 13)
			{
				hours -= 12;
			}
		}
	}
}
float DialFace::DegToRad(float degrees)
{
	return degrees * (PI / 180);
}
DialFace::DialFace() {};
DialFace::~DialFace() {};