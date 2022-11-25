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
			120,
			30,
			"Play");
			Buttons::center(buttonPlay);

			Buttons::init(buttonCredits,
			(GetScreenWidth() * .5f),
			(GetScreenHeight() * .5f + 65),
			100,
			30,
			"Credits");
			Buttons::center(buttonCredits);

			Buttons::init(buttonQuit,
			(GetScreenWidth() * .5f),
			(GetScreenHeight() * .5f + 130),
			50,
			30,
			"Quit");
			Buttons::center(buttonQuit);
		}

		void draw() {
			BeginDrawing();

				ClearBackground(BLACK);

				HideCursor();
				DrawCircle(GetMouseX(), GetMouseY(), 5, RED);

				Buttons::draw(buttonPlay);
				Buttons::draw(buttonCredits);
				Buttons::draw(buttonQuit);

			EndDrawing();
		}

		// Public
		void update() {
			Buttons::update(buttonPlay, GetMousePosition());
			Buttons::update(buttonCredits, GetMousePosition());
			if(Buttons::update(buttonQuit, GetMousePosition())) Program::close();

			draw();
		}

		void init() {
			initButtons();
		}
	}
}