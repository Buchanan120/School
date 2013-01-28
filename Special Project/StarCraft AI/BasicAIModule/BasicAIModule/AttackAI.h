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
#include "Brain.h"

using namespace BWAPI;
//includes-

namespace AI
{
	class Attack
	{
	private:
		//vector of all base locations
		std::vector<BWTA::BaseLocation *> baseLocations;
		BWTA::BaseLocation * nextBase;

		//wait clock for patrol
		clock_t endwait;

		//wait clock for fill bunker
		clock_t endwaitFillBunker;

		//wait time for patrol
		int waitSeconds;

		//wait time for fill bunker
		int waitSecondsFillBunker;
		int flamethrowerCount;
		bool isBaseUnderAttack;
		bool readyToPatrol;

		//patrol back to main base
		bool patrolMainBase;

		//patrol ready
		bool baseRightClicked;

	public:
		//important - overrides all attack unit commands
		bool allAttackUnitsDefend;
		Unit * target;

		Attack();
		void GetBaseLocations();
		inline void Timer();
		BWTA::BaseLocation * SetAttackPos();
		inline void UpdateUnitCount();
		inline void MoveToAttackPos(Brain * ourBrain);
		inline void CheckPatrol();
		inline void ResetUnitCount();
		inline void FillBunker();
		inline void DefendBase();
		inline void GetAttackTarget(Unit * unit);
		void StartLocationIsUnderAttack(Unit * unit);
	};

	Attack::Attack()
	{
		srand ( time(NULL) );

		//1 second
		waitSecondsFillBunker = 1;

		//15 seconds
		waitSeconds = 60;
		endwait = clock () + waitSeconds * CLOCKS_PER_SEC ;
		endwaitFillBunker = clock () + waitSecondsFillBunker * CLOCKS_PER_SEC ;
	}

	//call this one time in OnStart(). fills the vector of bases
	void Attack::GetBaseLocations()
	{
		const std::set<BWTA::BaseLocation *> bases = BWTA::getBaseLocations();
		std::set<BWTA::BaseLocation *>::const_iterator i;
		for (i = bases.begin(); i != bases.end(); i++)
		{
			if (!(*i)->isIsland() && !(*i)->isStartLocation())
			{
				baseLocations.push_back(*i);
			}
		} 
	}

	//switch unit patrol to another base every 30 seconds
	inline void Attack::Timer()
	{
		//patrol timer
		if (clock() > endwait)
		{
			if (patrolMainBase == false)
				patrolMainBase = true;
			else
				patrolMainBase = false;

			nextBase = Attack::SetAttackPos();
			baseRightClicked = false;
			endwait = (clock () + waitSeconds * CLOCKS_PER_SEC);
		}

		//bunker timer
		if (clock() > endwaitFillBunker)
		{
			FillBunker();
			endwaitFillBunker = (clock () + waitSecondsFillBunker * CLOCKS_PER_SEC);
		}
	}

	//choose a random non-island, base to send marines to
	BWTA::BaseLocation * Attack::SetAttackPos()
	{
		BWTA::BaseLocation * anyBase;
		int anyNum = rand() % baseLocations.size();
		anyBase = baseLocations[anyNum];
		return anyBase;
	}

	//count total firebats
	inline void Attack::UpdateUnitCount()
	{
		for each (Unit * unit in Broodwar->self()->getUnits())
		{
			if (unit->getType() == UnitTypes::Terran_Firebat)
			{
				flamethrowerCount++;
			}
		}
	}

	//send units to a base to guard and back to home base every other call
	inline void Attack::MoveToAttackPos(Brain * ourBrain)
	{
		//if every spot has been visited start at the beginning again
		if (ourBrain->nextPosition == ourBrain->memory.size())
		{
			ourBrain->nextPosition = 0;
		}

		//if units are ready
		if (readyToPatrol == true && baseRightClicked == false)
		{
			for each(Unit * unit in Broodwar->self()->getUnits())
			{
				if (unit->getType() != UnitTypes::Terran_SCV 
					&& unit->getType() != UnitTypes::Terran_Ghost
					&& unit->getType() != UnitTypes::Terran_Medic)
				{
					//if not time to go back to main base
					if (patrolMainBase == false)
					{
						//if there are remembered locations
						if (!ourBrain->memory.empty() 
							&& ourBrain->nextPosition < ourBrain->memory.size())
						{
							unit->attackMove(ourBrain->memory[ourBrain->nextPosition]);
							ourBrain->nextPosition++;
						}
						else
						{
							unit->attackMove(nextBase->getPosition());
						}
						
					}
					else
						unit->attackMove(Broodwar->self()->getStartLocation());
				}
			}
			baseRightClicked = true;
		}
	}

