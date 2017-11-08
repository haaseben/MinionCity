/**
* \file MinionCounter.h
*
* \author Ben Haase
*
*  Class that implements a minion counter
*/
#pragma once
#include "TileVisitor.h"
/**
*  Implements a minion counter
*/
class CMinionCounter :
	public CTileVisitor
{
public:
	CMinionCounter();
	~CMinionCounter();

	/** Get the number of minions
	* \returns Number of minions */
	int GetNumMinions() const { return mNumMinions; }

	void CMinionCounter::VisitMinion(CTileMinion *minion);

private:
	/// Minions Counter
	int mNumMinions = 0;
};

