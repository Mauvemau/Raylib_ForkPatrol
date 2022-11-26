#include "hud.h"

#include "raylib.h"

#include "game/game.h"
#include "program_manager.h"
#include "utils.h"

namespace MoonPatrol {
	namespace Hud {
		// Private

		// --

		// Public
		void draw() {
			const char* versionText = TextFormat("v%s", Program::getVersion());
			int versionFontSize = static_cast<int>(GetScreenHeight() * .05f);
			int versionTextWide = MeasureText(versionText, versionFontSize);
			DrawText(versionText,
				static_cast<int>((GetScreenWidth() * .99) - versionTextWide),
				static_cast<int>((GetScreenHeight() * .99) - versionFontSize),
				versionFontSize, { 40, 30, 15, 255 });

			DrawText(TextFormat("Score: %i", Game::getScore()),
				static_cast<int>(GetScreenHeight() * .01f),
				static_cast<int>(GetScreenHeight() * .01f),
				static_cast<int>(GetScreenHeight() * .05f),
				RAYWHITE);

			if (Game::getTime() < Game::getBeginTime()) {
				Utils::DrawCenteredText("GET READY", 
					static_cast<int>(GetScreenWidth() * .5f), 
					static_cast<int>(GetScreenHeight() * .5f), 
					static_cast<int>(GetScreenHeight() * .075f), 
					RED);
			}

#ifdef _DEBUG
			DrawText(TextFormat("Elapsed Time: %f", Game::getTime()),
				static_cast<int>((GetScreenWidth() * .01)),
				static_cast<int>((GetScreenHeight() * .96)),
				static_cast<int>(GetScreenHeight() * .04f), 
				{ 40, 30, 15, 255 });
#endif // _DEBUG
		}
	}
}