#pragma once
#include "raylib.h"

class Obstacle
{
	//Texture2D sprite;
public:

	int x = 0;
	int y = 0;
	int radius = 0;
};

void obstacleCollisionWall();