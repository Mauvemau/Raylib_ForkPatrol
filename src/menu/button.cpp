#include "button.h"

#include "collisionManager.h"
#include "utils.h"

namespace MoonPatrol {
	namespace Buttons {

		// Public

		void center(Button& button) {
			button.x -= button.width * .5f;
			button.y -= button.height * .5f;
		}

		Button create() {
			Button button;
			button.x = 0;
			button.y = 0;
			button.width = 0;
			button.height = 0;
			button.hovered = false;
			return button;
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