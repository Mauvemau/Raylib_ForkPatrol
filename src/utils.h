#pragma once

#include "raylib.h"

namespace Utils {
	const double m_pi = 3.14159265358979323846;

	float DegreesToRadians(float deg);
	float RadiansToDegrees(float rad);
	void DrawCenteredText(const char* text, int x, int y, int fontSize, Color color);
}