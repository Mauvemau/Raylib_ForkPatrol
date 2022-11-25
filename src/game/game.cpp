#include "raylib.h"
#include "game.h"
#include "player.h"

namespace MoonPatrol {
    namespace Game {
        // Private

        Players::Player player1;

        float floorAltitude;

        void draw();

        // --

        void draw()
        {
            BeginDrawing();

                ClearBackground(BLACK);

                DrawRectangle(0, static_cast<int>(getFloorAltitude()), GetScreenWidth(), 20, PURPLE);

                //DrawText("GAME PAUSED", static_cast<int>(screenWidth / 2 - MeasureText("GAME PAUSED", 40) / 2), static_cast<int>(screenHeight / 2 - 40), 40, GRAY);

                Players::draw(player1);

            EndDrawing();
        }

        // Public

        float getFloorAltitude() {
            return floorAltitude;
        }

        void update()
        {
            Players::update(player1);

            draw();
        }

        void init()
        {
            floorAltitude = GetScreenHeight() * .85f;
            Players::init(player1,
                GetScreenWidth() * .25f, 
                getFloorAltitude(),
                50, 50,
                200.0f, 
                100.0f, 100.0f,
                RED);
        }
    }
}