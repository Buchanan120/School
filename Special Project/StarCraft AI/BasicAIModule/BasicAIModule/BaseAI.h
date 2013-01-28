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
#include <stdio.h>
#include <time.h>
#include "MyArray.h"

using namespace BWAPI;

namespace AI
{
	class Base
	{
	private:
		bool isMainBaseFinished;
		bool allUpgradesAreComplete;
		// TilePosition for Supply Depots
		TilePosition secondBaseChokepoint;
		bool isIslandBase;
		MyArray<BWAPI::Unit*> commandCenters;
	public:
		int expanded;
		Base();
		void GetNextBaseLocation();
		void BuildMainBase(BaseManager* baseManager, BuildOrderManager* buildOrderManager);
		//void BuildSecondBase(BaseManager* baseManager, BuildOrderManager* buildOrderManager);
		void BuildNextBase(BaseManager* baseManager, BuildOrderManager* buildOrderManager);
		void BuildIslandBase(BaseManager* baseManager, BuildOrderManager* buildOrderManager);
		void Upgrades(Unit * unit);
		bool LocationOccupiedByUs(BWTA::BaseLocation* baseLocation);
		MyArray<BWTA::BaseLocation*> baseLocations;
		int mineralThreshold[4];
		void OnCommandCenterCreate(BWAPI::Unit *unit);
	};

	Base::Base()
	{
	}

	bool Base::LocationOccupiedByUs(BWTA::BaseLocation* baseLocation)
	{
		std::set<Unit*> ourUnits=Broodwar->self()->getUnits();
		for each(Unit* unit in ourUnits)
		{
			if(unit->getType() == UnitTypes::Terran_Command_Center
					&& unit->getPosition() == baseLocation->getPosition())
			{
				return true;
			}
		}
		// We've checked all the units, and none of the Coommand Centers were there.
		return false;
	}
	void Base::GetNextBaseLocation()
	{	
		const std::set<BWTA::BaseLocation *> bases = BWTA::getBaseLocations();
		double shortest_distance = 1.79769e+308; // max of double
		BWTA::BaseLocation* closestBase;

		// Here is some code to tell it where to put the next Command Center
		for each(BWTA::BaseLocation * base in bases)
		{
			if (base->isIsland() && !LocationOccupiedByUs(base))
			{
				isIslandBase = true;
				closestBase = base;
				Broodwar->printf("Found island base");
				break;
			}
			
			// We're only interested in non-island bases with gas that we haven't built on yet
			if (!base->isIsland() && !base->isMineralOnly())
			{
				double distance = baseLocations[0]->getTilePosition().getDistance(base->getTilePosition());
				
				// Add the closest one
				if (distance < shortest_distance && !LocationOccupiedByUs(base)) 
				{
					shortest_distance = distance;
					closestBase = base;
				}
			}
		}
		//if(shortest_distance == 1.79769e+308)
		//{
		//	for each(BWTA::BaseLocation * base in bases)
		//	{
		//		// We're only interested in non-island bases with gas that we haven't built on yet
		//		if (!base->isIsland())
		//		{
		//			double distance = baseLocations[0]->getTilePosition().getDistance(base->getTilePosition());
		//			
		//			// Add the closest one
		//			if (distance < shortest_distance && !LocationOccupiedByUs(base)) 
		//			{
		//				shortest_distance = distance;
		//				closestBase = base;
		//			}
		//		}
		//	}
		//}
		
		baseLocations.Add(closestBase);
		//baseLocations.RemoveDuplicates();
		Broodwar->printf("Adding base to baseLocations");
		//}
	}

