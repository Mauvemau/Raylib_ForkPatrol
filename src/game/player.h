#pragma once

#include "weapon.h"

#include "raylib.h"

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
			Color color;
			Weapons::Weapon weapons[amountWeapons];
		};

		Player create();

		void drawHeader(Player player, const char* text);

		void shoot(Player& player);
		void jump(Player& player);
		void move(Player& player, int direction);

		void draw(Player player);
		void update(Player& player);
		void init(Player& player, float x, float y, float width, float height, float speed, float gravity, float jumpForce, Color color);
	}
}