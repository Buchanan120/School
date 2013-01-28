//include header file once
#pragma once

//includes
#include <BWAPI.h>
#include <BWTA.h>
#include <Arbitrator.h>
#include <WorkerManager.h>
#include <SupplyManager.h>
#include <BuildManager.h>
#include <BuildOrderManager.h>
#include <TechManager.h>
#include <UpgradeManager.h>
#include <BaseManager.h>
#include <ScoutManager.h>
#include <vector>
#include <queue>
#include <stdio.h>
#include <time.h>

using namespace BWAPI;
//includes-

namespace AI
{
	class Rebuild
	{
	private:
		int bunkerCount;
		int commandcenterCount;
		int marineCount;
		int flamethrowerCount;
		int supplydepotCount;
		int missileTurretCount;

	public:
		int scvCount;
		int numRebuildBunker, numRebuildCommandCenter, numRebuildMarine;
		int numRebuildFlameThrower, numRebuildSupplyDepot;
		int numRebuildSCV;
		int numRebuildMissileTurret;
		Rebuild();
		void unitCreated(Unit * unit);
		void unitDestroyed(Unit * unit);
		bool canBeCreated(Unit * unit);

	};

	//sets num times to rebuild unit
	Rebuild::Rebuild()
	{
		 numRebuildBunker = 10;
		 numRebuildCommandCenter = 1;
		 numRebuildMarine = 21;
		 numRebuildFlameThrower = 21;
		 numRebuildSupplyDepot = 0;
		 numRebuildSCV = 15;
		 numRebuildMissileTurret = 12;
	}
	//add 1 to unit count
	void Rebuild::unitCreated(Unit * unit)
	{
		if(unit->getPlayer() == Broodwar->self() && unit->getType() == UnitTypes::Terran_Firebat)
		{
			flamethrowerCount++;
		}
		if(unit->getPlayer() == Broodwar->self() && unit->getType() == UnitTypes::Terran_Command_Center)
		{
			commandcenterCount++;
		}
		if(unit->getPlayer() == Broodwar->self() && unit->getType() == UnitTypes::Terran_Supply_Depot)
		{
			supplydepotCount++;
		}
		if(unit->getPlayer() == Broodwar->self() && unit->getType() == UnitTypes::Terran_Marine)
		{
			marineCount++;
		}
		if(unit->getPlayer() == Broodwar->self() && unit->getType() == UnitTypes::Terran_Bunker)
		{
			bunkerCount++;
		}
		if(unit->getPlayer() == Broodwar->self() && unit->getType() == UnitTypes::Terran_Missile_Turret)
		{
			missileTurretCount++;
		}
	}

	//-1 to unit count
	void Rebuild::unitDestroyed(Unit * unit)
	{
		if(unit->getPlayer() == Broodwar->self() && unit->getType() == UnitTypes::Terran_Firebat)
		{
			flamethrowerCount--;
			numRebuildFlameThrower--;
		}
		if(unit->getPlayer() == Broodwar->self() && unit->getType() == UnitTypes::Terran_Command_Center)
		{
			commandcenterCount--;
			numRebuildCommandCenter--;
		}
		if(unit->getPlayer() == Broodwar->self() && unit->getType() == UnitTypes::Terran_Supply_Depot)
		{
			supplydepotCount--;
			numRebuildSupplyDepot--;
		}
		if(unit->getPlayer() == Broodwar->self() && unit->getType() == UnitTypes::Terran_Marine)
		{
			marineCount--;
			numRebuildMarine--;
		}

		if(unit->getPlayer() == Broodwar->self() && unit->getType() == UnitTypes::Terran_Bunker)
		{
			bunkerCount--;
			numRebuildBunker--;
		}

		if(unit->getPlayer() == Broodwar->self() && unit->getType() == UnitTypes::Terran_Missile_Turret)
		{
			missileTurretCount--;
			numRebuildMissileTurret--;
		}
	}

	//returns true if a unit can be rebuilt.
	//defaults to false
	bool Rebuild::canBeCreated(Unit * unit)
	{
		if(unit->getPlayer() == Broodwar->self() && unit->getType() == UnitTypes::Terran_Firebat)
		{
			if (numRebuildFlameThrower > 0)
			{
				return true;
			}
			else
			{
				return false;
			}
			
		}
		if(unit->getPlayer() == Broodwar->self() && unit->getType() == UnitTypes::Terran_Command_Center)
		{
			if (numRebuildCommandCenter > 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		if(unit->getPlayer() == Broodwar->self() && unit->getType() == UnitTypes::Terran_Supply_Depot)
		{
			if (numRebuildSupplyDepot > 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		if(unit->getPlayer() == Broodwar->self() && unit->getType() == UnitTypes::Terran_Marine)
		{
			if (numRebuildMarine > 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		if(unit->getPlayer() == Broodwar->self() && unit->getType() == UnitTypes::Terran_Bunker)
		{
			if (numRebuildBunker > 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		if(unit->getPlayer() == Broodwar->self() && unit->getType() == UnitTypes::Terran_Missile_Turret)
		{
			if (numRebuildMissileTurret > 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		//default to cannot be rebuilt
		return false;
	}
}