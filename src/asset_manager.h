#pragma once

#include "raylib.h"

namespace MoonPatrol {
	namespace Assets {
		enum class Audio {
			SHOOT,
			EXPLOSION,
			HURT,
			PAUSE,
			SCORE,
			COUNT
		};

		enum class Sprite {
			JEEP_BODY,
			JEEP_WHEEL,
			DRONE,
			BULLET_TRAIL,
			JEEP_BODY_COLORLESS,
			JEEP_BODY_SILHOUETTE,
			COUNT
		};

		void PlayAudio(Audio sound, float volume);
		void DrawSprite(Sprite sprite, Vector2 pos, Vector2 size, Vector2 pivot, float rotation, Color tint);

		Texture2D GetSprite(Sprite sprite);

		void Unload();
		void Load();
	}
}