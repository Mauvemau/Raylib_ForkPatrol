#pragma once

#include "raylib.h"

#include "game/player.h"
#include "game/obstacle.h"
#include "game/bullet.h"
#include "game/enemy.h"

namespace MoonPatrol {
	namespace Collisions {
		Vector2 LineLineIntersection(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
		bool rectangleRectangleCollision(float rec1X, float rec1Y, float rec1Width, float rec1Height, float rec2X, float rec2Y, float rec2Width, float rec2Height);
		bool CircleCircleCollision(float cir1X, float cir1Y, float cir1R, float cir2X, float cir2Y, float cir2R);
		bool pointRectCollision(float pointX, float pointY, float recX, float recY, float recWidth, float recHeight);
		bool bulletEnemy(Bullets::Bullet bullet, Enemies::Enemy enemy);
		bool enemyWall(Enemies::Enemy enemy);
		bool bulletWall(Bullets::Bullet bullet);
		bool playerObstacle(Players::Player player, Obstacles::Obstacle obstacle);
		bool playerWall(Players::Player player);
	}
}