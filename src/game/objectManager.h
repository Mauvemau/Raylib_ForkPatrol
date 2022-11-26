#pragma once

namespace MoonPatrol {
	namespace ObjectManager {

		// Pool Controls
		void removeBullet(int id);
		void addBullet(float x, float y, float radius, float directionAngle, float speed, bool hurtsPlayer);

		// General 
		void draw();
		void update();
		void init();
	}
}