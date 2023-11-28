#ifndef CARD_H
#define CARD_H

#pragma once

using namespace std;

class Card
{
public:
    enum ERank {
        ER_Two,
        ER_Three,
        ER_Four,
        ER_Five,
        ER_Six,
        ER_Seven,
        ER_Eight,
        ER_Nine,
        ER_Ten,
        ER_J,
        ER_Q,
        ER_K,
        ER_A,
        ER_NumOfRank
    };

    enum ESuit {
        ES_Club,
        ES_Diamond,
        ES_Heart,
        ES_Spade,
        ES_NumOfSuit
    };

	Card( ERank Rank, ESuit Suit );

	~Card();

    string getRank( void ) const;

    string getSuit( void ) const;

	bool operator==( const Card &other ) const;

	bool operator!=( const Card &other ) const;

	bool operator<( const Card &other ) const;

	bool operator<=( const Card &other ) const;

	bool operator>( const Card &other ) const;
    
	bool operator>=( const Card &other ) const;

private:
	ERank m_Rank;

    ESuit m_Suit;
};

#endif