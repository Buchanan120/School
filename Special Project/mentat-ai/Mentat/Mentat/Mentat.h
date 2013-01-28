#include "Modules.h"
#include "PerceivedReality.h"
#include "Squad.h"
#include "Strategos.h"
#include "BWAPI.h"
#include "BWTA.h"
#include <windows.h>
//#include <winsock.h>

// insure that this header file is not included more than once
#pragma once
#ifndef MENTAT_H_
#define MENTAT_H_

namespace AI
{
	class Mentat
	{
	public:
		// some sort of array of Agents
		Modules* modules;
		PercievedReality* pr;
		Squad* squad;
		Strategos* strategos;

		Mentat();
		~Mentat();
		void onStart();
		void onFrame();
		void onPlayerLeft(BWAPI::Player* player);
		void onNukeDetect(BWAPI::Position target);
		void onUnitCreate(BWAPI::Unit* unit);
		void onUnitDestroy(BWAPI::Unit* unit);
		void onUnitMorph(BWAPI::Unit* unit);
		void onUnitShow(BWAPI::Unit* unit);
		void onUnitHide(BWAPI::Unit* unit);
		void onUnitRenegade(BWAPI::Unit* unit);

		static bool analyzed;
		static bool analysis_just_finished;
		static BWTA::Region* home;
		static BWTA::Region* enemy_base;
		DWORD WINAPI AnalyzeThread();

	};
}

#endif