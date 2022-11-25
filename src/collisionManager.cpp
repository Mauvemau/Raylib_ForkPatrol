#include "collisionManager.h"

namespace MoonPatrol {
	namespace Collisions {

		// Private

		// --

		// Public
		bool pointRectCollision(float pointX, float pointY, float recX, float recY, float recWidth, float recHeight) {
			return (pointX > recX && pointX < (recX + recWidth) && pointY > recY && pointY < (recY + recHeight));
		}
	}
}