#include "game.h"

#include "player.h"
#include "obstacle.h"

#include "inputManager.h"
#include "collisionManager.h"
#include "programManager.h"

#include "raylib.h"

namespace MoonPatrol {
    namespace Game {
        // Private

        Players::Player playerOne;
        Obstacles::Obstacle obstacle;

        float floorAltitude;

        void draw();

        // --

        void draw()
        {
            BeginDrawing();

                ClearBackground(BLACK);

                DrawRectangle(0, static_cast<int>(getFloorAltitude()), GetScreenWidth(), 20, PURPLE);

                //DrawText("GAME PAUSED", static_cast<int>(screenWidth / 2 - MeasureText("GAME PAUSED", 40) / 2), static_cast<int>(screenHeight / 2 - 40), 40, GRAY);

                Obstacles::draw(obstacle);

                Players::draw(playerOne);

            EndDrawing();
        }

        // Public

        float getFloorAltitude() {
            return floorAltitude;
        }

        void update()
        {
            Input::updatePlayerOne(playerOne);

            Players::update(playerOne);

            Obstacles::update(obstacle);

            if (Collisions::playerObstacle(playerOne, obstacle)) {
                Program::setScreen(Program::Screen::GAME);
            }

            draw();
        }

        void init()
        {
            floorAltitude = GetScreenHeight() * .85f;
            Players::init(playerOne,
                GetScreenWidth() * .25f, 
                getFloorAltitude(),
                50, 50,
                300.0f, 
                200.0f, 200.0f,
                RED);

            Obstacles::init(obstacle,
                getFloorAltitude(),
                30, 30,
                200.0f);
        }
    }
}