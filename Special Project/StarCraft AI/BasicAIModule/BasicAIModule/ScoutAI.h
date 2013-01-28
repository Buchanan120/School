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

	class Scout
	{
	private:
		std::vector<BWTA::BaseLocation *> baseLocations;
		std::queue<BWAPI::Unit *> scoutControl;
		BWTA::BaseLocation * nextBase;
		clock_t stamp_t;
		int waitSeconds;
		bool baseRightClicked;

	public:
		Scout();
		void GetBaseLocations();
		inline void Timer();
		BWTA::BaseLocation * SetMoveTo();
		inline void MoveToBaseLocation(/*std::set<Unit*>::iterator * i*/);
		inline void ResetClicked();
		inline void AddScout(Unit * unit);
		inline int ScoutSize() const;
		void reset_t(){stamp_t = clock();}
		inline double get_t() const;
		
	};
	Scout::Scout()
	{
		srand ( time(NULL) );
		waitSeconds = 60000;
		stamp_t = clock();
	}

	void Scout::GetBaseLocations()
	{
		for each(BWTA::BaseLocation * bases in BWTA::getBaseLocations())
		{
			if (!bases->isIsland() && !bases->isStartLocation())
			{
				baseLocations.push_back(bases);
			}
		} 
	}

	//switch unit patrol to another base
	inline void Scout::Timer()
	{
		if (get_t() >= waitSeconds)
		{
			waitSeconds = 12000;
			nextBase = Scout::SetMoveTo();
			baseRightClicked = false;
			MoveToBaseLocation();
		}
	}

	inline double Scout::get_t() const
	{
		return (clock() - stamp_t);
	}

	//choose a random non-island, base
	BWTA::BaseLocation * Scout::SetMoveTo()
	{
		BWTA::BaseLocation * anyBase;
		int anyNum = rand() % baseLocations.size();
		anyBase = baseLocations[anyNum];
		return anyBase;

	}

	inline void Scout::MoveToBaseLocation()
	{
		Unit* u = scoutControl.front();	
		if (baseRightClicked == false)
		{
			u->rightClick(nextBase->getPosition());
			scoutControl.pop();
			scoutControl.push(u);
			ResetClicked();
			reset_t();
		}
	}

	inline void Scout::ResetClicked()
	{
		baseRightClicked = true;
	}

    inline int Scout::ScoutSize() const
	{
		return scoutControl.size();
	}

	inline void Scout::AddScout(Unit * unit)
	{
		if (ScoutSize() < 1)
		{
			if (unit->getType() == UnitTypes::Terran_SCV)
			{
				scoutControl.push(unit);
			}
		}
	}
}