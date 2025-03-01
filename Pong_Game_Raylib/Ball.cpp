#include "Ball.h"

#include <raylib.h>

void Ball::Draw()
{
	DrawCircle(x, y, radius, GREEN);
}

void Ball::Update()
{
	x += speed_x;
	y += speed_y;

	if (y + radius >= GetScreenHeight() || y - radius <= 0) {
		speed_y *= -1;
	}
	if (x + radius >= GetScreenWidth()) {
		cpuScore++;
		ResetBall();
	}
	if (x - radius <= 0) {
		playerScore++;
		ResetBall();
	}
}

void Ball::ResetBall()
{
	x = GetScreenWidth() / 2;
	y = GetScreenHeight() / 2;
	int speed_choice[2] = { -1,1 };
	speed_x *= speed_choice[(GetRandomValue(0, 1))];
	speed_y *= speed_choice[(GetRandomValue(0, 1))];
}
