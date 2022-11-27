#include "enemy.h"

#include <iostream>

#include "collision_manager.h"
#include "asset_manager.h"
#include "utils.h"

namespace MoonPatrol {
	namespace Enemies {

		// Private

		const int amplitude = 50;

		// --

		// Public

		Enemy create() {
			Enemy enemy;
			enemy.x = 0;
			enemy.y = 0;
			enemy.yCenter = 0;
			enemy.lives = 0;
			enemy.hitRadius = 0;
			enemy.speed = 0;
			enemy.direction = 0;
			enemy.weapon = Weapons::create();
			return enemy;
		}

		void drawHeader(Enemy enemy, const char* text) {
			Utils::DrawCenteredText(text,
				static_cast<int>(enemy.x),
				static_cast<int>(enemy.y - (enemy.hitRadius * 2)),
				static_cast<int>(GetScreenHeight() * .03f),
				GREEN);
		}

		void draw(Enemy enemy) {
#ifdef _DEBUG
			DrawCircle(static_cast<int>(enemy.x), static_cast<int>(enemy.y), enemy.hitRadius, Fade(GREEN, .25f));
#endif // _DEBUG
			Assets::DrawSprite(Assets::Sprite::DRONE, { enemy.x, enemy.y }, { enemy.hitRadius * 2, enemy.hitRadius * 2}, { enemy.hitRadius, enemy.hitRadius }, 0, WHITE);
		}

		void update(Enemy& enemy) {
			enemy.x += (enemy.speed * GetFrameTime()) * enemy.direction;
			// position.y = (amplitude * sin(position.x * speed.y * PI)) + center;
			enemy.y = (amplitude * sinf(enemy.x * .01f * static_cast<float>(Utils::m_pi))) + enemy.yCenter;
			if (Collisions::enemyWall(enemy)) {
				if (enemy.x < GetScreenWidth() * .5f) {
					enemy.x = static_cast<float>(GetScreenWidth());
				}
				else {
					enemy.x = 0;
				}
			}
		}

		void init(Enemy& enemy, float yCenter, int lives, float hitRadius, float speed, int direction, Weapons::Weapon weapon) {
			enemy = create();
			enemy.yCenter = yCenter;
			enemy.lives = lives;
			enemy.hitRadius = hitRadius;
			enemy.speed = speed;
			enemy.direction = direction;
			enemy.weapon = weapon;
		}
	}
}