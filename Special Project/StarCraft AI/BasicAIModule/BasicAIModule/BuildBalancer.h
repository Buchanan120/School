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
	class BuildBalancer
	{
	private:
		//build size limits number of units
		//troops
		int scvCountLimit;
		int marineCountLimit;
		int firebatCountLimit;
		int goliathCountLimit;
		int ghostsCountLimit;
		int siegeTankCountLimit;
		int wraithCountLimit;
		int medicCountLimit;

		//if the unit can be built
		bool ready[8];
		bool unitsComplete;

	public:

		BuildBalancer();
		void BuildBalancer::Ready(BuildOrderManager * buildOrderManager, Unit * unit);
	};

	
	BuildBalancer::BuildBalancer()
	{
		//build size limits
		//troops
		scvCountLimit = 24;
		marineCountLimit = 15;
		firebatCountLimit = 12;
		goliathCountLimit = 6;
		ghostsCountLimit = 0;
		siegeTankCountLimit = 6;
		wraithCountLimit = 0;
		medicCountLimit = 0;
	}

	//rebuilds what's missing
	void BuildBalancer::Ready(BuildOrderManager * buildOrderManager, Unit * unit)
	{
		if (unitsComplete == false)
		{
			//buildings
			bool commandCenter, barracks, academy;
			bool factory, scienceFacility, covertOps, starPort;

			//what buildings are built
			for each (Unit * building in Broodwar->self()->getUnits())
			{
				if (building->getType() == UnitTypes::Terran_Command_Center && building->isCompleted())
					commandCenter = true;
				else if (building->getType() == UnitTypes::Terran_Barracks && building->isCompleted())
					barracks = true;
				else if (building->getType() == UnitTypes::Terran_Academy && building->isCompleted())
					academy = true;
				else if (building->getType() == UnitTypes::Terran_Factory && building->isCompleted())
					factory = true;
				else if (building->getType() == UnitTypes::Terran_Science_Facility && building->isCompleted())
					scienceFacility = true;
				else if (building->getType() == UnitTypes::Terran_Covert_Ops && building->isCompleted())
					covertOps = true;
				else if (building->getType() == UnitTypes::Terran_Starport && building->isCompleted())
					starPort = true;
			}

			//SCVs
			if (commandCenter == true && ready[0] == false)
			{
				buildOrderManager->buildAdditional(scvCountLimit, UnitTypes::Terran_SCV, 100);
				ready[0] = true;
			}

			//marines
			if (barracks == true && ready[1] == false)
			{
				buildOrderManager->buildAdditional(marineCountLimit, UnitTypes::Terran_Marine, 100);
				ready[1] = true;
			}

			//Firebat
			if (barracks == true && academy == true && ready[2] == false)
			{
				buildOrderManager->buildAdditional(firebatCountLimit, UnitTypes::Terran_Firebat, 100);
				ready[2] = true;
			}

			//Goliath
			if (barracks == true && academy == true && factory == true && ready[3] == false)
			{
				buildOrderManager->buildAdditional(goliathCountLimit, UnitTypes::Terran_Goliath, 100);
				ready[3] = true;
			}

			//Ghost
			if (barracks == true && academy == true && scienceFacility == true && covertOps == true && ready[4] == false)
			{
				buildOrderManager->buildAdditional(ghostsCountLimit, UnitTypes::Terran_Ghost, 100);
				ready[4] = true;
			}

			//siege tanks
			if (barracks == true && factory == true && ready[5] == false)
			{
				buildOrderManager->buildAdditional(siegeTankCountLimit, UnitTypes::Terran_Siege_Tank_Tank_Mode, 100);
				ready[5] = true;
			}

			//Wraith
			if (factory == true && starPort == true && ready[6] == false)
			{
				buildOrderManager->buildAdditional(wraithCountLimit, UnitTypes::Terran_Wraith, 100);
				ready[6] = true;
			}

			//Medic
			if (factory == true && barracks == true && ready[7] == false)
			{
				buildOrderManager->buildAdditional(medicCountLimit, UnitTypes::Terran_Medic, 100);
				ready[7] = true;
			}

			//check to see if all units have been made
			for (int i = 0; i < 7; i++)
				if (ready[i] == false)
					unitsComplete = false;
		}
	}
}