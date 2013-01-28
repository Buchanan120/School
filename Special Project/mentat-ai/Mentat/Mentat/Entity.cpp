#include "Entity.h"
using namespace AI;

Entity::Entity(BWAPI::Unit* unit)
{
	unitType = unit->getType();
	groundWeapon = *unitType.groundWeapon();
	airWeapon = *unitType.airWeapon();
	race = unitType.getRace();
	identifier = unit->getID();
	position = unit->getTilePosition();
	hitPoints = unit->getHitPoints();
	shields = unit->getShields();
	energy = unit->getEnergy();
	resourceCost.first = unitType.mineralPrice();
	resourceCost.second = unitType.gasPrice();
}

void Entity::onUnitShow(BWAPI::Unit* unit)
{
	// update values
	position = unit->getTilePosition();
	hitPoints = unit->getHitPoints();
	shields = unit->getShields();
	energy = unit->getEnergy();
}

void Entity::onUnitMorph(BWAPI::Unit* unit)
{
	unitType = unit->getType();
	hitPoints = unit->getHitPoints();
	shields = unit->getShields();
	energy = unit->getEnergy();
	resourceCost.first += unitType.mineralPrice();
	resourceCost.second += unitType.gasPrice();
}