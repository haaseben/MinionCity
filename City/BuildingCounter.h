/**
* \file BuildingCounter.h
*
* \author Ben Haase
*
*  Class that implements a building counter
*/

#pragma once
#include "TileVisitor.h"

/**
*  Implements a building counter
*/
class CBuildingCounter :
	public CTileVisitor
{
public:
	CBuildingCounter();
	~CBuildingCounter();

	/** Get the number of buildings
	* \returns Number of buildings */
	int GetNumBuildings() const { return mNumBuildings; }

	void CBuildingCounter::VisitBuilding(CTileBuilding *building);

private:
	/// Buildings counter
	int mNumBuildings = 0;
};

