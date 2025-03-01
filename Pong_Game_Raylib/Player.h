#pragma once
class Player
{
public:
	float x, y;
	float width, height;
	int speed;
	void Draw();
	void Update();
protected:
	void LimitMovement();
};

