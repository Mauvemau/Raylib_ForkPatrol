#pragma once

namespace MoonPatrol {
	namespace Program {
		enum class Screen {
			GAME,
			MAINMENU,
			CREDITS,
			GAMEMODE,
			GAMEOVER
		};

		const char* getVersion();

		void close();
		void setScreen(Screen status);
		void start();
	}
}