#pragma once

namespace MoonPatrol {
	namespace Obstacles {
		struct Obstacle {
			float x;
			float y;
			float width;
			float height;
			float speed;
		};

		Obstacle create();

		void draw(Obstacle obstacle);
		void update(Obstacle& obstacle);
		void init(Obstacle& obstacle, float y, float width, float height, float speed);
	}
}