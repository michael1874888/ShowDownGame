#ifndef DECK_H
#define DECK_H

#pragma once

using namespace std;

class Deck
{
public:
	Deck();

	~Deck();

	void shuffle( void );

    Card drawCard( void );

	unsigned int getCardNum( void ) const;

private:
	void initCards( void );

	vector< Card > m_Cards;
};

#endif