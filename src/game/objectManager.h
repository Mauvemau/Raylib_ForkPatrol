#pragma once

namespace MoonPatrol {
	namespace ObjectManager {

		int getActiveEnemies();

		// Pool Controls
		void removeBullet(int id);
		void addBullet(float x, float y, float radius, float directionAngle, float speed, bool hurtsPlayer);

		void removeEnemy(int id);
		void addEnemy(float center, float hitRadius, float speed, int direction);

		// General 
		void draw();
		void update();
		void init();
	}
}