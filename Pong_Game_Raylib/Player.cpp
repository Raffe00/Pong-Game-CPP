#include "Player.h"

#include <raylib.h>

void Player::Draw()
{
	DrawRectangle(x, y, width, height, YELLOW);
}

void Player::Update()
{
	if (IsKeyDown(KEY_UP)) {
		y = y - speed;
	}
	if (IsKeyDown(KEY_DOWN)) {
		y = y + speed;
	}
	LimitMovement();
}

void Player::LimitMovement()
{
	if (y <= 0) {
		y = 0;
	}
	if (y + height >= GetScreenHeight()) {
		y = GetScreenHeight() - height;
	}
}
