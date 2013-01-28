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
	class IdleWorker
	{

	private:
		int numOnGas;
		int numOnMinerals;
		int numSCVs;
		int numIdle;
	public:
		std::vector<BWTA::BaseLocation*> mapBases;
		void SaveBaseLocations();
		inline void WorkerStats();
		inline void ResetWorkerStats();
		inline void AssignJobs(Unit * unit);
	};

	//called in onstart
	void IdleWorker::SaveBaseLocations()
	{
		//collect mineral at nearest base
		const std::set<BWTA::BaseLocation *> bases = BWTA::getBaseLocations();
		for each(BWTA::BaseLocation * base in bases)
		{
			// We're only interested in non-island bases
			if (!base->isIsland())
			{
				mapBases.push_back(base);
			}
		}

		//sort the distances based on the closest base
		BWTA::BaseLocation * temp;
		for (int i = 0; i < mapBases.size(); i++)
		{
			for (int x = 0; x <  mapBases.size(); x++)
			{
				if (Broodwar->self()->getStartLocation().getDistance(mapBases[i]->getTilePosition())
					< Broodwar->self()->getStartLocation().getDistance(mapBases[x]->getTilePosition()))
				{
					temp = mapBases[i];
					mapBases[i] = mapBases[x];
					mapBases[x] = temp;
				}
			}
		}
	}

	//how many workers are doing what?
	//called on OnFrame above unit iterator
	inline void IdleWorker::WorkerStats()
	{
		for each(Unit * SCV in Broodwar->self()->getUnits())
		{
			if (SCV->getType() == UnitTypes::Terran_SCV)
			{
				numSCVs++;
				if (SCV->isGatheringGas() == true)
				{
					numOnGas++;
				}
				if (SCV->isGatheringMinerals() == true)
				{
					numOnMinerals++;
				}
				if (SCV->isIdle() == true)
				{
					numIdle++;
				}
			}
		}
		
	}

	//reset worker stats
	//called at the top of onframe()
	inline void IdleWorker::ResetWorkerStats()
	{
		numOnGas = 0;
		numOnMinerals = 0;
		numSCVs = 0;
		numIdle = 0;
	}


	//assign jobs to idle workers
	//called in onframe under the unit iterator
	inline void IdleWorker::AssignJobs(Unit * unit)
	{
		bool breakLoop = false;
		if (numIdle > 1)
		{
			if (unit->getType() == UnitTypes::Terran_SCV)
			{
				if (unit->isIdle() == true)
				{
					//gas collecting check for 5+
					if (numSCVs >= 5)
					{
						if (numOnGas < 3)
						{
							for each(Unit * refinery in Broodwar->self()->getUnits())
							{
								if (refinery->getType()  == UnitTypes::Terran_Refinery)
								{
									unit->rightClick(refinery);
									numOnGas++;
								}
							}
						}
						else
						{
							//iterate through each mineral at a base to see if there are some to click
							for (int i = 0; i < mapBases.size(); i++)
							{
								for each(Unit * baseMineral in mapBases[i]->getMinerals())
								{								
									if (baseMineral->getResources() > 0 && breakLoop == false)
									{
										unit->rightClick(baseMineral);
										breakLoop = true;
									}
								}
							}
						}
					}
					//2 gas 2 mineral or 2 gas 1 mineral
					else if (numSCVs == 4 || numSCVs == 3)
					{
						if (numOnGas < 2)
						{
							for each(Unit * refinery in Broodwar->self()->getUnits())
							{
								if (refinery->getType()  == UnitTypes::Terran_Refinery)
								{
									unit->rightClick(refinery);
									numOnGas++;
								}
							}
						}
						else
						{
							//iterate through each mineral at a base to see if there are some to click
							for (int i = 0; i < mapBases.size(); i++)
							{
								for each(Unit * baseMineral in mapBases[i]->getMinerals())
								{								
									if (baseMineral->getResources() > 0 && breakLoop == false)
									{
										unit->rightClick(baseMineral);
										breakLoop = true;
									}
								}
							}
						}
					}
					//1 gas 1 mineral
					else if (numSCVs == 2)
					{
						if (numOnGas < 1)
						{
							for each(Unit * refinery in Broodwar->self()->getUnits())
							{
								if (refinery->getType()  == UnitTypes::Terran_Refinery)
								{
									unit->rightClick(refinery);
									numOnGas++;
								}
							}
						}
						else
						{
							//iterate through each mineral at a base to see if there are some to click
							for (int i = 0; i < mapBases.size(); i++)
							{
								for each(Unit * baseMineral in mapBases[i]->getMinerals())
								{								
									if (baseMineral->getResources() > 0 && breakLoop == false)
									{
										unit->rightClick(baseMineral);
										breakLoop = true;
									}
								}
							}
						}
					}
					//1 mineral
					else if (numSCVs == 1)
					{
						//iterate through each mineral at a base to see if there are some to click
						for (int i = 0; i < mapBases.size(); i++)
						{
							for each(Unit * baseMineral in mapBases[i]->getMinerals())
							{								
								if (baseMineral->getResources() > 0 && breakLoop == false)
								{
									unit->rightClick(baseMineral);
									breakLoop = true;
								}
							}
						}
					}
				}
			}
		}
	}
}