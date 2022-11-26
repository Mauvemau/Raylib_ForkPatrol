#include "inputManager.h"

#include "programManager.h"
#include "game/game.h"

namespace MoonPatrol {
	namespace Input {
		// Public
		void updatePlayerTwo(Players::Player& player) {
			if (IsKeyDown(KEY_LEFT)) {
				Players::move(player, -1);
			}
			else if (IsKeyDown(KEY_RIGHT)) {
				Players::move(player, +1);
			}
			if (IsKeyPressed(KEY_UP)) {
				Players::jump(player);
			}
			if (IsKeyDown(KEY_DOWN)) {
				Players::shoot(player);
			}
		}

		void updatePlayerOne(Players::Player& player) {
			if (IsKeyDown(KEY_A)) {
				Players::move(player, -1);
			}
			else if (IsKeyDown(KEY_D)) {
				Players::move(player, +1);
			}
			if (IsKeyPressed(KEY_W)) {
				Players::jump(player);
			}
			if (IsKeyDown(KEY_S)) {
				Players::shoot(player);
			}
		}

		void updateGeneral() {
			if (IsKeyPressed(KEY_ESCAPE)) {
				Game::setPaused(!Game::getIsPaused());
			}
		}
	}
}