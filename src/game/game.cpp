#include "game.h"

// Objects
#include "player.h"
#include "obstacle.h"
#include "terrain.h"

// Managers
#include "inputManager.h"
#include "collisionManager.h"
#include "programManager.h"
#include "objectManager.h"

// Menus
#include "menu/pauseMenu.h"
#include "menu/hud.h"

// Lib
#include "raylib.h"
#include <chrono>

using namespace std;

namespace MoonPatrol {
    namespace Game {
        // Private

        // Objects
        Players::Player playerOne;
        Obstacles::Obstacle obstacle;

        // Background
        Terrains::Terrain backgroundClose;
        Terrains::Terrain backgroundFar;
        Terrains::Terrain floor;

        chrono::steady_clock::time_point startTime;
        chrono::steady_clock::time_point pauseStartTime; // En caso del juego estar pausado por determinado tiempo, se lo sumamos al startTime.
        bool paused;

        float floorAltitude;

        void draw();

        // --

        void draw()
        {
            BeginDrawing();

                ClearBackground({ 30, 15, 55, 255 });

                DrawCircle(static_cast<int>(GetScreenWidth() * .75f), static_cast<int>(GetScreenHeight() * .2f), 100, { 250, 240, 190, 255 });

                Terrains::draw(backgroundFar);
                Terrains::draw(backgroundClose);

                DrawRectangle(0, static_cast<int>(getFloorAltitude()), GetScreenWidth(), 20, GRAY);

                Obstacles::draw(obstacle);

                Players::draw(playerOne);

                ObjectManager::draw();

                Terrains::draw(floor);

                if (paused) {
                    PauseMenu::draw();
                }
                else {
                    Hud::draw();
                }

            EndDrawing();
        }

        // Public

        void setPaused(bool value) {
            paused = value;
            if (paused) {
                pauseStartTime = chrono::steady_clock::now();
            }
            else {
                startTime += (chrono::steady_clock::now() - pauseStartTime);
            }
        }

        bool getIsPaused() {
            return paused;
        }

        float getFloorAltitude() {
            return floorAltitude;
        }

        float getTime() {
            float curTime = (static_cast<int>(chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - startTime).count())) * .001f;
            return curTime;
        }

        void update()
        {
            Input::updateGeneral();

            if (!paused) {
                Input::updatePlayerOne(playerOne);

                Players::update(playerOne);

                ObjectManager::update();

                Obstacles::update(obstacle);

                Terrains::update(floor);
                Terrains::update(backgroundClose);
                Terrains::update(backgroundFar);

                if (Collisions::playerObstacle(playerOne, obstacle)) {
                    Program::setScreen(Program::Screen::GAMEOVER);
                }
            }
            else {
                PauseMenu::update();
            }

            draw();
        }

        void init()
        {
            floorAltitude = GetScreenHeight() * .85f;

            startTime = chrono::steady_clock::now();
            paused = false;
            PauseMenu::init();

            ObjectManager::init();

            Terrains::init(floor, GetScreenWidth() * .1f, GetScreenHeight() * .875f, GetScreenHeight() * .85f, 250.0f, { 230, 180, 80, 255 });
            Terrains::init(backgroundClose, GetScreenWidth() * .2f, GetScreenHeight() * .7f, GetScreenHeight() * .5f, 100.0f, { 145, 120, 50, 255 });
            Terrains::init(backgroundFar, GetScreenWidth() * .3f, GetScreenHeight() * .7f, GetScreenHeight() * .4f, 50.0f, { 40, 30, 15, 255 });

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
                250.0f);
        }
    }
}