#include "objectManager.h"

// Objects
#include "bullet.h"

// Managers
#include "collisionManager.h"

// Lib
#include <iostream>

using namespace std;

namespace MoonPatrol {
	namespace ObjectManager {

		// -- Private

		const int maxBullets = 100;
		Bullets::Bullet bullets[maxBullets];
		int activeBullets;

		// --

		// -- Public

		// Getters

		// Pool Controls
		void removeBullet(int id) {
			if (id < activeBullets) {
				bullets[id] = bullets[activeBullets - 1];
				activeBullets--;
			}
		}

		void addBullet(float x, float y, float radius, float directionAngle, float speed, bool hurtsPlayer) {
			if (activeBullets < maxBullets) {
				Bullets::init(bullets[activeBullets], x, y, radius, directionAngle, speed, hurtsPlayer);
				activeBullets++;
			}
		}

		// General 
		void draw() {
			// Bullets
			for (int i = 0; i < activeBullets; i++) {
				Bullets::draw(bullets[i]);
			}
		}

		void update() {
			// Bullets
			for (int i = 0; i < activeBullets; i++) {
				Bullets::update(bullets[i]);
				if (Collisions::bulletWall(bullets[i])) {
					removeBullet(i);
				}
			}
		}

		void init() {
			// Bullets
			for (int i = 0; i < maxBullets; i++) {
				bullets[i] = Bullets::create();
			}
			activeBullets = 0;
		}
	}
}