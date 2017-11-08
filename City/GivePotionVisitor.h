/**
* \file GiveBananaVisitor.h
*
* \author Ben Haase
*
*  Class that implements a potion giver
*/
#pragma once
#include "TileVisitor.h"
/**
*  Implements a potion giver
*/
class CGivePotionVisitor :
	public CTileVisitor
{
public:
	CGivePotionVisitor();
	~CGivePotionVisitor();

	virtual void VisitMinion(CTileMinion *minion) override;
};

