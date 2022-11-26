#include "gameOverMenu.h"
#include "button.h"

#include "game/game.h"

#include "programManager.h"
#include "utils.h"

#include "raylib.h"

namespace MoonPatrol {
	namespace GameOverMenu {

		// Private

		Buttons::Button restartButton;
		Buttons::Button returnButton;

		void initButtons();
		void draw();

		// --

		void initButtons() {
			Buttons::init(restartButton,
				(GetScreenWidth() * .5f),
				(GetScreenHeight() * .6f),
				(GetScreenWidth() * .325f),
				(GetScreenHeight() * .1f),
				"Play Again");
			Buttons::center(restartButton);

			Buttons::init(returnButton,
				(GetScreenWidth() * .5f),
				(GetScreenHeight() * .6f + GetScreenHeight() * .125f),
				(GetScreenWidth() * .325f),
				(GetScreenHeight() * .1f),
				"Return to Menu");
			Buttons::center(returnButton);
		}

		void draw() {
			BeginDrawing();
				ClearBackground(BLACK);

				Utils::DrawCenteredText("GAME OVER",
					static_cast<int>(GetScreenWidth() * .5f), static_cast<int>(GetScreenHeight() * .25f),
					static_cast<int>(GetScreenHeight() * .075f), RED);

				Buttons::draw(restartButton);
				Buttons::draw(returnButton);

				DrawCircle(GetMouseX(), GetMouseY(), 5, RED);

			EndDrawing();
		}

		// Public

		void update() {
			if (Buttons::update(restartButton, GetMousePosition())) Program::setScreen(Program::Screen::GAME);
			if (Buttons::update(returnButton, GetMousePosition())) Program::setScreen(Program::Screen::MAINMENU);

			draw();
		}

		void init() {
			initButtons();
		}
	}
}