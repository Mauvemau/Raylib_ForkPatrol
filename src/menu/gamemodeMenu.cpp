#include "gamemodeMenu.h"
#include "button.h"

#include "game/game.h"

#include "programManager.h"
#include "utils.h"

namespace MoonPatrol {
	namespace GamemodeMenu {

		// Private
		Buttons::Button singlePlayerButton;
		Buttons::Button multiPlayerButton;
		Buttons::Button returnButton;


		void initButtons();
		void draw();

		// --

		void initButtons() {
			Buttons::init(singlePlayerButton,
				(GetScreenWidth() * .5f),
				(GetScreenHeight() * .275f),
				(GetScreenWidth() * .325f),
				(GetScreenHeight() * .1f),
				"Singleplayer");
			Buttons::center(singlePlayerButton);

			Buttons::init(multiPlayerButton,
				(GetScreenWidth() * .5f),
				(GetScreenHeight() * .275f + GetScreenHeight() * .12f),
				(GetScreenWidth() * .325f),
				(GetScreenHeight() * .1f),
				"Multiplayer");
			Buttons::center(multiPlayerButton);

			Buttons::init(returnButton,
				(GetScreenWidth() * .5f),
				(GetScreenHeight() * .75f),
				(GetScreenWidth() * .325f),
				(GetScreenHeight() * .1f),
				"Return to Menu");
			Buttons::center(returnButton);
		}

		void draw() {
			BeginDrawing();
				ClearBackground(BLACK);

				Utils::DrawCenteredText("Select a Gamemode", static_cast<int>(GetScreenWidth() * .5f), static_cast<int>(GetScreenHeight() * .1f), 60, ORANGE);

				Buttons::draw(singlePlayerButton);
				Buttons::draw(multiPlayerButton);
				Buttons::draw(returnButton);

				DrawCircle(GetMouseX(), GetMouseY(), 5, RED);

			EndDrawing();
		}

		// Public
		void update() {
			if (Buttons::update(singlePlayerButton, GetMousePosition())) {
				Game::setGameMode(false);
				Program::setScreen(Program::Screen::GAME); 
			}
			if (Buttons::update(multiPlayerButton, GetMousePosition())) {
				Game::setGameMode(true);
				Program::setScreen(Program::Screen::GAME);
			}
			if (Buttons::update(returnButton, GetMousePosition())) Program::setScreen(Program::Screen::MAINMENU);

			draw();
		}

		void init() {
			initButtons();
		}
	}
}