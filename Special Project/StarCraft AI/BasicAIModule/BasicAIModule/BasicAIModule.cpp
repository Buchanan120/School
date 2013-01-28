#include "BasicAIModule.h"
#include "ScoutAI.h"
#include "AttackAI.h"
#include "BaseAI.h"
#include "RepairAI.h"
#include "BuildBalancer.h"
#include "MyArray.h"
#include "IdleWorker.h"
#include "Ghosts.h"
#include "Brain.h"
using namespace Ghosts;
Ghosts::GhostTeam ourGhosts;

using namespace BWAPI;
using namespace AI;
AI::Base ourBase;
AI::Attack ourAttack;
AI::Repair ourRepair;
AI::Scout ourScout;
AI::BuildBalancer ourBuildBalancer;
AI::IdleWorker ourIdleWorker;
AI::Brain ourBrain;
AI::Brain * brainPtr;

void BasicAIModule::onStart()
{
	if (Broodwar->isReplay()) return;
	Broodwar->enableFlag(Flag::UserInput);
	//Broodwar->enableFlag(Flag::CompleteMapInformation);
	Broodwar->setLocalSpeed(0);
	BWTA::readMap();
	BWTA::analyze();
	this->analyzed=true;
	this->buildManager      = new BuildManager(&this->arbitrator);
	this->techManager       = new TechManager(&this->arbitrator);
	this->upgradeManager    = new UpgradeManager(&this->arbitrator);
	this->buildOrderManager = new BuildOrderManager(this->buildManager,this->techManager,this->upgradeManager);
	this->scoutManager      = new ScoutManager(&this->arbitrator);
	this->workerManager     = new WorkerManager(&this->arbitrator);
	this->baseManager       = new BaseManager();
	this->supplyManager     = new SupplyManager();

	this->supplyManager->setBuildManager(this->buildManager);
	this->supplyManager->setBuildOrderManager(this->buildOrderManager);
	this->techManager->setBuildingPlacer(this->buildManager->getBuildingPlacer());
	this->upgradeManager->setBuildingPlacer(this->buildManager->getBuildingPlacer());
	this->workerManager->setBaseManager(this->baseManager);
	this->baseManager->setBuildOrderManager(this->buildOrderManager);
	brainPtr = &ourBrain;

	ourAttack.GetBaseLocations();
	ourScout.GetBaseLocations();
	ourIdleWorker.SaveBaseLocations();
}

void BasicAIModule::onFrame()
{
	if (Broodwar->isReplay()) return;
	if (!this->analyzed) return;
	this->buildManager->update();
	this->buildOrderManager->update();
	this->baseManager->update();
	this->workerManager->update();
	this->techManager->update();
	this->upgradeManager->update();
	this->supplyManager->update();
	this->scoutManager->update();
	this->arbitrator.update();

	//neutral call for either defending or not defending
	ourAttack.DefendBase();
	ourIdleWorker.ResetWorkerStats();
	ourIdleWorker.WorkerStats();
	ourRepair.Timer();
	ourBrain.Timer();

	if (ourAttack.allAttackUnitsDefend == false)
	{
		ourBase.BuildMainBase(this->baseManager, this->buildOrderManager);
		if(Broodwar->self()->cumulativeMinerals() >= (ourBase.mineralThreshold[ourBase.expanded]))
			ourBase.BuildNextBase(this->baseManager, this->buildOrderManager);

		ourAttack.Timer();
		ourAttack.UpdateUnitCount();
		ourAttack.CheckPatrol();
		ourAttack.MoveToAttackPos(brainPtr);
		ourAttack.ResetUnitCount();
		ourGhosts.Ghost_Control();

		for each(Unit * allUnits in Broodwar->self()->getUnits())
		{
			ourBuildBalancer.Ready(buildOrderManager,allUnits);

			ourBase.Upgrades(allUnits);
			ourIdleWorker.AssignJobs(allUnits);
			ourScout.AddScout(allUnits);
		}
		ourScout.Timer();
	}
}

void BasicAIModule::onUnitDestroy(BWAPI::Unit *unit)
{
	//check our own units only
	if(unit->getPlayer() == Broodwar->self())
	{
		//building
		if(unit->getType().isBuilding())
		{
			buildOrderManager->buildAdditional(1, unit->getType(), 100, unit->getTilePosition());
			return;
		}
		else
		{
			buildOrderManager->buildAdditional(1, unit->getType(), 100);
			ourGhosts.on_Ghost_Death(unit);
			ourGhosts.on_Target_Death(unit);
		}
	}
} 

void BasicAIModule::onUnitCreate(BWAPI::Unit* unit)
{
	//troops
	if(unit->getPlayer() == Broodwar->self())
	{
		if(!unit->getType().isBuilding())
		{
			if(unit->getType() == UnitTypes::Terran_SCV)
			{
			}
			else if (unit->getType() == UnitTypes::Terran_Command_Center)
			{
				ourBase.OnCommandCenterCreate(unit);
			}
			else
			{
				unit->patrol(Broodwar->self()->getStartLocation());
				ourGhosts.on_Ghost_Build(unit);
			}
		}
	}
}

void BasicAIModule::onUnitShow(BWAPI::Unit * unit)
{
	ourAttack.StartLocationIsUnderAttack(unit);
	ourGhosts.on_Target_Sighted(unit);
	ourBrain.RememberTarget(unit);
}

void BasicAIModule::onUnitRemove(BWAPI::Unit * unit)
{
	this->arbitrator.onRemoveObject(unit);
	this->buildManager->onRemoveUnit(unit);
	this->techManager->onRemoveUnit(unit);
	this->upgradeManager->onRemoveUnit(unit);
	this->workerManager->onRemoveUnit(unit);
	this->scoutManager->onRemoveUnit(unit);
}