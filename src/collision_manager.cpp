#include "collision_manager.h"

#include <iostream>

namespace MoonPatrol {
	namespace Collisions {

		// Private

		// --

		// Public
		Vector2 LineLineIntersection(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
			Vector2 intersection;

			intersection.x =
				(((x1 * y2 - y1 * x2) * (x3 - x4)) - ((x1 - x2) * (x3 * y4 - y3 * x4))) /
				(((x1 - x2) * (y3 - y4)) - ((y1 - y2) * (x3 - x4)));

			intersection.y =
				(((x1 * y2 - y1 * x2) * (y3 - y4)) - ((y1 - y2) * (x3 * y4 - y3 * x4))) /
				(((x1 - x2) * (y3 - y4)) - ((y1 - y2) * (x3 - x4)));

			return intersection;
		}

		bool rectangleRectangleCollision(float rec1X, float rec1Y, float rec1Width, float rec1Height, float rec2X, float rec2Y, float rec2Width, float rec2Height) {
			return (rec1X < rec2X + rec2Width &&
					rec1X + rec1Width > rec2X &&
					rec1Y < rec2Y + rec2Height &&
					rec1Y + rec1Height > rec2Y);
		}

		bool CircleCircleCollision(float cir1X, float cir1Y, float cir1R, float cir2X, float cir2Y, float cir2R) {
			float distX = cir1X - cir2X;
			float distY = cir1Y - cir2Y;
			float dist = sqrtf((distX * distX) + (distY * distY));

			return (dist <= (cir1R + cir2R));
		}

		bool pointRectCollision(float pointX, float pointY, float recX, float recY, float recWidth, float recHeight) {
			return (pointX > recX && pointX < (recX + recWidth) && pointY > recY && pointY < (recY + recHeight));
		}

		bool bulletEnemy(Bullets::Bullet bullet, Enemies::Enemy enemy) {
			return CircleCircleCollision(bullet.x, bullet.y, bullet.radius, enemy.x, enemy.y, enemy.hitRadius);
		}

		bool enemyWall(Enemies::Enemy enemy) {
			return (enemy.x < 0 || enemy.x > GetScreenWidth());
		}

		bool bulletWall(Bullets::Bullet bullet) {
			return (bullet.x - bullet.radius <= 0 || bullet.y - bullet.radius <= 0 ||
				bullet.x + bullet.radius >= GetScreenWidth() || bullet.y + bullet.radius >= GetScreenHeight());
		}

		bool playerObstacle(Players::Player player, Obstacles::Obstacle obstacle) {
			return (rectangleRectangleCollision(player.x, player.y, player.width, player.height, obstacle.x, obstacle.y, obstacle.width, obstacle.height));
		}

		bool playerWall(Players::Player player) {
			return (player.x < 0 || (player.x + player.width) > GetScreenWidth());
		}
	}
}