#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <memory>
#include <optional>
#include "DeckDef.h"
#include "Card.h"
#include "Hand.h"
#include "Deck.h"
#include "ExchangeHandEvent.h"
#include "Player.h"
#include "HumanPlayer.h"

HumanPlayer::HumanPlayer()
{
}

HumanPlayer::~HumanPlayer()
{
}

optional< Card > HumanPlayer::show( void )
{
	int nIndex;

	if( m_pHand->getCardCount() == 0 ) {
		return nullopt;
	}

	cout << "Please choose a card to show:" << endl;
	m_pHand->showCards();
	cin >> nIndex;

	return m_pHand->takeCard( nIndex - 1 );
}
