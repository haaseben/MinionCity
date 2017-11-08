/**
* \file GivePotionVisitor.cpp
*
* \author Ben Haase
*/
#include "stdafx.h"
#include "GivePotionVisitor.h"
#include "TileMinion.h"


CGivePotionVisitor::CGivePotionVisitor()
{
}


CGivePotionVisitor::~CGivePotionVisitor()
{
}

/** \brief Visit a CTileMinion object
* \param minion Minion tile we are visiting */
void CGivePotionVisitor::VisitMinion(CTileMinion *minion)
{
	minion->GivePotion();
}