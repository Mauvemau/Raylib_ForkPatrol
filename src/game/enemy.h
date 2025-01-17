#pragma once

#include "weapon.h"

namespace MoonPatrol {
	namespace Enemies {
		struct Enemy {
			float x;
			float y;
			float yCenter; // Centro del movimiento sinusoidal en y.
			int lives;
			float hitRadius;
			float speed;
			int direction;
			Weapons::Weapon weapon;
		};

		Enemy create();

		void drawHeader(Enemy enemy, const char* text);

		void draw(Enemy enemy);
		void update(Enemy& enemy);
		void init(Enemy& enemy, float yCenter, int lives, float hitRadius, float speed, int direction, Weapons::Weapon weapon);
	}
}