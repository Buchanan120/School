// Squad.h
//	Squad is a class which contains a groups of Agents
//		and facilitates task coordination
//	Tactical level

// insure that this header file is not included more than once
#pragma once
#ifndef SQUAD_H_
#define SQUAD_H_

#include "BWAPI.h"

namespace AI
{
	class Squad
	{
	public:
		BWAPI::TilePosition regroupPosition;
		Squad();
		~Squad();
	};
}

#endif