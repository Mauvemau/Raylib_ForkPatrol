#include "raylib.h"
#include "game.h"
#include "player.h"

#define KEY_SPACE 32

namespace MoonPatrol {
    namespace Game {
        // Private

        Player player;

        void draw();

        // --

        void draw()
        {
            BeginDrawing();

            ClearBackground(BLACK);

            //DrawText("GAME PAUSED", static_cast<int>(screenWidth / 2 - MeasureText("GAME PAUSED", 40) / 2), static_cast<int>(screenHeight / 2 - 40), 40, GRAY);

            DrawRectangle(player.x, player.y, player.width, player.height, WHITE);

            EndDrawing();
        }

        // Public

        void update()
        {
            if (IsKeyDown(KEY_SPACE))
            {
                player.y -= 10;
            }

            player.y = 325;

            draw();
        }

        void init()
        {
        }
    }
}