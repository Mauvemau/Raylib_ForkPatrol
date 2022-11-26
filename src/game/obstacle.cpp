#include "obstacle.h"

#include "raylib.h"

#include "game.h"

namespace MoonPatrol {
	namespace Obstacles {

		// Private

		void move(Obstacle& obstacle, int direction);

		// --

		void move(Obstacle& obstacle, int direction) {
			obstacle.x += direction * (obstacle.speed * GetFrameTime());
		}

		// Public

		Obstacle create() {
			Obstacle obstacle;
			obstacle.x = 0;
			obstacle.y = 0;
			obstacle.width = 0;
			obstacle.height = 0;
			obstacle.speed = 0;
			obstacle.dodged = false;
			return obstacle;
		}

		void handleDodgeLogic(Obstacle& obstacle) {
			if (!obstacle.dodged) {
				obstacle.dodged = true;
				Game::setScore(Game::getScore() + 10);
			}
		}

		void draw(Obstacle obstacle) {
			DrawRectangle(static_cast<int>(obstacle.x), static_cast<int>(obstacle.y),
				static_cast<int>(obstacle.width), static_cast<int>(obstacle.height), GREEN);
		}

		void update(Obstacle& obstacle) {
			move(obstacle, -1);
			if (obstacle.x < (-obstacle.width)) {
				obstacle.x = static_cast<float>((GetScreenWidth() * 1) + obstacle.width);
				obstacle.dodged = false;
			}
		}

		void init(Obstacle& obstacle, float y, float width, float height, float speed) {
			obstacle = create();
			obstacle.x = GetScreenWidth() + width;
			obstacle.y = y - height;
			obstacle.width = width;
			obstacle.height = height;
			obstacle.speed = speed;
			obstacle.dodged = false;
		}

	}
}