#include "obstacle.h"

Obstacle obstacle;

void obstacleCollisionWall()
{
	// Collision logic: player vs walls
	if (obstacle.x < 0 -(obstacle.radius)) obstacle.x = static_cast<int>(GetScreenWidth()) - obstacle.radius;
};