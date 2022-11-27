#include "player.h"

#include <iostream>

#include "game.h"
#include "collision_manager.h"
#include "asset_manager.h"
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
			player.lives = 0;
			player.color = RAYWHITE;
			InitVehicleWeapons(player.weapons);
			return player;
		}

		int getLives(Player player) {
			return player.lives;
		}

		void setLives(Player& player, int value) {
			player.lives = value;
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

			float bodyY = Game::getFloorAltitude(player.x + (player.width * .5f)) - (player.height * 1.2f);
			if ((player.y + player.height) < Game::getFloorAltitude()) bodyY = player.y;

			float maxSeparation = player.height * .2f;

			float wheelRadius = player.height * .25f;
			float frontWheelX = player.x + (player.width * .88f);
			float frontWheelY = Game::getFloorAltitude(frontWheelX) - wheelRadius;
			if (frontWheelY - (bodyY + player.height) > maxSeparation) frontWheelY = (bodyY + player.height) + maxSeparation;
			float backWheelX = player.x + (player.width * .2f);
			float backWheelY = Game::getFloorAltitude(backWheelX) - wheelRadius;
			if (backWheelY - (bodyY + player.height) > maxSeparation) backWheelY = (bodyY + player.height) + maxSeparation;

			Assets::DrawSprite(Assets::Sprite::JEEP_BODY_SILHOUETTE, { player.x - 3, bodyY - 3 }, { player.width + 6, player.height + 6 }, { 0, 0 }, 0, player.color);
			Assets::DrawSprite(Assets::Sprite::JEEP_BODY, { player.x, bodyY }, { player.width, player.height }, { 0, 0 }, 0, WHITE);
			Assets::DrawSprite(Assets::Sprite::JEEP_WHEEL, { frontWheelX, frontWheelY }, { wheelRadius * 2, wheelRadius * 2 }, { wheelRadius, wheelRadius }, 0, WHITE);
			Assets::DrawSprite(Assets::Sprite::JEEP_WHEEL, { backWheelX, backWheelY }, { wheelRadius * 2, wheelRadius * 2 }, { wheelRadius, wheelRadius }, 0, WHITE);

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

		void init(Player& player, float x, float y, float width, float height, float speed, float gravity, float jumpForce, int lives, Color color) {
			player = create();
			player.x = x;
			player.y = y;
			player.width = width;
			player.height = height;
			player.y -= height;
			player.speed = speed;
			player.gravity = gravity;
			player.jumpForce = jumpForce;
			player.lives = lives;
			player.color = color;
			player.weapons[0] = Weapons::createWeaponFromTemplate(Weapons::Types::GUN);
		}
	}
}