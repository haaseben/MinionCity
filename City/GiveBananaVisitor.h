/**
* \file GiveBananaVisitor.h
*
* \author Ben Haase
*
*  Class that implements a banana giver
*/
#pragma once
#include "TileVisitor.h"

/**
*  Implements a banana giver
*/
class CGiveBananaVisitor :
	public CTileVisitor
{
public:
	CGiveBananaVisitor();
	~CGiveBananaVisitor();

	virtual void VisitMinion(CTileMinion *minion) override;
};

