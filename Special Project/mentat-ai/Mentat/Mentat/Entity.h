// Entity.h
//	The entity object contains information about a specific unit
//		and is used by agents and the PercievedReality.

// insure that this header file is not included more than once
#pragma once
#ifndef ENTITY_H_
#define ENTITY_H_

#include "BWAPI.h"

namespace AI
{
	class Entity
	{
	private:
		BWAPI::WeaponType groundWeapon;
		BWAPI::WeaponType airWeapon;
	public:
		BWAPI::UnitType unitType;
		BWAPI::Race race;
		int identifier;
		BWAPI::TilePosition position;
		int hitPoints;
		bool isEnemy;
		int shields;
		int energy;
		// first is mineralCost, second is gasCost
		std::pair<int, int> resourceCost;

		Entity(BWAPI::Unit* gameUnit);
		~Entity();
		void onUnitDestroy(BWAPI::Unit* unit);
		void onUnitMorph(BWAPI::Unit* unit);
		void onUnitShow(BWAPI::Unit* unit);
		void onUnitHide(BWAPI::Unit* unit);
		void onUnitRenegade(BWAPI::Unit* unit);
	};
}

#endif