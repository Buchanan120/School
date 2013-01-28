
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

namespace Ghosts
{
	//GhostTeam class
	class GhostTeam
	{
	public:
		//Functions
		GhostTeam();
		inline void Ghost_Control();					//Control the ghosts' basic attacking
		inline void Ghost_Withdraw();					//Control the ghosts' retreating
		inline void on_Ghost_Build(BWAPI::Unit * unit);		//on ghost/acadamy completion
		inline void on_Ghost_Death(BWAPI::Unit * unit);		//on team member death
		inline void on_Target_Death(BWAPI::Unit * unit);	//on ghost target death
		inline void on_Target_Sighted(BWAPI::Unit * unit);	//get the ghosts target

	private:
		//Variables
		std::set<BWAPI::Unit *> Ghost_Team;						//Set of ghosts
		std::priority_queue<BWAPI::Unit *> Lockdown_Targets;	//priority queue of lockdown targets
		Unit *Ghost_Target;										//The Ghosts target
		bool Ghost_Withdrawing;									//Have the ghosts been told to retreat?
		bool Ghost_Target_Set;									//If the ghosts have a target selected
		int ghosts_on_target;				//how many ghosts are after a specific target
		bool ghost_ready;					//if the ghost has enough energy to fight
		Position Ghost_Retreat_Point;		//Ghost retreat point, the acadamy location
	};

	//Constructor
	GhostTeam::GhostTeam()
	{
		ghosts_on_target = 0;			//initialize to 0
		ghost_ready = false;			//ghosts are not ready to fight initially
		Ghost_Target_Set = false;		//is the ghost team's target set?
		Ghost_Withdrawing = false;		//are the ghosts withdrawing?
	}

	//If an enemy that the ghosts should deal with is sighted, lock it as a target
	inline void GhostTeam::on_Target_Sighted(BWAPI::Unit *unit)
	{
		//get ghost target
		if(Broodwar->self()->isEnemy(unit->getPlayer()))
		{
			if(Ghost_Team.size() >= 6)
			{
				if(unit->getType() == UnitTypes::Protoss_High_Templar && Ghost_Target == NULL && Ghost_Target_Set == false)
				{
					Ghost_Target = unit;
					Broodwar->printf("Ghosts en route to eliminate target");
				}
			}
		}
	}

	//If a ghost or acadamy is built, update accordingly
	inline void GhostTeam::on_Ghost_Build(BWAPI::Unit * unit)
	{
		if(unit->getPlayer() == Broodwar->self() && unit->getType() == UnitTypes::Terran_Academy)
		{
			Ghost_Retreat_Point.x() = unit->getPosition().x();	//set the x
			Ghost_Retreat_Point.y() = unit->getPosition().y();	//set the y
			//Don't have a flag, that way if it's destroyed and rebuilt elsewhere, the ghosts will
			//retreat to a safe location
		}

		if(unit->getPlayer() == Broodwar->self() && unit->getType() == UnitTypes::Terran_Ghost)	//if a ghost has been built by the player
		{
			Ghost_Team.insert(unit);													//add the ghost to the ghost set
			unit->rightClick(Ghost_Retreat_Point);									//have the ghost move to the ghost retreat point
		}
	}

	//If a ghost in the team dies
	inline void GhostTeam::on_Ghost_Death(BWAPI::Unit * unit)
	{
		if(unit->getPlayer() == Broodwar->self() && unit->getType() == UnitTypes::Terran_Ghost)
			Ghost_Team.erase(unit);									//remove the dead ghost from the team
	}

	//If the ghosts' basic attack target is dead
	inline void GhostTeam::on_Target_Death(BWAPI::Unit * unit)
	{
		if(unit == Ghost_Target)				//if the ghost's target is dead
		{
			Ghost_Target = NULL;				//set the ghosts' target to null
			Ghost_Target_Set = false;			//set their target_set to false
			Broodwar->printf("Enemy eliminated");		//inform the player it is dead
		}
	}

	//Control the Ghosts
	inline void GhostTeam::Ghost_Control()
	{
		if(Ghost_Team.size() == 6)
		{
			for each(Unit* ghost in Ghost_Team)
			{
				if(ghost->isIdle() && ghost->isCloaked())		//if the ghost is idle, and cloaked
				{
					ghost->decloak();			//decloak
					//Ghost_Withdraw == true;		//retreat to the withdraw point
				}
				else if(Ghost_Target != NULL && Ghost_Target->isVisible() && Ghost_Target_Set == false)	//If the ghosts have a visible target
				{
					ghost->attackUnit(Ghost_Target);		//attack the target
					ghost->cloak();							//have the ghost cloak
					++ghosts_on_target;						//increment ghosts_on_target
				}
				else if(ghosts_on_target == Ghost_Team.size())	//if all ghosts have been told to attack
				{
					Ghost_Target_Set = true;				//set Ghost_Target_Set to true
					Broodwar->printf("Ghosts en route to eliminate target");	//output
					ghosts_on_target = 0;					//reset ghosts_on_target
				}
			}
		}

		//else if(Ghost_Withdrawing == true)
		//	Ghost_Withdraw();
	}

	//Control the Ghost withdraw
	inline void GhostTeam::Ghost_Withdraw()
	{
		for each(Unit* ghost in Ghost_Team)			//for each ghost in the ghost
		{
			ghost->rightClick(Ghost_Retreat_Point);		//tell the ghosts to retreat to the retreat point
			++ghosts_on_target;
			if(ghosts_on_target == Ghost_Team.size())
			{
				Ghost_Withdrawing = false;
				ghosts_on_target = 0;
			}
		}
	}
}
