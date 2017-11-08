/**
* \file GiveBananaVisitor.cpp
*
* \author Ben Haase
*/

#include "stdafx.h"
#include "GiveBananaVisitor.h"
#include "TileMinion.h"

CGiveBananaVisitor::CGiveBananaVisitor()
{
}


CGiveBananaVisitor::~CGiveBananaVisitor()
{
}


/** \brief Visit a CTileMinion object
* \param minion Minion tile we are visiting */
void CGiveBananaVisitor::VisitMinion(CTileMinion *minion)
{
	minion->GiveBanana();
}