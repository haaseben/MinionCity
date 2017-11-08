/**
* \file MinionTileVisitor.cpp
*
* \author Ben Haase
*/
#include "stdafx.h"
#include "MinionTileVisitor.h"
#include "TileMinion.h"


CMinionTileVisitor::CMinionTileVisitor()
{
}


CMinionTileVisitor::~CMinionTileVisitor()
{
}


/** \brief Visit a CTileMinion object
* \param minion Minion tile we are visiting */
void CMinionTileVisitor::VisitMinion(CTileMinion *minion)
{
	minion->SetSpeed();
}