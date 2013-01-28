// Ansible.h
//	Ansible is the top level logic for the AI.  
//	Equivalent of BasicAIModule

// insure that this header file is not included more than once
#pragma once
#ifndef ANSIBLE_H_
#define ANSIBLE_H_

#include <BWAPI.h>
#include <BWTA.h>
#include <windows.h>
#include <winsock.h>
#include <sstream>
#include <string>

// port to connect to
#define PORTNUM 1337

// size of receive buffer for commands from Mentat
#define recieveBufferSize 4096
char recieveBuffer[recieveBufferSize];

// buffer data buffer
#define sendBufferSize 100000
char sendBuffer[sendBufferSize];

//pixels per tile in StarCraft
#define pixelsPerTile 32

// max indices of static type data
#define maxUnitTypes 230
#define maxTechTypes 47
#define maxUpgradeTypes 63

// mapping of IDs to types
UnitType unitTypeMap[maxUnitTypes];
TechType techTypeMap[maxTechTypes];
UpgradeType upgradeTypeMap[maxUpgradeTypes];

// export information about static type data?
bool exportTypeData = false;

// display commands made by the bot?, received from Mentat
bool logCommands = false;

// mapping of unit objects to a unique ID, sent to Mentat
std::map<Unit*, int> unitMap;
std::map<int, Unit*> unitIDMap;

// used by the append method
int digits[9];

// socket identifier
int proxyBotSocket = -1;




static bool analyzed;
static bool analysis_just_finished;
static BWTA::Region* home;
static BWTA::Region* enemy_base;
DWORD WINAPI AnalyzeThread();

class Ansible : public BWAPI::AIModule
{
public:
	virtual void onStart();
	virtual void onEnd(bool isWinner);
	virtual void onFrame();
	virtual bool onSendText(std::string text);
	virtual void onPlayerLeft(BWAPI::Player* player);
	virtual void onNukeDetect(BWAPI::Position target);
	virtual void onUnitCreate(BWAPI::Unit* unit);
	virtual void onUnitDestroy(BWAPI::Unit* unit);
	virtual void onUnitMorph(BWAPI::Unit* unit);
	virtual void onUnitShow(BWAPI::Unit* unit);
	virtual void onUnitHide(BWAPI::Unit* unit);
	virtual void onUnitRenegade(BWAPI::Unit* unit);
	void drawStats(); //not part of BWAPI::AIModule
	void showPlayers();
	void showForces();
	bool show_visibility_data;

	/** functions for being a proxy **/
	int initSocket();
	void exportStaticData();
	std::string toString(int value);
	std::string toString(bool value);
	void append(FILE *log, std::string data);
	void handleCommand(int command, int unitID, int arg0, int arg1, int arg2);
	BWAPI::UnitType getUnitType(int type); 
	BWAPI::TechType getTechType(int type);
	BWAPI::UpgradeType getUpgradeType(int type);
	void loadTypeMaps();
	BWAPI::TilePosition getTilePosition(int x, int y);
	BWAPI::Position getPosition(int x, int y);
	BWAPI::Unit* getUnit(int unitID);
	int append(int val, char* buf, int currentIndex);

};

#endif