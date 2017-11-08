#include "stdafx.h"
#include "MinionCounter.h"


CMinionCounter::CMinionCounter()
{
}


CMinionCounter::~CMinionCounter()
{
}
/** Visit a CTileMinion object
* \param minion Minion we are visiting */
void CMinionCounter::VisitMinion(CTileMinion *minion)
{
	mNumMinions++;
}