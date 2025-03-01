#pragma once

class Ball
{
public:
	float x, y;
	int speed_x, speed_y;
	int radius;
	int playerScore = 0;
	int cpuScore = 0;
	void Draw();
	void Update();
	void ResetBall();
};

