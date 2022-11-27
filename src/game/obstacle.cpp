#include "obstacle.h"

#include "raylib.h"

#include "game.h"
#include "asset_manager.h"
#include "utils.h"

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

		void setSpeed(Obstacle& obstacle, float value) {
			obstacle.speed = value;
		}

		void setX(Obstacle& obstacle, float xPos) {
			obstacle.x = xPos;
		}

		void drawHeader(Obstacle obstacle, const char* text) {
			Utils::DrawCenteredText(text,
				static_cast<int>(obstacle.x + (obstacle.width * .5f)),
				static_cast<int>(obstacle.y - (obstacle.height * .5f)),
				static_cast<int>(GetScreenHeight() * .03f),
				{ 40, 30, 15, 255 });
		}

		void handleDodgeLogic(Obstacle& obstacle) {
			if (!obstacle.dodged) {
				obstacle.dodged = true;
				Game::setScore(Game::getScore() + 10);
				Assets::PlayAudio(Assets::Audio::SCORE, .5f);
				Game::setObstaclesDodged(Game::getObstaclesDodged() + 1);
			}
		}

		void draw(Obstacle obstacle) {
			DrawRectangle(static_cast<int>(obstacle.x), static_cast<int>(obstacle.y),
				static_cast<int>(obstacle.width), static_cast<int>(obstacle.height), { 40, 30, 15, 255 });
		}

		void update(Obstacle& obstacle) {
			if (Game::getObstaclesDodged() == 0 || Game::getEnemiesKilled() > 0 || obstacle.dodged == true) {
				move(obstacle, -1);
				if (obstacle.x < (-obstacle.width)) {
					int aux = GetRandomValue(0, 1);
					if (aux) {
						obstacle.x = static_cast<float>((GetScreenWidth() * 1) + obstacle.width);
					}
					else {
						obstacle.x = static_cast<float>((GetScreenWidth() * 2) + obstacle.width);
					}
					obstacle.dodged = false;
				}
			}
		}

		void init(Obstacle& obstacle, float y, float width, float height, float speed) {
			obstacle = create();
			obstacle.x = GetScreenWidth() + width;
			obstacle.y = y;
			obstacle.width = width;
			obstacle.height = height;
			obstacle.speed = speed;
			obstacle.dodged = false;
		}

	}
}