	void Base::BuildMainBase(BaseManager* baseManager, BuildOrderManager* buildOrderManager)
	{
		if (isMainBaseFinished == false)
		{
			mineralThreshold[0] = 3000;
			mineralThreshold[1] = 8000;
			mineralThreshold[2] = 15000;
			mineralThreshold[3] = 20000;


			// Create a set of chokepoints
			BWTA::Region* homeRegion = BWTA::getStartLocation(BWAPI::Broodwar->self())->getRegion();
			std::set<BWTA::Chokepoint*> mainBaseChokepoints= homeRegion->getChokepoints();

			// Start base
			baseLocations.Add(BWTA::getStartLocation(BWAPI::Broodwar->self()));

			// Find the place to build Barracks
			// Near the chokepoint to the rest of the map
			BWTA::Chokepoint* baseExit;
			for each(BWTA::Chokepoint* chokepoint in mainBaseChokepoints)
			{
				baseExit = chokepoint;
				break;
			}

			/*
			int chokePointX = baseExit->getCenter().x();
			int chokePointY = baseExit->getCenter().y();
			int mainBaseUnitsX = baseLocations[0]->getTilePosition().x();
			int mainBaseUnitsY = baseLocations[0]->getTilePosition().y();

			mainBaseUnitsX += (chokePointX - mainBaseUnitsX)/2;
			mainBaseUnitsY += (chokePointY - mainBaseUnitsY)/2;
			TilePosition mainBaseUnits(mainBaseUnitsX, mainBaseUnitsY);
			*/
			
			//const std::set<BWTA::BaseLocation *> bases = BWTA::getBaseLocations();
			//double shortest_distance = 1.79769e+308; // max of double
			//std::set<BWTA::BaseLocation *>::const_iterator i;

			// First base expansion
			GetNextBaseLocation();

			// Create a set of chokepoints for second base
			BWTA::Region* secondBaseRegion = baseLocations[1]->getRegion();
			std::set<BWTA::Chokepoint*> secondBase = secondBaseRegion->getChokepoints();
			double longestDistance = 0;

			// Decide where to build the supply depots
			for each(BWTA::Chokepoint* chokepoint in secondBase)
			{
				double distance = baseLocations[0]->getTilePosition().getDistance(chokepoint->getCenter());
				if(distance > longestDistance) {
					longestDistance = distance;
					secondBaseChokepoint = chokepoint->getCenter();
				}
			}

			int secondBaseX = baseLocations[1]->getTilePosition().x();
			int secondBaseY = baseLocations[1]->getTilePosition().y();
			int secondBaseChokepointX = secondBaseChokepoint.x();
			int secondBaseChokepointY = secondBaseChokepoint.y();

			secondBaseChokepointX = secondBaseX + (8*(secondBaseChokepointX - secondBaseX)) / 10;
			secondBaseChokepointY = secondBaseY + (8*(secondBaseChokepointY - secondBaseY)) / 10;
			secondBaseChokepoint = *(new TilePosition(secondBaseChokepointX, secondBaseChokepointY));

			buildOrderManager->buildAdditional(2, UnitTypes::Terran_Barracks, 80/*, mainBaseUnits*/);
			
			// As far as I know, this loop should only run once,
			// but if there are multiple points, it'll cover them.
			for each (BWTA::Chokepoint* point in mainBaseChokepoints)
			{
				buildOrderManager->build(5, UnitTypes::Terran_Bunker, 74, point->getCenter());
				buildOrderManager->build(1, UnitTypes::Terran_Missile_Turret, 68, point->getCenter());
				buildOrderManager->build(20, UnitTypes::Terran_Marine, 74);
			}

			buildOrderManager->buildAdditional(1, UnitTypes::Terran_Refinery, 72);
			buildOrderManager->buildAdditional(1, UnitTypes::Terran_Academy, 70);
			buildOrderManager->buildAdditional(1, UnitTypes::Terran_Engineering_Bay, 70);
			buildOrderManager->buildAdditional(1, UnitTypes::Terran_Machine_Shop, 70);

			for each (BWTA::Chokepoint* point in mainBaseChokepoints)
			{
				buildOrderManager->build(2, UnitTypes::Terran_Missile_Turret, 68, point->getSides().first);
			}
			//buildOrderManager->buildAdditional(1, UnitTypes::Terran_Comsat_Station, 60);
			buildOrderManager->buildAdditional(1, UnitTypes::Terran_Factory, 60/*, mainBaseUnits*/);
			//buildOrderManager->buildAdditional(1, UnitTypes::Terran_Starport, 50/*, mainBaseUnits*/);
			buildOrderManager->buildAdditional(2, UnitTypes::Terran_Armory, 40);
			buildOrderManager->buildAdditional(1, UnitTypes::Terran_Science_Facility, 31);
			//buildOrderManager->buildAdditional(1, UnitTypes::Terran_Covert_Ops, 30);
			//buildOrderManager->buildAdditional(1, UnitTypes::Terran_Science_Vessel, 23);
			isMainBaseFinished = true;
		}
	}


