#include <string>
#include <cassert>
#include "Card.h"

Card::Card( void )
{
}

Card::Card( ERank Rank, ESuit Suit )
{
    m_Rank = Rank;
    m_Suit = Suit;
}


Card::~Card()
{
}

string Card::getRank( void ) const
{
    switch( m_Rank ) {
    case ER_Two:
        return "Two";
    case ER_Three:
        return "Three";
    case ER_Four:
        return "Four";
    case ER_Five:
        return "Five";
    case ER_Six:
        return "Six";
    case ER_Seven:
        return "Seven";
    case ER_Eight:
        return "Eight";
    case ER_Nine:
        return "Nine";
    case ER_Ten:
        return "Ten";
    case ER_J:
        return "J";
    case ER_Q:
        return "Q";
    case ER_K:
        return "K";
    case ER_A:
        return "A";
    default:
        assert( false );
        return "Unknown";
    }
}

string Card::getSuit( void ) const
{
    switch( m_Suit ) {
    case ES_Spade:
        return "Spade";
    case ES_Heart:
        return "Heart";
    case ES_Diamond:
        return "Diamond";
    case ES_Club:
        return "Club";
    default:
        assert( false );
        return "Unknown";
    }
}

bool Card::operator==( const Card &other ) const
{
	return m_Rank == other.m_Rank && m_Suit == other.m_Suit;
}

bool Card::operator!=( const Card &other ) const
{
	return !( *this == other );
}

bool Card::operator<( const Card &other ) const
{
	if( m_Rank == other.m_Rank ) {
		return m_Suit < other.m_Suit;
	}
	return m_Rank < other.m_Rank;
}

bool Card::operator<=( const Card &other ) const
{
	return *this < other || *this == other;
}

bool Card::operator>( const Card &other ) const
{
	return !( *this <= other );
}

bool Card::operator>=( const Card &other ) const
{
	return !( *this < other );
}
