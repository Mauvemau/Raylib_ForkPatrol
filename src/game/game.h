#pragma once

namespace MoonPatrol {
	namespace Game {

		void setPaused(bool value);
		void setScore(int value);

		bool getIsPaused();
		float getFloorAltitude();
		float getTime();
		int getScore();

		void update();
		void init();
	}
}