	//if enough units patrol (marines and FT's)
	inline void Attack::CheckPatrol()
	{
		if (flamethrowerCount >= 8)
			readyToPatrol = true;
		else
			readyToPatrol = false;
	}

	//reset all data at the top of onFrame()
	inline void Attack::ResetUnitCount()
	{
		flamethrowerCount = 0;
	}

	//fill bunker with marines
	inline void Attack::FillBunker()
	{
		int count = 0;
		bool needsAFirebat = true;
		Unit * saveMarineToRemove;

		// Iterate over the set of units
		for each(Unit * terranBunker in Broodwar->self()->getUnits())
		{
			needsAFirebat = true;

			// If we find a finished bunker and we have space in it
			if (terranBunker->getType() == UnitTypes::Terran_Bunker
				&& terranBunker->isCompleted() == true)
			{
				//check to see if the bunker needs a firebat
				//iterate through the bunkers units
				if (terranBunker->getLoadedUnits().empty() == false)
				{
					for each(Unit * terranBunkerUnit in terranBunker->getLoadedUnits())
					{
						if (terranBunkerUnit->getType() == UnitTypes::Terran_Firebat)
						{
							needsAFirebat = false;
						}
						if(terranBunkerUnit->getType() == UnitTypes::Terran_Marine )
						{
							saveMarineToRemove = terranBunkerUnit;
						}
					}
				}

				// Iterate over the set of units and load in a marine
				for each(Unit * marineOrFirebat in Broodwar->self()->getUnits())
				{
					// If we find a Marine outside of a bunker
					if (marineOrFirebat->getType() == UnitTypes::Terran_Marine
						&& marineOrFirebat->isLoaded() == false
						&& count < (4 - terranBunker->getLoadedUnits().size()))
					{
						marineOrFirebat->load(terranBunker);
						count++;
					}

					//check to see if the bunker needs a fire bat and if this unit is a firebat
					//this only happens if the bunker has room
					if (needsAFirebat == true 
						&& marineOrFirebat->getType() == UnitTypes::Terran_Firebat
						&& marineOrFirebat->isLoaded() == false
						&& terranBunker->getLoadedUnits().size() != 4)
					{
						marineOrFirebat->load(terranBunker);
						count++;
						needsAFirebat = false;
					}

					//check to see if the bunker needs a fire bat and if this unit is a firebat
					//this only happens if the bunker does NOT have room
					if (needsAFirebat == true 
						&& marineOrFirebat->getType() == UnitTypes::Terran_Firebat
						&& marineOrFirebat->isLoaded() == false
						&& terranBunker->getLoadedUnits().size() == 4)
					{
						terranBunker->unload(saveMarineToRemove);
						marineOrFirebat->load(terranBunker);
						count++;
						needsAFirebat = false;
					}
				}
			}
			count = 0;
		}
	}

	//1st Priority for all units
	//if in view range and in region of base send all units
	inline void Attack::DefendBase()
	{
		if (allAttackUnitsDefend == true)
		{
			Broodwar->printf("Defending");
			for each(Unit * attackUnit in Broodwar->self()->getUnits())
			{
				attackUnit->attackMove(target->getPosition());
			}
			allAttackUnitsDefend = false;
		}
	}

	//save the target to attack in our class so we can refer it it's position
	inline void Attack::GetAttackTarget(Unit * unit)
	{
		target = unit;
	}

	//check the region inside of home base to see if there is an enemy 
	//if so all units defend
	void Attack::StartLocationIsUnderAttack(Unit * unit)
	{
		//Is enemy in sight?
		if (Broodwar->self()->isEnemy(unit->getPlayer()))
		{ 
			BWTA::Region* startBaseRegion;
			startBaseRegion = BWTA::getStartLocation(BWAPI::Broodwar->self())->getRegion();

			//Is enemy in region?
			if (startBaseRegion->getPolygon().isInside(unit->getPosition()))
			{
				allAttackUnitsDefend = true;
				GetAttackTarget(unit);
			}
		}
	}
}