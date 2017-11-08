#include "stdafx.h"
#include "TileMinion.h"
#include "iostream"
using namespace std;
using namespace Gdiplus;

/// Image for background
const wstring TileBackground = L"grass.png";

///image for minion
const wstring MinionImage = L"minion.png";

///image for minion with banana
const wstring BananaImage = L"banana.png";

///image for mutant minion
const wstring MutantImage = L"mutant.png";

/// How much we offset drawing the tile to the left of the center
const int OffsetLeft = 64;

/// How much we offset drawing the tile above the center
const int OffsetDown = 32;







/** Constructor
* \param city The city this is a member of
*/
CTileMinion::CTileMinion(CCity *city) : CTile(city)
{
	SetImage(TileBackground);

	LoadImage(mMinionImage, MinionImage);
	LoadImage(mBananaImage, BananaImage);
	LoadImage(mMutantImage, MutantImage);

	
}



CTileMinion::~CTileMinion()
{
}


/**  Save this item to an XML node
* \param node The node we are going to be a child of
* \returns Allocated node
*/
std::shared_ptr<xmlnode::CXmlNode> CTileMinion::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	auto itemNode = CTile::XmlSave(node);

	itemNode->SetAttribute(L"type", L"minion");
	itemNode->SetAttribute(L"file", GetFile());

	return itemNode;
}

/**
* brief Load the attributes for an item node.
* \param node The Xml node we are loading the item from
*/
void CTileMinion::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	CTile::XmlLoad(node);
	SetImage(node->GetAttributeValue(L"file", L""));
}

/**
* Load an image into a bitmap
* \param image Image pointer to load
* \param name Filename to load from
*/
void CTileMinion::LoadImage(std::unique_ptr<Gdiplus::Bitmap> &image, std::wstring name)
{
	wstring filename = ImagesDirectory + name;
	image = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
	if (image->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += filename;
		AfxMessageBox(msg.c_str());
	}
}


/** Draw this item
* \param graphics The graphics context to draw on */
void CTileMinion::Draw(Gdiplus::Graphics *graphics)
{
	CTile::Draw(graphics);
	if (mState == Minion)
	{
		int wid = mMinionImage->GetWidth();
		int hit = mMinionImage->GetHeight();

		graphics->DrawImage(mMinionImage.get(),
			(int)(GetX() - OffsetLeft+mRunX), (int)(GetY() + OffsetDown+mRunY - hit),
			wid, hit);
	}

	else if (mState == Mutant)
	{
		int wid = mMutantImage->GetWidth();
		int hit = mMutantImage->GetHeight();

		graphics->DrawImage(mMutantImage.get(),
			(int)(GetX() - OffsetLeft+mRunX), (int)(GetY() +mRunY+ OffsetDown - hit),
			wid, hit);
	}

	if (mState== Banana )
	{
		int wid = mBananaImage->GetWidth();
		int hit = mBananaImage->GetHeight();

		graphics->DrawImage(mBananaImage.get(),
			(int)(GetX() - OffsetLeft+mRunX), (int)(GetY() +mRunY+ OffsetDown - hit),
			wid, hit);
	}
}
/**
*changes state of minion
*/
void CTileMinion::ChangeState()
{
	if (mState == Minion)
	{
		mState = Banana;
	}

	if (mState == Banana)
	{
		mState = Mutant;
	}

	if (mState == Mutant)
	{
		mState = Minion;
	}
}

/**
* Called before the image is drawn
* \param elapsed Time since last draw
*/
void CTileMinion::Update(double elapsed)
{
	CTile::Update(elapsed);
	
	
		// when the Minion is running...
		// mSpeedX is a constant pixels per second running speed...
		mRunX += mSpeedX * elapsed;

		//mSpeedYis a constant pixels per second running speed
		mRunY += mSpeedY *elapsed;

	
}
/**
*Gives the minion a banana
*/
void CTileMinion::GiveBanana()
{
	if (mBananaCount == 0)
	{
		mState = Banana;
	}
	mBananaCount++;
	if (mBananaCount == 4)
	{
		mState = Mutant;
	}

}
/**
*Gives the minion a potion
*/
void CTileMinion::GivePotion()
{
	mState = Minion;
	
	mBananaCount = 0;
}

/**
*Sets speed for minions to run
*/
void CTileMinion::SetSpeed()
{
	mSpeedX = ((double)rand() / RAND_MAX) * 120;
	mSpeedY = ((double)rand() / RAND_MAX) * 100;
}