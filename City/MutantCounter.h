/**
* \file MutantCounter.h
*
* \author Ben Haase
*
*  Class that implements a mutant counter
*/
#pragma once
#include "TileVisitor.h"
/**
*  Implements a mutant counter
*/
class CMutantCounter :
	public CTileVisitor
{
public:
	CMutantCounter();
	~CMutantCounter();

	/** Get the number of mutants
	* \returns Number of mutants */
	int GetNumMutants() const { return mNumMutants; }

	virtual void VisitMinion(CTileMinion *minion) override;

private:
	/// Mutants Counter
	int mNumMutants = 0;
};

