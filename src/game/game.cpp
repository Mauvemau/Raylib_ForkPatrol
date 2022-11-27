#include "game.h"

// lib
#include <chrono> // Usando la libreria chrono para lograr un reloj que sea lo mas perfecto posible.

#include "raylib.h"

// Objects
#include "player.h"
#include "obstacle.h"
#include "terrain.h"
// Managers
#include "input_manager.h"
#include "collision_manager.h"
#include "program_manager.h"
#include "object_manager.h"
#include "asset_manager.h"
// Layout Menus
#include "menu/pause_menu.h"
#include "menu/hud.h"

using namespace std;

namespace MoonPatrol {
    namespace Game {
        // Private

        // Objects
        Players::Player playerOne;
        Players::Player playerTwo;
        Obstacles::Obstacle obstacle;

        // Background
        Terrains::Terrain backgroundClose;
        Terrains::Terrain backgroundFar;
        Terrains::Terrain floor;

        chrono::steady_clock::time_point startTime;
        chrono::steady_clock::time_point pauseStartTime; // En caso del juego estar pausado por determinado tiempo, se lo sumamos al startTime.
        bool paused;

        float floorAltitude;

        int score;

        int enemySoftCap;

        bool multiplayer;

        float beginGameTime; // El juego comienza despues de __ segundos, dejando que los jugadores que prueben los controles.

        int obstaclesDodged;
        int enemiesKilled;

        void handleGameLogic();
        void draw();

        // --

        void handleGameLogic() {
            if (obstaclesDodged > 0) {
                if (ObjectManager::getActiveEnemies() < enemySoftCap) {
                    int direction = -1;
                    int aux = GetRandomValue(0, 1);
                    if (aux) {
                        direction = abs(direction);
                    }
                    float altitude;
                    int altitudeMultiplier = GetRandomValue(20, 40);
                    altitude = altitudeMultiplier * .01f;
                    float speed = static_cast<float>(GetRandomValue(100, 200));

                    ObjectManager::addEnemy(GetScreenHeight() * altitude, GetScreenHeight() * .045f, speed, direction);
                }
            }
        }

        void draw()
        {
            BeginDrawing();

                ClearBackground({ 30, 15, 55, 255 });

                DrawCircle(static_cast<int>(GetScreenWidth() * .75f), static_cast<int>(GetScreenHeight() * .2f), 100, { 250, 240, 190, 255 });

                Terrains::draw(backgroundFar);
                Terrains::draw(backgroundClose);

                //DrawRectangle(0, static_cast<int>(getFloorAltitude()), GetScreenWidth(), 20, GRAY);

                Obstacles::draw(obstacle);

                ObjectManager::draw();

                if (Players::getLives(playerOne) >= 0) {
                    Players::draw(playerOne);
                }
                if (multiplayer) {
                    if (Players::getLives(playerTwo) >= 0) {
                        Players::draw(playerTwo);
                    }
                }

                if (multiplayer) {
                    if (Players::getLives(playerOne) >= 0) {
                        Players::drawHeader(playerOne, "P1");
                    }
                    if (Players::getLives(playerTwo) >= 0) {
                        Players::drawHeader(playerTwo, "P2");
                    }
                }

                if (obstaclesDodged == 0 && getTime() >= beginGameTime) {
                    Obstacles::drawHeader(obstacle, "JUMP OVER THIS");
                }

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

        void setObstaclesDodged(int value) {
            obstaclesDodged = value;
        }

        void setEnemiesKilled(int value) {
            enemiesKilled = value;
        }

        void setGameMode(bool value) {
            multiplayer = value;
        }

        void setPaused(bool value) {
            paused = value;
            if (paused) {
                pauseStartTime = chrono::steady_clock::now();
                Assets::PlayAudio(Assets::Audio::PAUSE, .5f);
            }
            else {
                startTime += (chrono::steady_clock::now() - pauseStartTime);
            }
        }

        void setScore(int value) {
            score = value;
        }

        bool getGameMode() {
            return multiplayer;
        }

        int getPlayerOneLives() {
            return Players::getLives(playerOne);
        }

        int getPlayerTwoLives() {
            return Players::getLives(playerTwo);
        }

        int getObstaclesDodged() {
            return obstaclesDodged;
        }

        int getEnemiesKilled() {
            return enemiesKilled;
        }

        float getBeginTime() {
            return beginGameTime;
        }

        bool getIsPaused() {
            return paused;
        }

        float getFloorAltitude(float xPos) {
            return Terrains::getElevation(floor, xPos);
        }

        float getFloorAltitude() {
            return floorAltitude;
        }

        float getTime() {
            float curTime = (static_cast<int>(chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - startTime).count())) * .001f;
            return curTime;
        }

