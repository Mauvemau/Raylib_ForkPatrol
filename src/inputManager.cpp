#include "inputManager.h"

#include "programManager.h"

namespace MoonPatrol {
	namespace Input {
		// Public
		void updatePlayerOne(Players::Player& player) {
			if (IsKeyDown(KEY_A)) {
				Players::move(player, -1);
			}
			else if (IsKeyDown(KEY_D)) {
				Players::move(player, +1);
			}
			if (IsKeyPressed(KEY_SPACE)) {
				Players::jump(player);
			}
			if (IsKeyDown(KEY_LEFT_CONTROL)) {

			}
			//
			if (IsKeyPressed(KEY_ESCAPE)) {
				Program::setScreen(Program::Screen::MAINMENU);
			}
		}
	}
}