#include <iostream>
#include <raylib.h>

#include "Ball.h"
#include "Player.h"
#include "Cpu.h"


int main() {
	//Scree size.
	const int width = 1600;
	const int height = 900;
	//Frame per second.
	SetTargetFPS(60);

	InitWindow(width, height, "PONG GAME WITH RAYLIB");

	//Ball class instance.
	Ball ball;
	ball.radius = 20;
	ball.x = width / 2;
	ball.y = height / 2;
	ball.speed_x = 9;
	ball.speed_y = 9;

	//Player class instance.
	Player player;
	player.width = 25;
	player.height = 120;
	player.speed = 6;
	player.x = width - player.width - 10;
	player.y = height / 2 - player.height / 2;

	//Cpu class instance.
	Cpu cpu;
	cpu.width = 25;
	cpu.height = 120;
	cpu.speed = 6;
	cpu.x = 10;
	cpu.y = height / 2 - cpu.height / 2;

	//Game main loop.
	while (WindowShouldClose() == false) {
		BeginDrawing();
		
		ball.Update();
		player.Update();
		cpu.Update(ball.y);

		//Collisions.
		if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y}, ball.radius, Rectangle{ player.x, player.y, player.width, player.height })) {
			ball.speed_x *= -1;
		}
		if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.radius, Rectangle{ cpu.x, cpu.y, cpu.width, cpu.height })) {
			ball.speed_x *= -1;
		}

		ClearBackground(BLUE);
		//Draw a line in the middle.
		DrawLine(width/2,0,width/2,height, BLACK);
		//Draw a circle in the middle of the screen.
		ball.Draw();
		//Draw a rectangle on the left side controlled by cpu.
		cpu.Draw();
		//Draw a rectangle on the right side controlled by player.
		player.Draw();
		//Draw player and cpu score.
		DrawText(TextFormat("%i", ball.cpuScore), width / 4 - 20, 20, 80, BLACK);
		DrawText(TextFormat("%i", ball.playerScore), 3 * width / 4 - 20, 20, 80, BLACK);

		EndDrawing();
	}

	CloseWindow();
	

	return 0;
}