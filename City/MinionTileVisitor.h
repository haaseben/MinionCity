/**
* \file MinionTileVisitor.h
*
* \author Ben Haase
*
*  Class that implements a minion visitor
*/
#pragma once
#include "TileVisitor.h"

/**
*  Implements a minion visitor
*/
class CMinionTileVisitor :
	public CTileVisitor
{
public:
	CMinionTileVisitor();
	~CMinionTileVisitor();

	virtual void VisitMinion(CTileMinion *minion) override;
};

