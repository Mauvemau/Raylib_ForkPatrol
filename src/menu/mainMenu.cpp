#include "mainMenu.h"
#include "button.h"

#include "programManager.h"
#include "utils.h"

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
			(GetScreenHeight() * .5f + 260),
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

				Utils::DrawCenteredText("Fork Patrol", static_cast<int>(GetScreenWidth() * .5f), static_cast<int>(GetScreenHeight() * .25f), 120, SKYBLUE);

				const char* versionText = TextFormat("v%s", Program::getVersion());
				int versionFontSize = static_cast<int>(GetScreenHeight() * .05f);
				int versionTextWide = MeasureText(versionText, versionFontSize);
				DrawText(versionText,
					static_cast<int>((GetScreenWidth() * .99) - versionTextWide),
					static_cast<int>((GetScreenHeight() * .99) - versionFontSize),
					versionFontSize, WHITE);

				DrawCircle(GetMouseX(), GetMouseY(), 5, RED);

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