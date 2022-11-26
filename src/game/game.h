#pragma once

namespace MoonPatrol {
	namespace Game {

		void setGameMode(bool value);
		void setPaused(bool value);
		void setScore(int value);

		float getBeginTime();
		bool getIsPaused();
		float getFloorAltitude();
		float getTime();
		int getScore();

		void update();
		void init();
	}
}