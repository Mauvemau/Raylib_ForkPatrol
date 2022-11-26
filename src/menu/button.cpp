#include "button.h"

#include "collision_manager.h"
#include "utils.h"

namespace MoonPatrol {
	namespace Buttons {

		// Public

		Button create() {
			Button button;
			button.x = 0;
			button.y = 0;
			button.width = 0;
			button.height = 0;
			button.hovered = false;
			return button;
		}

		bool getIsHovered(Button button) {
			return button.hovered;
		}

		void center(Button& button) {
			button.x -= button.width * .5f;
			button.y -= button.height * .5f;
		}

		void drawHeader(const char* text, Buttons::Button button) {
			int x = static_cast<int>(button.x + static_cast<float>(button.width * .5f));
			int y = static_cast<int>(button.y - static_cast<float>(button.width * .1f));
			Utils::DrawCenteredText(text, x, y, static_cast<int>(GetScreenHeight() * .03f), RAYWHITE);
		}

		void draw(Button button) {
			if (button.hovered)
			{
				DrawRectangle(static_cast<int>(button.x), static_cast<int>(button.y), static_cast<int>(button.width), static_cast<int>(button.height), DARKBLUE);
				Utils::DrawCenteredText(button.text, static_cast<int>(button.x + (button.width * .5f)),
					static_cast<int>(button.y + (button.height * .5f)),
					30, WHITE);
			}
			else
			{
				DrawRectangle(static_cast<int>(button.x), static_cast<int>(button.y), static_cast<int>(button.width), static_cast<int>(button.height), WHITE);
				Utils::DrawCenteredText(button.text, static_cast<int>(button.x + (button.width * .5f)), 
					static_cast<int>(button.y + (button.height * .5f)), 
					30, DARKBLUE);
			}
		}

		bool update(Button& button, Vector2 mousePos) {
			button.hovered = (Collisions::pointRectCollision(mousePos.x, mousePos.y, button.x, button.y, button.width, button.height));
			return (button.hovered && IsMouseButtonDown(MOUSE_BUTTON_LEFT));
		}

		void init(Button& button, float x, float y, float width, float height, const char* text) {
			button = create();
			button.x = x;
			button.y = y;
			button.width = width;
			button.height = height;
			button.text = text;
		}
	}
}