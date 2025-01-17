#pragma once

#include "raylib.h"

namespace MoonPatrol {
	namespace Bullets {
		struct Bullet {
			float x;
			float y;
			float radius;
			float directionAngle;
			float speed;
			bool hurtsPlayer;
			Color color;
		};

		Bullet create();

		void draw(Bullet bullet);
		void update(Bullet& bullet);
		void init(Bullet& bullet, float x, float y, float radius, float directionAngle, float speed, bool hurtsPlayer, Color color);
	}
}