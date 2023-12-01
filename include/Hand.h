#ifndef HAND_H
#define HAND_H

#pragma once

using namespace std;

class Hand
{
public:
    Hand();

	~Hand();

	void setCard( Card Card );

	optional< Card > takeCard( int nIndex );

	optional< Card > takeRandomCard( void );

	int getCardCount() const;

	void showCards( void );

private:
	vector< Card > m_Cards;
};

#endif