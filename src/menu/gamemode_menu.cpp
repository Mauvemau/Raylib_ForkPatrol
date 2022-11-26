#include "gamemode_menu.h"

#include "button.h"
#include "game/game.h"
#include "program_manager.h"
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

				Utils::DrawCenteredText("Select a Gamemode", static_cast<int>(GetScreenWidth() * .5f), static_cast<int>(GetScreenHeight() * .12f), 60, ORANGE);

				if (Buttons::getIsHovered(singlePlayerButton)) {
					Utils::DrawCenteredText("Game Controls", static_cast<int>(GetScreenWidth() * .5f), static_cast<int>(GetScreenHeight() * .48f), 35, SKYBLUE);

					Utils::DrawCenteredText("[A] [D] to move Left and Right.", static_cast<int>(GetScreenWidth() * .5f), static_cast<int>(GetScreenHeight() * .53f), 25, RAYWHITE);
					Utils::DrawCenteredText("[W] to Jump!", static_cast<int>(GetScreenWidth() * .5f), static_cast<int>(GetScreenHeight() * .58f), 25, RAYWHITE);
					Utils::DrawCenteredText("[S] to Shoot your gun.", static_cast<int>(GetScreenWidth() * .5f), static_cast<int>(GetScreenHeight() * .63f), 25, RAYWHITE);
				}
				if (Buttons::getIsHovered(multiPlayerButton)) {
					Utils::DrawCenteredText("(P1) Controls", static_cast<int>(GetScreenWidth() * .25f), static_cast<int>(GetScreenHeight() * .49f), 30, { 220, 130, 130, 255 });
					Utils::DrawCenteredText("[A] [D] to move Left and Right.", static_cast<int>(GetScreenWidth() * .25f), static_cast<int>(GetScreenHeight() * .53f), 25, RED);
					Utils::DrawCenteredText("[W] to Jump!", static_cast<int>(GetScreenWidth() * .25f), static_cast<int>(GetScreenHeight() * .58f), 25, RED);
					Utils::DrawCenteredText("[S] to Shoot your gun.", static_cast<int>(GetScreenWidth() * .25f), static_cast<int>(GetScreenHeight() * .63f), 25, RED);

					Utils::DrawCenteredText("(P2) Controls", static_cast<int>(GetScreenWidth() * .75f), static_cast<int>(GetScreenHeight() * .49f), 30, SKYBLUE);
					Utils::DrawCenteredText("[< ] [ >] to move Left and Right.", static_cast<int>(GetScreenWidth() * .75f), static_cast<int>(GetScreenHeight() * .53f), 25, BLUE);
					Utils::DrawCenteredText("[UP] to Jump!", static_cast<int>(GetScreenWidth() * .75f), static_cast<int>(GetScreenHeight() * .58f), 25, BLUE);
					Utils::DrawCenteredText("[DOWN] to Shoot your gun.", static_cast<int>(GetScreenWidth() * .75f), static_cast<int>(GetScreenHeight() * .63f), 25, BLUE);
				}

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