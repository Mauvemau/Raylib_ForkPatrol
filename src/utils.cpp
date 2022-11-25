#include "utils.h"

namespace Utils {

	// Public

    float DegreesToRadians(float deg) {
        return static_cast<float>(deg * (m_pi / 180.0));
    }

    float RadiansToDegrees(float rad) {
        return static_cast<float>(rad * (180.0 / m_pi));
    }

	void DrawCenteredText(const char* text, int x, int y, int fontSize, Color color) {
        int textWide = MeasureText(text, fontSize);
        DrawText(text, static_cast<int>((x) - (textWide * .5)), static_cast<int>((y) - (fontSize * .5)), fontSize, color);
	}
}