	void Base::BuildNextBase(BaseManager* baseManager, BuildOrderManager* buildOrderManager)
	{
		if (!isIslandBase)
		{
			// Build Command Center
			baseManager->expand(baseLocations[expanded + 1]);
			Broodwar->printf("Building base number %i after mining %i minerals", expanded + 1, Broodwar->self()->cumulativeMinerals());
	
			// Pick location for next base
			GetNextBaseLocation();
	
			expanded++;
	
			// Build defenses
			// One Bunker and one Turret at the Command Center
			buildOrderManager->buildAdditional(2, UnitTypes::Terran_Bunker, 80, baseLocations[expanded]->getTilePosition());
			buildOrderManager->buildAdditional(1, UnitTypes::Terran_Missile_Turret, 80, baseLocations[expanded]->getTilePosition());
	
			BWTA::Region* expansionRegion = baseLocations[expanded]->getRegion();
			std::set<BWTA::Chokepoint*> chokepoints= expansionRegion->getChokepoints();
			
			// Four Bunkers and a Turret at each chokepoint
			for each (BWTA::Chokepoint * defensiveLine in chokepoints)
			{
				buildOrderManager->buildAdditional(4, UnitTypes::Terran_Bunker, 79, defensiveLine->getCenter());
				buildOrderManager->buildAdditional(2, UnitTypes::Terran_Missile_Turret, 79, defensiveLine->getCenter());
				buildOrderManager->build(16, UnitTypes::Terran_Marine, 79);
			}
	
			//buildOrderManager->buildAdditional(1, UnitTypes::Terran_Nuclear_Silo, 76);
	
			buildOrderManager->buildAdditional(1, UnitTypes::Terran_Refinery, 75, baseLocations[expanded]->getTilePosition());
		} 
		else
		{
			BuildIslandBase(baseManager, buildOrderManager);
		}

	}
	
	void Base::BuildIslandBase(BaseManager* baseManager, BuildOrderManager* buildOrderManager)
	{
		buildOrderManager->buildAdditional(1, UnitTypes::Terran_Command_Center, 80, baseLocations[0]->getTilePosition());
		BWAPI::Unit * islandCommandCenter = commandCenters[commandCenters.Size()];
		bool doneMoving = false;
		while(!islandCommandCenter->isBeingConstructed() && !doneMoving)
		{
			islandCommandCenter->lift();
			islandCommandCenter->land(baseLocations[expanded]->getTilePosition());
			doneMoving = true;
		}
	}

