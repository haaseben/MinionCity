/**
* \file MutantCounter.cpp
*
* \author Ben Haase
*/
#include "stdafx.h"
#include "MutantCounter.h"
#include "TileMinion.h"


CMutantCounter::CMutantCounter()
{
}


CMutantCounter::~CMutantCounter()
{
}

/** Visit a CTileMinion object
* \param minion Minion we are visiting */
void CMutantCounter::VisitMinion(CTileMinion *minion)
{
	if (minion->GetBananaCounter()>=4)
	{
		mNumMutants++;
	}
		
}