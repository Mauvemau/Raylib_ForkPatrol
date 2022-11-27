#include "asset_manager.h"

#include <iostream>

using namespace std;

namespace MoonPatrol {
	namespace Assets {
		const int soundAmount = static_cast<int>(Audio::COUNT);
		Sound sounds[soundAmount];

		const int spriteAmount = static_cast<int>(Sprite::COUNT);
		Texture2D sprites[spriteAmount];

		void UnloadAudios();
		void LoadAudio(const char* path, int id);
		void LoadAudios();
		void UnloadSprites();
		void LoadSprite(const char* path, int id);
		void LoadSprites();
		void InitAudio();

		// --

		void LoadAudio(const char* path, int id) {
			sounds[id] = LoadSound(path);
		}

		void UnloadAudios() {
			for (int i = 0; i < soundAmount; i++) {
				UnloadSound(sounds[i]);
			}
		}

		void LoadAudios() {
			for (int i = 0; i < soundAmount; i++) {
				switch ((Audio)i) {
				case Audio::SHOOT:
					LoadAudio("res/sounds/shoot.wav", i);
					break;
				case Audio::EXPLOSION:
					LoadAudio("res/sounds/explosion.wav", i);
					break;
				case Audio::HURT:
					LoadAudio("res/sounds/hurt.wav", i);
					break;
				case Audio::PAUSE:
					LoadAudio("res/sounds/pause.wav", i);
					break;
				case Audio::SCORE:
					LoadAudio("res/sounds/score.wav", i);
					break;
				default:
					cout << "[!] Invalid Audio: AssetLoader - LoadAudios\n";
					break;
				}
			}
		}

		void LoadSprite(const char* path, int id) {
			sprites[id] = LoadTexture(path);
		}

		void UnloadSprites() {
			for (int i = 0; i < spriteAmount; i++) {
				UnloadTexture(sprites[i]);
			}
		}

		void LoadSprites() {
			for (int i = 0; i < spriteAmount; i++) {
				switch ((Sprite)i) {
				case Sprite::JEEP_BODY:
					LoadSprite("res/sprites/jeep_body.png", i);
					break;
				case Sprite::JEEP_WHEEL:
					LoadSprite("res/sprites/jeep_wheel.png", i);
					break;
				case Sprite::DRONE:
					LoadSprite("res/sprites/drone.png", i);
					break;
				case Sprite::BULLET_TRAIL:
					LoadSprite("res/sprites/bullet_trail.png", i);
					break;
				case Sprite::JEEP_BODY_COLORLESS:
					LoadSprite("res/sprites/jeep_body_colorless.png", i);
					break;
				case Sprite::JEEP_BODY_SILHOUETTE:
					LoadSprite("res/sprites/jeep_body_silhouette.png", i);
					break;
				default:
					cout << "[!] Invalid Sprite: AssetLoader - LoadSprites\n";
					break;
				}
			}
		}

		void InitAudio() {
			InitAudioDevice();
		}

		// Global

		void DrawSprite(Sprite sprite, Vector2 pos, Vector2 size, Vector2 pivot, float rotation, Color tint) {
			Texture2D texture = Assets::GetSprite(sprite);
			int textureWidth = texture.width;
			int textureHeight = texture.height;

			DrawTexturePro(texture,
				{ 0.0f, 0.0f, static_cast<float>(textureWidth), static_cast<float>(textureHeight) },
				{ pos.x, pos.y, size.x, size.y },
				{ pivot.x, pivot.y },
				rotation, tint);
		}

		void PlayAudio(Audio sound, float volume) {
			SetSoundVolume(sounds[static_cast<int>(sound)], volume);
			PlaySound(sounds[static_cast<int>(sound)]);
		}

		Texture2D GetSprite(Sprite sprite) {
			return sprites[static_cast<int>(sprite)];
		}

		void Unload() {
			UnloadAudios();
			UnloadSprites();
		}

		void Load() {
			InitAudio();
			LoadAudios();
			LoadSprites();
		}
	}
}