        int getScore() {
            return score;
        }

        void update()
        {
            Input::updateGeneral();

            if (!paused) {
                if (Players::getLives(playerOne) >= 0) {
                    Input::updatePlayerOne(playerOne);
                    Players::update(playerOne);
                }

                if (multiplayer) {
                    if (Players::getLives(playerTwo) >= 0) {
                        Input::updatePlayerTwo(playerTwo);
                        Players::update(playerTwo);
                    }
                }

                ObjectManager::update();

                if (getTime() >= beginGameTime) {
                    Obstacles::update(obstacle);
                    handleGameLogic();
                }

                if (Players::getLives(playerOne) >= 0) {
                    if (Collisions::playerObstacle(playerOne, obstacle)) {
                        Obstacles::setX(obstacle, static_cast<float>((GetScreenWidth() * 2) + obstacle.width));
                        Players::setLives(playerOne, Players::getLives(playerOne) - 1);
                        Assets::PlayAudio(Assets::Audio::HURT, 1.0f);
                    }
                    if (playerOne.x > (obstacle.x + obstacle.width)) {
                        Obstacles::handleDodgeLogic(obstacle);
                    }
                }
                if (multiplayer) {
                    if (Players::getLives(playerTwo) >= 0) {
                        if (Collisions::playerObstacle(playerTwo, obstacle)) {
                            Obstacles::setX(obstacle, static_cast<float>((GetScreenWidth() * 2) + obstacle.width));
                            Players::setLives(playerTwo, Players::getLives(playerTwo) - 1);
                            Assets::PlayAudio(Assets::Audio::HURT, 1.0f);
                        }
                        if (playerTwo.x > (obstacle.x + obstacle.width)) {
                            Obstacles::handleDodgeLogic(obstacle);
                        }
                    }
                }

                Terrains::update(floor);
                Terrains::update(backgroundClose);
                Terrains::update(backgroundFar);
            }
            else {
                PauseMenu::update();
            }

            if (multiplayer && Players::getLives(playerOne) < 0 && Players::getLives(playerTwo) < 0 || !multiplayer && Players::getLives(playerOne) < 0) {
                Program::setScreen(Program::Screen::GAMEOVER);
            }

            draw();
        }

        void init()
        {
            floorAltitude = GetScreenHeight() * .85f;

            startTime = chrono::steady_clock::now();
            paused = false;
            PauseMenu::init();

            score = 0;

            enemySoftCap = 1;

            beginGameTime = 3.0f;

            obstaclesDodged = 0;
            enemiesKilled = 0;

            ObjectManager::init();

            Terrains::init(floor, GetScreenWidth() * .1f, GetScreenHeight() * .875f, GetScreenHeight() * .85f, 250.0f, { 230, 180, 80, 255 });
            Terrains::init(backgroundClose, GetScreenWidth() * .2f, GetScreenHeight() * .7f, GetScreenHeight() * .5f, 100.0f, { 145, 120, 50, 255 });
            Terrains::init(backgroundFar, GetScreenWidth() * .3f, GetScreenHeight() * .7f, GetScreenHeight() * .4f, 50.0f, { 40, 30, 15, 255 });

            Players::init(playerOne,
                GetScreenWidth() * .22f, 
                getFloorAltitude(),
                120, 50,
                300.0f, 
                200.0f, 200.0f,
                3,
                RED);

            Players::init(playerTwo,
                GetScreenWidth() * .28f,
                getFloorAltitude(),
                120, 50,
                300.0f,
                200.0f, 200.0f,
                3,
                BLUE);

            Obstacles::init(obstacle,
                getFloorAltitude() - 30,
                30, 100,
                250.0f);
        }
    }
}