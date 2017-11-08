/**
* \file PointHistory.cpp
*
* \author Charles Owen
*
* Class that maintains a collection of Point objects in order.
*/

#pragma once
#include <memory>

/**
 * Class that maintains a collection of Point objects in order.
 */
class CPointHistory
{
public:
	CPointHistory();
	virtual ~CPointHistory();

	void Add(Gdiplus::Point p);

protected:
	/**
	* Nested class that stores up to five points in a bin.
	*/
	class PointBin
	{
	public:
		/// Maximum number of points we can put into a bin
		const static int MaxPoints = 5;

		/// Constructor
		PointBin() {}

		/// Destructor
		virtual ~PointBin() {}

		/// Get the current count of items in this bin
		/// \return Count (zero to five)
		int GetCnt() { return mCnt; }

		bool Add(Gdiplus::Point point);

		/// Get a stored point
		/// \param i Index to the point (0 to mCnt-1)
		/// \return Stored point value
		Gdiplus::Point Get(int i) { return mPoints[i]; }

		/// Get the next bin in the list
		/// \return Pointer to next bin or null if none
		std::shared_ptr<PointBin> GetNext() { return mNext; }

		/// Set the next bin in the list
		/// \param next Next pointer to set
		void SetNext(std::shared_ptr<PointBin> next) { mNext = next; }

		

	private:
		/// Array to store the points
		Gdiplus::Point mPoints[MaxPoints];

		/// Number of elements currently stored in array
		int mCnt = 0;

		/// Next bin
		std::shared_ptr<PointBin> mNext;
	};


	/// Pointer to the head of the linked list of bins
	std::shared_ptr<PointBin> mHead;

	
private:
	/// Pointer to the tail of the linked list of bins (last node)
	std::shared_ptr<PointBin> mTail;

public:
	/** Iterator that iterates over the points clicked */
	class Iter
	{
	public:
		/** Constructor
		* \param point The pointhistory we are iterating over
		* \param pos The integer postition in the bin
		* \param bin The current bin in the array
		*/
		Iter(CPointHistory *point, std::shared_ptr<PointBin> bin,int pos) : mPointHistory(point), mBin(bin),mPos(pos){}

		/** Test for end of the iterator
		* \param other is another iter to check against
		* \returns True if we this position equals not equal to the other position */
		bool operator!=(const Iter &other) const
		{
			if (mBin != other.mBin || mPos != other.mPos)
			{
				return true;
			}

			else
			{
				return false;
			}
			
		}

		/** Get value at current position
		* \returns Value at mPos in the collection */
		Gdiplus::Point operator *() const { return mBin->Get(mPos); }

		/** Increment the iterator
		* \returns Reference to this iterator */
		const Iter& operator++()
		{
			mPos++;
			if (mPos ==mBin->GetCnt())
			{
				mPos = 0;
				mBin=mBin->GetNext();
			}

			return *this;
		}


	private:
		CPointHistory *mPointHistory;   ///< Collection of Clicks we are iterating over
		std::shared_ptr<PointBin> mBin; ///<points to the current bin
		int mPos;   ///<current position in bin
	};



	/** Get an iterator for the beginning of the collection
	* \returns Iter object at position mHead */
	Iter begin() { return Iter(this,mHead,0); }

	/** Get an iterator for the end of the collection
	* \returns Iter object at position past the end */
	Iter end() { return Iter(this,nullptr,0); }
};

