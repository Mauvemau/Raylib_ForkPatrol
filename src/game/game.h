#pragma once

namespace MoonPatrol {
	namespace Game {

		void setPaused(bool value);

		bool getIsPaused();
		float getFloorAltitude();

		void update();
		void init();
	}
}