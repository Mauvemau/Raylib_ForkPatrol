#include "player.h"

#include <iostream>

#include "game.h"
#include "collision_manager.h"
#include "utils.h"

using namespace std;

namespace MoonPatrol {
	namespace Players {
		// Private

		void InitVehicleWeapons(Weapons::Weapon weapons[]);

		// --

		void InitVehicleWeapons(Weapons::Weapon weapons[]) {
			for (int i = 0; i < amountWeapons; i++) {
				weapons[i] = Weapons::create();
			}
		}
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
			InitVehicleWeapons(player.weapons);
			return player;
		}

		void drawHeader(Player player, const char* text) {
			Utils::DrawCenteredText(text, 
				static_cast<int>(player.x + (player.width * .5f)),
				static_cast<int>(player.y - (player.height * .5f)),
				static_cast<int>(GetScreenHeight() * .025f), 
				player.color);
		}

		void shoot(Player& player) {
			for (int i = 0; i < amountWeapons; i++) {
				Weapons::shoot(player.weapons[i], player.x + (player.width * .5f), player.y + (player.height * .5f), Utils::DegreesToRadians(-90.0f), player.color);
			}
		}

		void jump(Player& player) {
			if (player.y + player.height >= Game::getFloorAltitude()) {
				player.y -= 1;
				player.verticalVelocity = -player.jumpForce;
			}
		}

		void move(Player& player, int direction) {
			player.x += direction * (player.speed * GetFrameTime());
			if (Collisions::playerWall(player)) {
				if (player.x < (GetScreenWidth() * .5f)) {
					player.x = 0;
				}
				else {
					player.x = static_cast<float>(GetScreenWidth() - player.width);
				}
			}
		}

		void draw(Player player) {

			float bodyY = Game::getFloorAltitude(player.x + (player.width * .5f)) - (player.height * 1.15f);
			if ((player.y + player.height) < Game::getFloorAltitude()) bodyY = player.y;

			float maxSeparation = player.height * .25f;

			float wheelRadius = player.height * .2f;
			float frontWheelX = player.x + (player.width * .8f);
			float frontWheelY = Game::getFloorAltitude(frontWheelX) - wheelRadius;
			if (frontWheelY - (bodyY + player.height) > maxSeparation) frontWheelY = (bodyY + player.height) + maxSeparation;
			float backWheelX = player.x + (player.width * .2f);
			float backWheelY = Game::getFloorAltitude(backWheelX) - wheelRadius;
			if (backWheelY - (bodyY + player.height) > maxSeparation) backWheelY = (bodyY + player.height) + maxSeparation;

			DrawRectangle(static_cast<int>(player.x), static_cast<int>(bodyY),
				static_cast<int>(player.width), static_cast<int>(player.height), player.color);
			DrawCircle(static_cast<int>(frontWheelX), static_cast<int>(frontWheelY), wheelRadius, DARKGRAY);
			DrawCircle(static_cast<int>(backWheelX), static_cast<int>(backWheelY), wheelRadius, DARKGRAY);

#ifdef _DEBUG
			DrawRectangle(static_cast<int>(player.x), static_cast<int>(player.y),
				static_cast<int>(player.width), static_cast<int>(player.height), Fade(GREEN, .25f));
#endif // _DEBUG
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
			player.weapons[0] = Weapons::createWeaponFromTemplate(Weapons::Types::GUN);
		}
	}
}