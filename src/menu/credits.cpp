#include "credits.h"

#include "button.h"
#include "program_manager.h"
#include "utils.h"

namespace MoonPatrol {
	namespace Credits {

		Buttons::Button altamiranoGithub;
		Buttons::Button altamiranoItch;

		Buttons::Button salazarGithub;
		Buttons::Button salazarItch;

		Buttons::Button raylibWebsite;

		Buttons::Button spriteJeepButton;
		Buttons::Button spriteDroneButton;

		Buttons::Button buttonReturn;

		void initButtons();
		void draw();

		// --

		void initButtons() {
			Buttons::init(buttonReturn, 
			20, 
			static_cast<float>(GetScreenHeight() - 80), 
			240, 
			60, 
			"Back To Menu");

			Buttons::init(altamiranoGithub,
				static_cast<float>(GetScreenWidth() * .5f),
				static_cast<float>(GetScreenHeight() * .3f),
				160,
				40,
				"Github");
			Buttons::center(altamiranoGithub);
			Buttons::init(altamiranoItch,
				static_cast<float>(GetScreenWidth() * .5f),
				static_cast<float>(GetScreenHeight() * .3f + 50),
				160,
				40,
				"Itch.io");
			Buttons::center(altamiranoItch);

			Buttons::init(salazarGithub,
				static_cast<float>(GetScreenWidth() * .5f),
				static_cast<float>(GetScreenHeight() * .475f),
				160,
				40,
				"Github");
			Buttons::center(salazarGithub);
			Buttons::init(salazarItch,
				static_cast<float>(GetScreenWidth() * .5f),
				static_cast<float>(GetScreenHeight() * .475f + 50),
				160,
				40,
				"Itch.io");
			Buttons::center(salazarItch);

			Buttons::init(raylibWebsite,
				static_cast<float>(GetScreenWidth() * .5f),
				static_cast<float>(GetScreenHeight() * .7f),
				160,
				40,
				"Raylib");
			Buttons::center(raylibWebsite);

			Buttons::init(spriteJeepButton,
				static_cast<float>(GetScreenWidth() * .5f),
				static_cast<float>(GetScreenHeight() * .82f),
				220,
				40,
				"Jeep Sprite");
			Buttons::center(spriteJeepButton);
			Buttons::init(spriteDroneButton,
				static_cast<float>(GetScreenWidth() * .5f),
				static_cast<float>(GetScreenHeight() * .82f + 50),
				220,
				40,
				"Drone Sprite");
			Buttons::center(spriteDroneButton);

		}

		void draw() {
			BeginDrawing();

				ClearBackground(BLACK);

				Buttons::draw(buttonReturn);

				Buttons::draw(altamiranoGithub);
				Buttons::drawHeader("Project Owner Altamirano", altamiranoGithub);
				Buttons::draw(altamiranoItch);

				Buttons::draw(salazarGithub);
				Buttons::drawHeader("Fork by Mauvemau", salazarGithub);
				Buttons::draw(salazarItch);

				Buttons::draw(raylibWebsite);
				Buttons::drawHeader("This game was made using Raylib", raylibWebsite);

				Buttons::draw(spriteJeepButton);
				Buttons::drawHeader("Sprites by knik1985", spriteJeepButton);
				Buttons::draw(spriteDroneButton);

				Utils::DrawCenteredText("Credits", static_cast<int>(GetScreenWidth() * .5f), static_cast<int>(GetScreenHeight() * .10f), 60, ORANGE);
				Utils::DrawCenteredText("Developers:", static_cast<int>(GetScreenWidth() * .5f), static_cast<int>(GetScreenHeight() * .2f), 35, SKYBLUE);
				Utils::DrawCenteredText("Resources:", static_cast<int>(GetScreenWidth() * .5f), static_cast<int>(GetScreenHeight() * .6f), 35, RED);

				DrawCircle(GetMouseX(), GetMouseY(), 5, RED);

			EndDrawing();
		}

		// Public

		void update() {
			if (Buttons::update(buttonReturn, GetMousePosition())) Program::setScreen(Program::Screen::MAINMENU);
			if (Buttons::update(altamiranoGithub, GetMousePosition())) OpenURL("https://github.com/Shusepe");
			if (Buttons::update(altamiranoItch, GetMousePosition())) OpenURL("https://jose-altamirano.itch.io");
			if (Buttons::update(salazarGithub, GetMousePosition())) OpenURL("https://github.com/Mauvemau");
			if (Buttons::update(salazarItch, GetMousePosition())) OpenURL("https://mauvemau.itch.io");
			if (Buttons::update(raylibWebsite, GetMousePosition())) OpenURL("https://www.raylib.com");
			if (Buttons::update(spriteJeepButton, GetMousePosition())) OpenURL("https://opengameart.org/content/pixel-military-car-pack");
			if (Buttons::update(spriteDroneButton, GetMousePosition())) OpenURL("https://opengameart.org/content/pixel-drone");
			if (IsKeyPressed(KEY_ESCAPE)) Program::setScreen(Program::Screen::MAINMENU);

			draw();
		}

		void init() {
			initButtons();
		}
	}
}