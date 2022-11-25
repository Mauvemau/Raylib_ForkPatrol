#pragma once

namespace MoonPatrol {
	namespace MainMenu {
		enum class Options {
			PLAY,
			CREDITS,
			QUIT,
			COUNT
		};

		void update();
		void init();
	}
}