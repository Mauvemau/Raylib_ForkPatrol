#pragma once

#include "raylib.h"

#include "weapon.h"

namespace MoonPatrol {
	static const int amountWeapons = 6;
	namespace Players {
		struct Player {
			float x;
			float y;
			float width;
			float height;
			float speed;
			float verticalVelocity;
			float gravity;
			float jumpForce;
			int lives;
			Color color;
			Weapons::Weapon weapons[amountWeapons];
		};

		Player create();

		int getLives(Player player);

		void setLives(Player& player, int value);

		void drawHeader(Player player, const char* text);

		void shoot(Player& player);
		void jump(Player& player);
		void move(Player& player, int direction);

		void draw(Player player);
		void update(Player& player);
		void init(Player& player, float x, float y, float width, float height, float speed, float gravity, float jumpForce, int lives, Color color);
	}
}