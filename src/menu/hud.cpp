#include "hud.h"

#include "raylib.h"

#include "game/game.h"
#include "program_manager.h"
#include "asset_manager.h"
#include "utils.h"

namespace MoonPatrol {
	namespace Hud {
		// Private

		void drawLives();

		// --

		void drawLives() {
			DrawText("P1:",
				static_cast<int>(GetScreenHeight() * .01f),
				static_cast<int>(GetScreenHeight() * .08f),
				static_cast<int>(GetScreenHeight() * .04f),
				RED);
			Vector2 size = { static_cast<float>(GetScreenHeight() * .06), static_cast<float>(GetScreenHeight() * .03) };
			float spacing = 0;
			int p1Lives = Game::getPlayerOneLives();
			if (p1Lives > 0) {
				for (int i = 0; i < p1Lives; i++) {
					if (i > 0)
						spacing += size.x + GetScreenWidth() * .01f;
					Assets::DrawSprite(Assets::Sprite::JEEP_BODY_SILHOUETTE,
						{ static_cast<float>((GetScreenWidth() * .05) + spacing), static_cast<float>(GetScreenHeight() * .08) }, size,
						{ 0, 0 }, 0, RED);
				}
			}
			else if (p1Lives < 0) {
				DrawText("DEAD",
					static_cast<int>(GetScreenWidth() * .05),
					static_cast<int>(GetScreenHeight() * .08f),
					static_cast<int>(GetScreenHeight() * .04f),
					RED);
			}
			if (Game::getGameMode()) {
				DrawText("P2:",
					static_cast<int>(GetScreenHeight() * .01f),
					static_cast<int>(GetScreenHeight() * .15f),
					static_cast<int>(GetScreenHeight() * .04f),
					BLUE);
				size = { static_cast<float>(GetScreenHeight() * .06), static_cast<float>(GetScreenHeight() * .03) };
				spacing = 0;
				int p2Lives = Game::getPlayerTwoLives();
				if (p2Lives > 0) {
					for (int i = 0; i < p2Lives; i++) {
						if (i > 0)
							spacing += size.x + GetScreenWidth() * .01f;
						Assets::DrawSprite(Assets::Sprite::JEEP_BODY_SILHOUETTE,
							{ static_cast<float>((GetScreenWidth() * .05) + spacing), static_cast<float>(GetScreenHeight() * .15) }, size,
							{ 0, 0 }, 0, BLUE);
					}
				}
				else if(p2Lives < 0){
					DrawText("DEAD",
						static_cast<int>(GetScreenWidth() * .05),
						static_cast<int>(GetScreenHeight() * .15f),
						static_cast<int>(GetScreenHeight() * .04f),
						BLUE);
				}
			}
		}

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

			if (Game::getTime() < 10.0f) {
				Utils::DrawCenteredText("Press [ESC] to pause the game.",
					static_cast<int>((GetScreenWidth() * .5)),
					static_cast<int>((GetScreenHeight() * .95)),
					static_cast<int>(GetScreenHeight() * .03f),
					{ 40, 30, 15, 255 });
			}

			if (Game::getTime() < Game::getBeginTime()) {
				Utils::DrawCenteredText("GET READY", 
					static_cast<int>(GetScreenWidth() * .5f), 
					static_cast<int>(GetScreenHeight() * .5f), 
					static_cast<int>(GetScreenHeight() * .075f), 
					RED);
			}

			drawLives();

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