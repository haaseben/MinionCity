/**
* \file TileBuilding.h
*
* \author Ben Haase
*
*  Class that implements a Minion tile
*/
#pragma once
#include "Tile.h"
/**
*  A Minion tile
*/
class CTileMinion :
	public CTile
{
public:
	
	CTileMinion(CCity *city);

	///  Default constructor (disabled)
	CTileMinion() = delete;

	///  Copy constructor (disabled)
	CTileMinion(const CTileMinion &) = delete;

	~CTileMinion();

	std::shared_ptr<xmlnode::CXmlNode> CTileMinion::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node);
	void CTileMinion::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode> &node);

	/** Accept a visitor
	* \param visitor The visitor we accept */
	virtual void Accept(CTileVisitor *visitor) override { visitor->VisitMinion(this); }

	void CTileMinion::LoadImage(std::unique_ptr<Gdiplus::Bitmap> &image, std::wstring name);
	void CTileMinion::Draw(Gdiplus::Graphics *graphics);
	void CTileMinion::ChangeState();
	void CTileMinion::Update(double elapsed);
	void CTileMinion::GiveBanana();
	void CTileMinion::GivePotion();

	void CTileMinion::SetSpeed();

	

	///possible states of the minion tile
	enum States { Minion, Banana, Mutant };


	/**getter for mBananaCount
	*\return mBananaCount
	*/
	int GetBananaCounter() { return mBananaCount; }

private:
	/// The image of the regular minion
	std::unique_ptr<Gdiplus::Bitmap> mMinionImage;

	/// The image of the banana holding minion
	std::unique_ptr<Gdiplus::Bitmap> mBananaImage;

	/// The image of the mutant minion
	std::unique_ptr<Gdiplus::Bitmap> mMutantImage;

	///intial state of mState
	States mState = Minion;

	///how many bananas a minion is holding
	int mBananaCount = 0;

	///speed for minions to run in x
	double mRunX=0;

	///speed for minions to run in y
	double mRunY=0;

	///intial speed for minions to run in x
	double mSpeedX=0;
	

	///intial speed for minions to run in y
	double mSpeedY=0;

	
};

