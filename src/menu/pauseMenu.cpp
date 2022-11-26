#include "pauseMenu.h"
#include "button.h"

#include "game/game.h"

#include "programManager.h"
#include "utils.h"

namespace MoonPatrol {
	namespace PauseMenu {
		// Private

		Buttons::Button resumeButton;
		Buttons::Button restartButton;
		Buttons::Button returnButton;

		void initButtons();

		// --

		void initButtons() {
			Buttons::init(resumeButton,
				(GetScreenWidth() * .5f),
				(GetScreenHeight() * .5f),
				(GetScreenWidth() * .325f),
				(GetScreenHeight() * .1f),
				"Resume");
			Buttons::center(resumeButton);

			Buttons::init(restartButton,
				(GetScreenWidth() * .5f),
				(GetScreenHeight() * .5f + GetScreenHeight() * .125f),
				(GetScreenWidth() * .325f),
				(GetScreenHeight() * .1f),
				"Restart");
			Buttons::center(restartButton);

			Buttons::init(returnButton,
				(GetScreenWidth() * .5f),
				(GetScreenHeight() * .5f + GetScreenHeight() * .25f),
				(GetScreenWidth() * .325f),
				(GetScreenHeight() * .1f),
				"Return to Menu");
			Buttons::center(returnButton);
		}

		// Public

		void draw() {
			DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, .5));

			Utils::DrawCenteredText("GAME PAUSED",
				static_cast<int>(GetScreenWidth() * .5f), static_cast<int>(GetScreenHeight() * .25f),
				static_cast<int>(GetScreenHeight() * .1f), RAYWHITE);

			Buttons::draw(resumeButton);
			Buttons::draw(restartButton);
			Buttons::draw(returnButton);

			HideCursor();
			DrawCircle(GetMouseX(), GetMouseY(), 5, RED);
		}

		void update() {
			if (Buttons::update(resumeButton, GetMousePosition())) Game::setPaused(false);
			if (Buttons::update(restartButton, GetMousePosition())) Program::setScreen(Program::Screen::GAME);
			if (Buttons::update(returnButton, GetMousePosition())) Program::setScreen(Program::Screen::MAINMENU);
		}

		void init() {
			initButtons();
		}
	}
}