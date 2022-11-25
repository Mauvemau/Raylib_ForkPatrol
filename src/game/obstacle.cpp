#include "obstacle.h"

extern float screenWidth;
extern float screenHeight;

Obstacle obstacle;

void obstacleCollisionWall()
{
	// Collision logic: player vs walls
	if (obstacle.x < 0 -(obstacle.radius)) obstacle.x = static_cast<int>(screenWidth) - obstacle.radius;
};