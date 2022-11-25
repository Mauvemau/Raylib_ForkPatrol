#include "raylib.h"
#include "game.h"
#include "player.h"

#define KEY_SPACE 32

enum class Options
{
    Menu,
    Play,
    Credits,
    Quit
};

struct Button
{
    float x;
    float y;
    float width;
    float height;

    const char* text;
};

Player player;

Button buttonPlay;
Button buttonCredits;
Button buttonQuit;
Button buttonPause;
Button buttonReturn;
Button buttonContinue;

Options chosenOpc = Options::Play;

float screenWidth;
float screenHeight;

int initGame();                           // Initialize game
static void game();                       // Play game
static void showCredits();                // Show credits
static void updateGame();                 // Update game 
static void drawGame();                   // Draw game 
static void logicMenu();                  // Logic Menu 
static void drawMenu();                   // Draw Menu 
static void updateDrawFrame();            // Update and Draw 

void initButtons()
{
    buttonPlay.width = 120;
    buttonPlay.height = 30;
    buttonPlay.x = screenWidth / 2 - buttonPlay.width / 2;
    buttonPlay.y = screenHeight / 2 - buttonPlay.height / 2;
    buttonPlay.text = "Play";

    buttonCredits.width = 100;
    buttonCredits.height = 30;
    buttonCredits.x = screenWidth / 2 - buttonCredits.width / 2;
    buttonCredits.y = screenHeight / 2 - buttonCredits.height / 2 + 65;
    buttonCredits.text = "Credits";

    buttonQuit.width = 50;
    buttonQuit.height = 30;
    buttonQuit.x = screenWidth / 2 - buttonQuit.width / 2;
    buttonQuit.y = screenHeight / 2 - buttonQuit.height / 2 + 130;
    buttonQuit.text = "Quit";

    buttonReturn.width = 180;
    buttonReturn.height = 30;
    buttonReturn.x = 20;
    buttonReturn.y = screenHeight - buttonReturn.height - 20;
    buttonReturn.text = "Back To Menu";

    buttonPause.width = 80;
    buttonPause.height = 30;
    buttonPause.x = screenWidth - buttonPause.width - 20;
    buttonPause.y = 20;
    buttonPause.text = "Pause";

    buttonContinue.width = 110;
    buttonContinue.height = 30;
    buttonContinue.x = screenWidth / 2 - buttonContinue.width / 2;
    buttonContinue.y = screenHeight / 2 - buttonContinue.height / 2 + 50;
    buttonContinue.text = "Continue";
};

void logicMenu()
{
    if (CheckCollisionCircleRec(Vector2{ static_cast<float>(GetMouseX()), static_cast<float>(GetMouseY()) }, 5, Rectangle{ buttonPlay.x, buttonPlay.y, buttonPlay.width, buttonPlay.height }))
    {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            game();
            chosenOpc = Options::Play;
        }
    }

    if (CheckCollisionCircleRec(Vector2{ static_cast<float>(GetMouseX()), static_cast<float>(GetMouseY()) }, 5, Rectangle{ buttonCredits.x, buttonCredits.y, buttonCredits.width, buttonCredits.height }))
    {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            chosenOpc = Options::Credits;
        }
    }

    if (CheckCollisionCircleRec(Vector2{ static_cast<float>(GetMouseX()), static_cast<float>(GetMouseY()) }, 5, Rectangle{ buttonQuit.x, buttonQuit.y, buttonQuit.width, buttonQuit.height }))
    {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            chosenOpc = Options::Quit;
        }
    }
}

void drawButton(Button button)
{
    if (CheckCollisionCircleRec(Vector2{ static_cast<float>(GetMouseX()), static_cast<float>(GetMouseY()) }, 5, Rectangle{ button.x, button.y, button.width, button.height }))
    {
        DrawRectangle(static_cast<int>(button.x), static_cast<int>(button.y), static_cast<int>(button.width), static_cast<int>(button.height), DARKBLUE);
        DrawText(button.text, static_cast<int>(button.x), static_cast<int>(button.y), 25, WHITE);
    }
    else
    {
        DrawRectangle(static_cast<int>(button.x), static_cast<int>(button.y), static_cast<int>(button.width), static_cast<int>(button.height), WHITE);
        DrawText(button.text, static_cast<int>(button.x), static_cast<int>(button.y), 25, DARKBLUE);
    }
};

void showCredits()
{
    if (CheckCollisionCircleRec(Vector2{ static_cast<float>(GetMouseX()), static_cast<float>(GetMouseY()) }, 5, Rectangle{ buttonReturn.x, buttonReturn.y, buttonReturn.width, buttonReturn.height }))
    {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            chosenOpc = Options::Menu;
        }
    }

    BeginDrawing();

    ClearBackground(BLACK);

    HideCursor();
    DrawCircle(GetMouseX(), GetMouseY(), 5, RED);

    DrawText("Credits:", 0, 2, 10, WHITE);

    //DrawButtonReturn
    drawButton(buttonReturn);

    EndDrawing();
};

void drawMenu()
{
    BeginDrawing();

    ClearBackground(BLACK);

    HideCursor();
    DrawCircle(GetMouseX(), GetMouseY(), 5, RED);

    DrawText("Menu", 0, 0, 120, WHITE);

    //DrawButtonPlay
    drawButton(buttonPlay);

    //DrawButtonCredits
    drawButton(buttonCredits);

    //DrawButtonQuit
    drawButton(buttonQuit);

    EndDrawing();
};

int initGame()
{
    screenWidth = 1024;
    screenHeight = 650;

    InitWindow(static_cast<int>(screenWidth), static_cast<int>(screenHeight), "MoonPatrol - Altamirano");

    initButtons();

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose() && chosenOpc != Options::Quit) // Detect window close button or ESC key
    {
        // Update and Draw
        switch (chosenOpc)
        {
        case Options::Menu:
            logicMenu();
            drawMenu();
            break;

        case Options::Play:
            updateDrawFrame();
            break;

        case Options::Credits:
            showCredits();
            break;
        }
    }

    CloseWindow();

    return 0;
}

// Initialize game variables
void game()
{

}

// Update game
void updateGame()
{
    if (IsKeyDown(KEY_SPACE))
    {

        player.y -= 10;
    }
        
    player.y = 325;
}

// Draw game 
void drawGame()
{
    BeginDrawing();

    ClearBackground(BLACK);

    //DrawText("GAME PAUSED", static_cast<int>(screenWidth / 2 - MeasureText("GAME PAUSED", 40) / 2), static_cast<int>(screenHeight / 2 - 40), 40, GRAY);

    DrawRectangle(player.x, player.y, player.width, player.height, WHITE);

    EndDrawing();
}

// Update and Draw
void updateDrawFrame()
{
    updateGame();
    drawGame();
}