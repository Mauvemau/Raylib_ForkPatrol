#include "obstacle.h"

extern float screenWidth;
extern float screenHeight;

Obstacle obstacle;

void obstacleCollisionWall()
{
	// Collision logic: player vs walls
	if (obstacle.x < 0 -(obstacle.radius)) obstacle.x = screenWidth - obstacle.radius;
};