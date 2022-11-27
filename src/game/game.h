#pragma once

namespace MoonPatrol {
	namespace Game {

		void setObstaclesDodged(int value);
		void setEnemiesKilled(int value);
		void setGameMode(bool value);
		void setPaused(bool value);
		void setScore(int value);

		int getObstaclesDodged();
		int getEnemiesKilled();
		float getBeginTime();
		bool getIsPaused();
		float getFloorAltitude(float xPos);
		float getFloorAltitude();
		float getTime();
		int getScore();

		void update();
		void init();
	}
}