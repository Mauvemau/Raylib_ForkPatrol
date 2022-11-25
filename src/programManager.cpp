#include "programManager.h"

#include "raylib.h"

// Screens
#include "mainMenu.h"

namespace MoonPatrol {
	namespace Program {
		// Private

		const int screenWidth = 1024;
		const int screenHeight = 768;

		Screen currentScreen;

		bool programShouldClose;

		const char* programVersion = "0.1";

		static void initScreen(Screen screen);
		static void uninit();
		static void update();
		static void init();


		// --

		static void initScreen(Screen screen) {
			switch (screen) {
			case MoonPatrol::Program::Screen::GAME:
				
				break;
			case MoonPatrol::Program::Screen::MAINMENU:
				MainMenu::init();
				break;
			case MoonPatrol::Program::Screen::CREDITS:

				break;
			default:
				break;
			}
		}

		static void uninit() {
			CloseWindow();
		}

		static void update() {
			while (!WindowShouldClose() && !programShouldClose) {
				switch (currentScreen) {
				case MoonPatrol::Program::Screen::GAME:

					break;
				case MoonPatrol::Program::Screen::MAINMENU:
					MainMenu::update();
					break;
				case MoonPatrol::Program::Screen::CREDITS:

					break;
				default:
					break;
				}
			}
		}

		static void init() {
			programShouldClose = false;
			InitWindow(static_cast<int>(screenWidth), static_cast<int>(screenHeight), TextFormat("MoonPatrol - Altamirano - v%s", programVersion));
			setScreen(Screen::MAINMENU);
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