#include "collisionManager.h"

namespace MoonPatrol {
	namespace Collisions {

		// Private

		// --

		// Public
		bool rectangleRectangleCollision(float rec1X, float rec1Y, float rec1Width, float rec1Height, float rec2X, float rec2Y, float rec2Width, float rec2Height) {
			return (rec1X < rec2X + rec2Width &&
					rec1X + rec1Width > rec2X &&
					rec1Y < rec2Y + rec2Height &&
					rec1Y + rec1Height > rec2Y);
		}

		bool pointRectCollision(float pointX, float pointY, float recX, float recY, float recWidth, float recHeight) {
			return (pointX > recX && pointX < (recX + recWidth) && pointY > recY && pointY < (recY + recHeight));
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