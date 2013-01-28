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
#include "BuildBalancer.h"

using namespace BWAPI;
//includes

namespace AI
{
	class Repair
	{
	private:
		int NumSCVs;
		clock_t endWait;
		int waitSeconds;
		bool canClick;
		
	public:
		Repair();
		void Timer();
		void CountSCVs();
		void CheckForDamage();
		void RepairBuilding(Unit * target);
	};
	
	Repair::Repair()
	{
		waitSeconds = 3;
		endWait = clock () + waitSeconds * CLOCKS_PER_SEC ;
	}
	//timer for repair clicks
	void Repair::Timer()
	{
		if (clock() > endWait)
		{
			CountSCVs();
			canClick = true;
			endWait = (clock () + waitSeconds * CLOCKS_PER_SEC);
			CheckForDamage();
		}
	}

	void Repair::CountSCVs()
	{
		//reset scvs
		NumSCVs = 0;

		//count scvs
		for each(Unit * allUnits in Broodwar->self()->getUnits())
		{
			if (allUnits->getType() == UnitTypes::Terran_SCV)
			{
				NumSCVs++;
			}
		}
	}

	//only reapirs bunkers at the moment
	void Repair::CheckForDamage()
	{
		if (NumSCVs > 0 && canClick == true)
		{
			for each(Unit * building in Broodwar->self()->getUnits())
			{
				if (building->getType().isBuilding() == true && building->getType() == UnitTypes::Terran_Bunker)
				{
					if (building->isCompleted() == true)
					{
						//maxHP of a bunker
						int maxHP = 350;
						int HP = (building->getHitPoints() /256);
						if (building->getType() == UnitTypes::Terran_Bunker)
						{
							Broodwar->printf( "HP: %d", HP);
							Broodwar->printf( "maxHP: %d", maxHP);
						}
						
						if (HP < maxHP)
						{
							RepairBuilding(building);
						}
					}
				}	
			}
			canClick = false;
		}
	}

	void Repair::RepairBuilding(Unit * target)
	{	 
		for each(Unit* unit in Broodwar->self()->getUnits())
		{
			if(unit->getType() == UnitTypes::Terran_SCV)
			{
				unit->repair(target);
				return;
			}
		}
	}
}