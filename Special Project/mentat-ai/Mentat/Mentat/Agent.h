// Agent.h
//	Agent is the basic intelligence for all units
//	Logistics level

// insure that this header file is not included more than once
#pragma once
#ifndef AGENT_H_
#define AGENT_H_

#include "Mentat.h"

namespace AI
{
	class Agent
	{
	public:
		Agent(Squad * squad, BWAPI::Unit * unitToControl);
		void act();
		void setSquad(Squad* squad);
	private:
		BWTA::Unit * self;
		Squat * squad;
		static double sightRange = 5;
		std::set<BWTA::Unit *> nearbyUnits;
		void analyze(BWTA::Unit * unit);
		void attack(BWTA::Unit * unit);
		void move(BWTA::Tileposition loc);
		void run(BWTA::Tileposition loc);
		// TODO: Find a way to get the module's methods for the agent.
	};
}

#endif