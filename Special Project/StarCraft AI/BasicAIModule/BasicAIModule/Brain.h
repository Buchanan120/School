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
	class Brain
	{
	public:
		std::vector<BWAPI::Position > memory;
		Brain();
		inline void Timer();
		void RememberTarget(Unit * unit);
		int nextPosition;
		bool addAPosition;

		clock_t endwait;
		int waitSeconds;


	};
	Brain::Brain()
	{
		waitSeconds = 5;
		endwait = clock () + waitSeconds * CLOCKS_PER_SEC ;
		addAPosition = true;
	}

	//add new locations every few seconds
	inline void Brain::Timer()
	{
		if (clock() > endwait)
		{
			addAPosition = true;
			printf("Add a Position = true");
			endwait = clock () + waitSeconds * CLOCKS_PER_SEC ;
		}

	}

	void Brain::RememberTarget(Unit * unit)
	{
		//Is enemy in sight?
		if (addAPosition == true)
		{
			if (Broodwar->self()->isEnemy(unit->getPlayer()))
			{ 
				printf("Push back a position ");
				Broodwar->printf("Num Positions: %d", memory.size());
				memory.push_back(unit->getPosition());
				addAPosition = false;
			}
		}
	}
}