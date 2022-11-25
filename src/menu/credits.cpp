#include "credits.h"
#include "button.h"

#include "programManager.h"

namespace MoonPatrol {
	namespace Credits {

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
		}

		void draw() {
			BeginDrawing();

				ClearBackground(BLACK);

				HideCursor();
				DrawCircle(GetMouseX(), GetMouseY(), 5, RED);

				Buttons::draw(buttonReturn);

				DrawText("Credits:", 0, 2, 10, WHITE);

			EndDrawing();
		}

		// Public

		void update() {
			if (Buttons::update(buttonReturn, GetMousePosition())) Program::setScreen(Program::Screen::MAINMENU);

			draw();
		}

		void init() {
			initButtons();
		}
	}
}