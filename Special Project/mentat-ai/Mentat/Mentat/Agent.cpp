#include "Agent.h"
#include "Squad.h"
#include "Entity.h"
using namespace AI;

Agent::Agent(Squad* squad, BWAPI::Unit* unitToControl)
{
	this.self = unitToControl;
	this.squad = squad;
}

void Agent::onUnitDestroy(BWAPI::Unit *unit)
{
	if (unit->getID() == self->getID())
		~Agent();
}

void Agent::act()
{
	nearbyUnits = BWTA::Broodwar->enemy()->getUnits();
	for each(BWTA::Unit* unit in nearbyUnits)
	{
		if (unit->getDistance() <= sightRange)
			analyze(unit);
	}
}

void Agent::analyze(BWAPI::Unit* unit)
{
	if (unit.getHitPoints() < self.getHitPoints())
	{
		attack(unit);
	}
}

void Agent::attack(BWTA::Unit * unit)
{
	self.attack(unit);
}

void Agent::run()
{
	move(squad->getRegroupPosition());
}