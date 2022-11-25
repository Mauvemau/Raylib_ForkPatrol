#pragma once

#include "raylib.h"

namespace MoonPatrol {
	namespace Players {
		struct Player {
			float x;
			float y;
			float width;
			float height;
			float speed;
			float gravity;
			float jumpForce;
			Color color;
		};

		void move(Player& player, int direction);

		void draw(Player player);
		void update(Player& player);
		void init(Player& player, float x, float y, float width, float height, float speed, float gravity, float jumpForce, Color color);
	}
}