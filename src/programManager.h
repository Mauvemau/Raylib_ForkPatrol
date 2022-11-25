#pragma once

namespace MoonPatrol {
	namespace Program {
		enum class Screen {
			GAME,
			MAINMENU,
			CREDITS
		};

		const char* getVersion();

		void close();
		void setScreen(Screen status);
		void start();
	}
}