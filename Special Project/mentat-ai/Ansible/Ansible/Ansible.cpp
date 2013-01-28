#include "Ansible.h"
using namespace BWAPI;
using namespace std;

void Ansible::onStart()
{
	// Enable some cheat flags
	Broodwar->enableFlag(Flag::UserInput);
	// Uncomment to enable complete map information
	Broodwar->enableFlag(Flag::CompleteMapInformation);

	//read map information into BWTA so terrain analysis can be done in another thread
	BWTA::readMap();
	analysis_just_finished=false
	analyzed=false;;
	show_visibility_data=false;
}

void Ansible::onFrame()
{
	drawStats();
}

void Ansible::onUnitCreate(BWAPI::Unit* unit)
{
	
}
void Ansible::onUnitDestroy(BWAPI::Unit* unit)
{
	
}

void Ansible::onUnitMorph(BWAPI::Unit* unit)
{
	
}
void Ansible::onUnitShow(BWAPI::Unit* unit)
{
	
}
void Ansible::onUnitHide(BWAPI::Unit* unit)
{
	
}
void Ansible::onUnitRenegade(BWAPI::Unit* unit)
{
	
}
void Ansible::onPlayerLeft(BWAPI::Player* player)
{
	Broodwar->sendText("%s left the game.",player->getName().c_str());
}
void Ansible::onNukeDetect(BWAPI::Position target)
{
	if (target != Positions::Unknown)
		Broodwar->printf("Nuclear Launch Detected at (%d,%d)",target.x(),target.y());
	else
		Broodwar->printf("Nuclear Launch Detected");
}

bool Ansible::onSendText(std::string text)
{
	if (text=="/show players")
	{
		showPlayers();
		return false;
	} 
	else if (text=="/show forces")
	{
		showForces();
		return false;
	} 
	else if (text=="/show visibility")
	{
		show_visibility_data=true;
	} 
	else if (text=="/analyze")
	{
		if (analyzed == false)
		{
			Broodwar->printf("Analyzing map... this may take a minute");
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)AnalyzeThread, NULL, 0, NULL);
		}
		return false;
	} 
	else
	{
		Broodwar->printf("You typed '%s'!",text.c_str());
	}
	return true;
}

void Ansible::onEnd(bool isWinner)
{
	if ( isWinner )
	{
		//log win to file
	}
}

DWORD WINAPI AnalyzeThread()
{
	BWTA::analyze();
	analyzed = true;
	analysis_just_finished = true;

	//self start location only available if the map has base locations
	if (BWTA::getStartLocation(BWAPI::Broodwar->self())!= NULL)
	{
		home = BWTA::getStartLocation(BWAPI::Broodwar->self())->getRegion();
	}
	return 0;
}

void Ansible::drawStats()
{
	std::set<Unit*> myUnits = Broodwar->self()->getUnits();
	Broodwar->drawTextScreen(5,0,"I have %d units:",myUnits.size());
	std::map<UnitType, int> unitTypeCounts;
	for(std::set<Unit*>::iterator i=myUnits.begin();i!=myUnits.end();i++)
	{
		if (unitTypeCounts.find((*i)->getType())==unitTypeCounts.end())
		{
			unitTypeCounts.insert(std::make_pair((*i)->getType(),0));
		}
		unitTypeCounts.find((*i)->getType())->second++;
	}
	int line=1;
	for(std::map<UnitType,int>::iterator i=unitTypeCounts.begin();i!=unitTypeCounts.end();i++)
	{
		Broodwar->drawTextScreen(5,16*line,"- %d %ss",(*i).second, (*i).first.getName().c_str());
		line++;
	}
}

void Ansible::showPlayers()
{
	std::set<Player*> players=Broodwar->getPlayers();
	for(std::set<Player*>::iterator i=players.begin();i!=players.end();i++)
	{
		Broodwar->printf("Player [%d]: %s is in force: %s",(*i)->getID(),(*i)->getName().c_str(), (*i)->getForce()->getName().c_str());
	}
}
void Ansible::showForces()
{
	std::set<Force*> forces=Broodwar->getForces();
	for(std::set<Force*>::iterator i=forces.begin();i!=forces.end();i++)
	{
		std::set<Player*> players=(*i)->getPlayers();
		Broodwar->printf("Force %s has the following players:",(*i)->getName().c_str());
		for(std::set<Player*>::iterator j=players.begin();j!=players.end();j++)
		{
			Broodwar->printf("  - Player [%d]: %s",(*j)->getID(),(*j)->getName().c_str());
		}
	}
}