#pragma once

namespace MoonPatrol {
	namespace Obstacles {
		struct Obstacle {
			float x;
			float y;
			float width;
			float height;
			float speed;
			bool dodged;
		};

		Obstacle create();

		void setSpeed(Obstacle& obstacle, float value);
		void setX(Obstacle& obstacle, float xPos);

		void drawHeader(Obstacle obstacle, const char* text);
		void handleDodgeLogic(Obstacle& obstacle);

		void draw(Obstacle obstacle);
		void update(Obstacle& obstacle);
		void init(Obstacle& obstacle, float y, float width, float height, float speed);
	}
}