	void Base::Upgrades(Unit * unit)
	{
		if (allUpgradesAreComplete == false)
		{
			//U-238 Shells
			if (Broodwar->self()->getUpgradeLevel(UpgradeTypes::U_238_Shells) < 1)
			{
				if (Broodwar->self()->minerals() > 100)
				{
					if (Broodwar->self()->gas() > 100)
					{
						if (unit->getType() == UnitTypes::Terran_Academy)
						{
							unit->upgrade(UpgradeTypes::U_238_Shells);
						}
					}
				}
			}

			//SiegeMode
			if (!Broodwar->self()->hasResearched(TechTypes::Tank_Siege_Mode))
			{
				if (Broodwar->self()->minerals() > 400)
				{
					if (Broodwar->self()->gas() > 400)
					{
						if (unit->getType() == UnitTypes::Terran_Machine_Shop)
						{
							unit->research(TechTypes::Tank_Siege_Mode);
						}
					}
				}
			}

			/*
			//Medic energy
			if (Broodwar->self()->getUpgradeLevel(UpgradeTypes::Caduceus_Reactor) < 1)
			{
				if (Broodwar->self()->minerals() > 300)
				{
					if (Broodwar->self()->gas() > 300)
					{
						if (unit->getType() == UnitTypes::Terran_Academy)
						{
							unit->upgrade(UpgradeTypes::Caduceus_Reactor);
						}
					}
				}
			}*/

			//Infantry armor
			if (Broodwar->self()->getUpgradeLevel(UpgradeTypes::Terran_Infantry_Armor) < 2)
			{
				if (Broodwar->self()->minerals() > 250)
				{
					if (Broodwar->self()->gas() > 250)
					{
						if (unit->getType() == UnitTypes::Terran_Engineering_Bay)
						{
							unit->upgrade(UpgradeTypes::Terran_Infantry_Armor);
						}
					}
				}
			}

			//Infantry weapons
			if (Broodwar->self()->getUpgradeLevel(UpgradeTypes::Terran_Infantry_Weapons) < 2)
			{
				if (Broodwar->self()->minerals() > 250)
				{
					if (Broodwar->self()->gas() > 250)
					{
						if (unit->getType() == UnitTypes::Terran_Engineering_Bay)
						{
							unit->upgrade(UpgradeTypes::Terran_Infantry_Weapons);
						}
					}
				}
			}

			//Vehicle plating
			if (Broodwar->self()->getUpgradeLevel(UpgradeTypes::Terran_Vehicle_Plating) < 3)
			{
				if (Broodwar->self()->minerals() > 250)
				{
					if (Broodwar->self()->gas() > 250)
					{
						if (unit->getType() == UnitTypes::Terran_Armory)
						{
							unit->upgrade(UpgradeTypes::Terran_Vehicle_Plating);
						}
					}
				}
			}

			//Vehicle weapons
			if (Broodwar->self()->getUpgradeLevel(UpgradeTypes::Terran_Vehicle_Weapons) < 3)
			{
				if (Broodwar->self()->minerals() > 250)
				{
					if (Broodwar->self()->gas() > 250)
					{
						if (unit->getType() == UnitTypes::Terran_Armory)
						{
							unit->upgrade(UpgradeTypes::Terran_Vehicle_Weapons);
						}
					}
				}
			}
			
			/*
			//Ship plating
			if (Broodwar->self()->getUpgradeLevel(UpgradeTypes::Terran_Ship_Plating) < 3)
			{
				if (Broodwar->self()->minerals() > 250)
				{
					if (Broodwar->self()->gas() > 250)
					{
						if (unit->getType() == UnitTypes::Terran_Armory)
						{
							unit->upgrade(UpgradeTypes::Terran_Ship_Plating);
						}
					}
				}
			}*/

			/*
			//Ship weapons
			if (Broodwar->self()->getUpgradeLevel(UpgradeTypes::Terran_Ship_Weapons) < 3)
			{
				if (Broodwar->self()->minerals() > 250)
				{
					if (Broodwar->self()->gas() > 250)
					{
						if (unit->getType() == UnitTypes::Terran_Armory)
						{
							unit->upgrade(UpgradeTypes::Terran_Ship_Weapons);
						}
					}
				}
			}*/


			//Charon booster (increased goliath air range)
			if (Broodwar->self()->getUpgradeLevel(UpgradeTypes::Charon_Booster) < 1)
			{
				if (Broodwar->self()->minerals() > 400)
				{
					if (Broodwar->self()->gas() > 400)
					{
						if (unit->getType() == UnitTypes::Terran_Machine_Shop)
						{
							unit->upgrade(UpgradeTypes::Charon_Booster);
						}
					}
				}
			}

			/*
			//Ocular Implants (Ghost sight range)
			if (Broodwar->self()->getUpgradeLevel(UpgradeTypes::Ocular_Implants) < 1)
			{
				if (Broodwar->self()->minerals() > 400)
				{
					if (Broodwar->self()->gas() > 400)
					{
						if (unit->getType() == UnitTypes::Terran_Covert_Ops)
						{
							unit->upgrade(UpgradeTypes::Ocular_Implants);
						}
					}
				}
			}*/

			/*
			//Moebius Reactor (Increase Ghost Starting and Max energy)
			if (Broodwar->self()->getUpgradeLevel(UpgradeTypes::Moebius_Reactor) < 1)
			{
				if (Broodwar->self()->minerals() > 400)
				{
					if (Broodwar->self()->gas() > 400)
					{
						if (unit->getType() == UnitTypes::Terran_Covert_Ops)
						{
							unit->upgrade(UpgradeTypes::Moebius_Reactor);
						}
					}
				}
			}*/

			/*
			//Personnel Cloaking for Ghosts
			if (!Broodwar->self()->hasResearched(TechTypes::Personnel_Cloaking))
			{
				if (Broodwar->self()->minerals() > 400)
				{
					if (Broodwar->self()->gas() > 400)
					{
						if (unit->getType() == UnitTypes::Terran_Covert_Ops)
						{
							unit->research(TechTypes::Personnel_Cloaking);
						}
					}
				}
			}*/

			/*
			//Lockdown (Ghost ability)
			if (!Broodwar->self()->hasResearched(TechTypes::Lockdown))
			{
				if (Broodwar->self()->minerals() > 400)
				{
					if (Broodwar->self()->gas() > 400)
					{
						if (unit->getType() == UnitTypes::Terran_Covert_Ops)
						{
							unit->research(TechTypes::Lockdown);
						}
					}
				}
			}
			*/

			/*check to see if all upgrades are complete so the 
			check functions no longer need to be called (efficiency).*/
			//if (Broodwar->self()->getUpgradeLevel(UpgradeTypes::Caduceus_Reactor) == 1)
			//{
			if (Broodwar->self()->getUpgradeLevel(UpgradeTypes::Terran_Infantry_Armor) == 2)
			{
				if (Broodwar->self()->getUpgradeLevel(UpgradeTypes::Terran_Infantry_Weapons) == 2)
				{
					if (Broodwar->self()->getUpgradeLevel(UpgradeTypes::Terran_Vehicle_Plating) == 3)
					{
						if (Broodwar->self()->getUpgradeLevel(UpgradeTypes::Terran_Vehicle_Weapons) == 3)
						{
							//if (Broodwar->self()->getUpgradeLevel(UpgradeTypes::Terran_Ship_Plating) == 3)
							//{
							//if (Broodwar->self()->getUpgradeLevel(UpgradeTypes::Terran_Ship_Weapons) == 3)
							//{
							if (Broodwar->self()->getUpgradeLevel(UpgradeTypes::Charon_Booster) == 1)
							{
								//if (Broodwar->self()->getUpgradeLevel(UpgradeTypes::Ocular_Implants) == 1)
								//{
								//if (Broodwar->self()->getUpgradeLevel(UpgradeTypes::Moebius_Reactor) == 1)
								//{
								//if (Broodwar->self()->hasResearched(TechTypes::Lockdown))
								//{
								//if (Broodwar->self()->hasResearched(TechTypes::Personnel_Cloaking))
								//{
								if (Broodwar->self()->hasResearched(TechTypes::Tank_Siege_Mode))
								{
									allUpgradesAreComplete = true;
									Broodwar->printf("All upgrades and tech complete");
								}
								//}
								//}
								//}
								//}
								//}
								//}
							}
						}
					}
				}
				//}
			}
		}
	}
	
	void Base::OnCommandCenterCreate(BWAPI::Unit *unit)
	{
		commandCenters.Add(unit);
	}
}


	

