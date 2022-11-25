#include "player.h"
#include "game.h"

#include <iostream>

using namespace std;

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
			player.verticalVelocity = 0;
			player.gravity = 0;
			player.jumpForce = 0;
			player.color = RAYWHITE;
			return player;
		}

		void jump(Player& player) {
			if (player.y + player.height >= Game::getFloorAltitude()) {
				player.y -= 1;
				player.verticalVelocity = -player.jumpForce;
			}
		}

		void move(Player& player, int direction) {
			player.x += direction * (player.speed * GetFrameTime());
		}

		void draw(Player player) {
			DrawRectangle(static_cast<int>(player.x), static_cast<int>(player.y),
				static_cast<int>(player.width), static_cast<int>(player.height), player.color);
		}

		void update(Player& player) {
			if ((player.y + player.height) < Game::getFloorAltitude()) {
				player.verticalVelocity += player.gravity * GetFrameTime();
			}
			else {
				player.verticalVelocity = 0;
				player.y = Game::getFloorAltitude() - player.height;
			}
			player.y += player.verticalVelocity * GetFrameTime();
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