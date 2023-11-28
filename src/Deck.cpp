#include <algorithm>
#include <vector>
#include <random>
#include <stdexcept>
#include <string>
#include "DeckDef.h"
#include "Card.h"
#include "Deck.h"

Deck::Deck()
{
	initCards();
}

Deck::~Deck()
{
}

void Deck::shuffle( void )
{
	// create random number generator
	random_device rd;
	mt19937 generator( rd() );

	// shuffle cards
	std::shuffle( m_Cards.begin(), m_Cards.end(), generator );
}

Card Deck::drawCard( void )
{
	if( m_Cards.empty() == true ) {
		throw out_of_range( "No more cards in the deck" );
	}

	Card card = m_Cards.back();
	m_Cards.pop_back();
	return card;
}

unsigned int Deck::getCardNum( void ) const
{
	return m_Cards.size();
}

void Deck::initCards(void)
{
	for( int suit = 0; suit < Card::ES_NumOfSuit; suit++ ) {
		for( int rank = 0; rank < Card::ER_NumOfRank; rank++ ) {
			m_Cards.push_back(Card( Card::ERank( rank ), Card::ESuit( suit ) ));
		}
	}
}