// Interface.h
//	Interface is the go-between for the API and the programmer.
//		Defines calls for often-used methods such as build or upgrade
//	Equivalent of BWSAL

// insure that this header file is not included more than once
#pragma once
#ifndef INTERFACE_H_
#define INTERFACE_H_

class Interface
{
	Interface();
	~Interface();
	void handleCommand(int command, int unitID, int arg0, int arg1, int arg2);
};
#endif