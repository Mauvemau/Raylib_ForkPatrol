#include "player.h"
#include "game.h"

namespace MoonPatrol {
	namespace Players {

		// Private

		// --

		// Public

		Player create() {
			Player player;
			player.x = 0;
			player.y = 0;
			player.width = 0;
			player.height = 0;
			player.speed = 0;
			player.gravity = 0;
			player.jumpForce = 0;
			player.color = RAYWHITE;
			return player;
		}

		void jump(Player& player) {
			player.color = RED;
		}

		void move(Player& player, int direction) {
			player.x += direction * (player.speed * GetFrameTime());
		}

		void draw(Player player) {
			DrawRectangle(static_cast<int>(player.x), static_cast<int>(player.y),
				static_cast<int>(player.width), static_cast<int>(player.height), player.color);
		}

		void update(Player& player) {
			// --
		}

		void init(Player& player, float x, float y, float width, float height, float speed, float gravity, float jumpForce, Color color) {
			player = create();
			player.x = x;
			player.y = y;
			player.width = width;
			player.height = height;
			player.y -= height;
			player.speed = speed;
			player.gravity = gravity;
			player.jumpForce = jumpForce;
			player.color = color;
		}
	}
}