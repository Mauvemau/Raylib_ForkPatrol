#include "bullet.h"

#include <iostream>

#include "asset_manager.h"
#include "utils.h"

namespace MoonPatrol {
	namespace Bullets {
		// Private

		void move(Bullet& bullet);

		// --

		void move(Bullet& bullet) {
			bullet.x += bullet.speed * cosf(bullet.directionAngle) * GetFrameTime();
			bullet.y += bullet.speed * sinf(bullet.directionAngle) * GetFrameTime();
		}

		// Public

		Bullet create() {
			Bullet bullet;
			bullet.x = 0;
			bullet.y = 0;
			bullet.radius = 0;
			bullet.directionAngle = 0;
			bullet.speed = 0;
			bullet.hurtsPlayer = 0;
			bullet.color = WHITE;
			return bullet;
		}

		void draw(Bullet bullet) {
			DrawCircle(static_cast<int>(bullet.x), static_cast<int>(bullet.y), bullet.radius, bullet.color);
			DrawCircle(static_cast<int>(bullet.x), static_cast<int>(bullet.y), bullet.radius * .9f, Fade(RAYWHITE, .5f));

			Assets::DrawSprite(Assets::Sprite::BULLET_TRAIL, { bullet.x, bullet.y },
				{ static_cast<float>(bullet.radius + bullet.speed * .1), static_cast<float>(bullet.radius * 2) },
				{ static_cast<float>(bullet.radius + bullet.speed * .1), static_cast<float>(bullet.radius * 1) },
				Utils::RadiansToDegrees(bullet.directionAngle), bullet.color);
		}

		void update(Bullet& bullet) {
			move(bullet);
		}

		void init(Bullet& bullet, float x, float y, float radius, float directionAngle, float speed, bool hurtsPlayer, Color color) {
			bullet = create();
			bullet.x = x;
			bullet.y = y;
			bullet.radius = radius;
			bullet.directionAngle = directionAngle;
			bullet.speed = speed;
			bullet.hurtsPlayer = hurtsPlayer;
			bullet.color = color;
		}
	}
}