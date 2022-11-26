#pragma once

namespace MoonPatrol {
	namespace Game {

		void setPaused(bool value);

		bool getIsPaused();
		float getFloorAltitude();
		float getTime();

		void update();
		void init();
	}
}