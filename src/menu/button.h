#pragma once

#include "raylib.h"

namespace MoonPatrol {
	namespace Buttons {
        struct Button
        {
            float x;
            float y;
            float width;
            float height;
            bool hovered;

            const char* text;
        };

        Button create();

        void center(Button& button);

        void draw(Button button);
        bool update(Button& button, Vector2 mousePos);
        void init(Button& button, float x, float y, float width, float height, const char* text);
	}
}