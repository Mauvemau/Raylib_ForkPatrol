#include "weapon.h"

#include <iostream>

#include "game.h"
#include "object_manager.h"
#include "asset_manager.h"

using namespace std;

namespace MoonPatrol {
	namespace Weapons {

		// Private

		// --

		// Public

		Weapon create() {
			Weapon weapon;
			weapon.fireRate = 0;
			weapon.firePower = 0;
			weapon.bulletCaliber = 0;
			weapon.hurtsPlayer = 0;
			weapon.lastShot = 0;
			return weapon;
		}

		Weapon createWeaponFromTemplate(Types type) {
			Weapon weapon;
			switch (type)
			{
			case MoonPatrol::Weapons::Types::GUN:
				weapon.fireRate = .25f;
				weapon.firePower = static_cast<float>(GetScreenHeight() * .9);
				weapon.bulletCaliber = static_cast<float>(GetScreenHeight() * .005);
				break;
			case MoonPatrol::Weapons::Types::RIFLE:
				weapon.fireRate = .15f;
				weapon.firePower = static_cast<float>(GetScreenHeight() * .9);
				weapon.bulletCaliber = static_cast<float>(GetScreenHeight() * .0025);
				break;
			default:
				weapon.fireRate = .0f;
				weapon.firePower = .0f;
				weapon.bulletCaliber = .0f;
				cout << "Invalid weapon type!\n";
				break;
			}
			weapon.hurtsPlayer = false;
			return weapon;
		}

		void shoot(Weapon& weapon, float x, float y, float direction, Color color) {
			if (weapon.fireRate > 0) {
				if (weapon.fireRate < (Game::getTime() - weapon.lastShot)) {
					weapon.lastShot = Game::getTime();
					ObjectManager::addBullet(x, y, weapon.bulletCaliber, direction, weapon.firePower, weapon.hurtsPlayer, color);
					Assets::PlayAudio(Assets::Audio::SHOOT, .5f);
				}
			}
		}

		void init(Weapon& weapon, float fireRate, float firePower, float bulletCaliber, bool hurtsPlayer) {
			weapon = create();
			weapon.fireRate = fireRate;
			weapon.firePower = firePower;
			weapon.bulletCaliber = bulletCaliber;
			weapon.hurtsPlayer = hurtsPlayer;
		}
	}
}