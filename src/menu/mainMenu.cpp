#include "mainMenu.h"
#include "button.h"

#include "programManager.h"

namespace MoonPatrol {
	namespace MainMenu {

		// Pivate
		Buttons::Button buttonPlay;
		Buttons::Button buttonCredits;
		Buttons::Button buttonQuit;

		void initButtons();

		void draw();

		// --

		void initButtons() {
			Buttons::init(buttonPlay,
			(GetScreenWidth() * .5f),
			(GetScreenHeight() * .5f),
			180,
			60,
			"Play");
			Buttons::center(buttonPlay);

			Buttons::init(buttonCredits,
			(GetScreenWidth() * .5f),
			(GetScreenHeight() * .5f + 80),
			160,
			60,
			"Credits");
			Buttons::center(buttonCredits);

			Buttons::init(buttonQuit,
			(GetScreenWidth() * .5f),
			(GetScreenHeight() * .5f + 160),
			110,
			60,
			"Quit");
			Buttons::center(buttonQuit);
		}

		void draw() {
			BeginDrawing();

				ClearBackground(BLACK);

				Buttons::draw(buttonPlay);
				Buttons::draw(buttonCredits);
				Buttons::draw(buttonQuit);

				HideCursor();
				DrawCircle(GetMouseX(), GetMouseY(), 5, RED);

				DrawText("Menu", 0, 0, 120, WHITE);

			EndDrawing();
		}

		// Public
		void update() {
			if (Buttons::update(buttonPlay, GetMousePosition())) Program::setScreen(Program::Screen::GAME);
			if (Buttons::update(buttonCredits, GetMousePosition())) Program::setScreen(Program::Screen::CREDITS);
			if (Buttons::update(buttonQuit, GetMousePosition())) Program::close();

			draw();
		}

		void init() {
			initButtons();
		}
	}
}