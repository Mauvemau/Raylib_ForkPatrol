#include "program_manager.h"

#include "raylib.h"

// Screens
#include "menu/game_over_menu.h"
#include "menu/gamemode_menu.h"
#include "menu/main_menu.h"
#include "menu/credits.h"
#include "game/game.h"
// Managers
#include "asset_manager.h"

namespace MoonPatrol {
	namespace Program {
		// Private

		const int screenWidth = 1024;
		const int screenHeight = 768;

		Screen currentScreen;

		bool programShouldClose;

		const char* programVersion = "1.2";

		static void initScreen(Screen screen);
		static void uninit();
		static void update();
		static void init();

		// --

		static void initScreen(Screen screen) {
			switch (screen) {
			case MoonPatrol::Program::Screen::GAME:
				Game::init();
				break;
			case MoonPatrol::Program::Screen::MAINMENU:
				MainMenu::init();
				break;
			case MoonPatrol::Program::Screen::CREDITS:
				Credits::init();
				break;
			case MoonPatrol::Program::Screen::GAMEMODE:
				GamemodeMenu::init();
				break;
			case MoonPatrol::Program::Screen::GAMEOVER:
				GameOverMenu::init();
				break;
			default:
				break;
			}
		}

		static void uninit() {
			Assets::Unload();
			CloseWindow();
		}

		static void update() {
			while (!WindowShouldClose() && !programShouldClose) {
				switch (currentScreen) {
				case MoonPatrol::Program::Screen::GAME:
					Game::update();
					break;
				case MoonPatrol::Program::Screen::MAINMENU:
					MainMenu::update();
					break;
				case MoonPatrol::Program::Screen::CREDITS:
					Credits::update();
					break;
				case MoonPatrol::Program::Screen::GAMEMODE:
					GamemodeMenu::update();
					break;
				case MoonPatrol::Program::Screen::GAMEOVER:
					GameOverMenu::update();
					break;
				default:
					break;
				}
			}
		}

		static void init() {
			programShouldClose = false;
			InitWindow(static_cast<int>(screenWidth), static_cast<int>(screenHeight), TextFormat("MoonPatrol - Altamirano/Salazar - v%s", programVersion));
			//SetTargetFPS(15);
			HideCursor();
			SetExitKey(KEY_NULL);
			setScreen(Screen::MAINMENU);
			Assets::Load();
		}

		// Public

		const char* getVersion() {
			return programVersion;
		}

		void close() {
			programShouldClose = true;
		}

		void setScreen(Screen screen) {
			initScreen(screen);
			currentScreen = screen;
		}

		void start() {
			init();
			update();
			uninit();
		}
	}
}