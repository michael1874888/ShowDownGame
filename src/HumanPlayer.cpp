#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <memory>
#include "DeckDef.h"
#include "Card.h"
#include "Hand.h"
#include "Deck.h"
#include "ExchangeHandEvent.h"
#include "Player.h"
#include "HumanPlayer.h"

HumanPlayer::HumanPlayer()
{
	m_pExchangeHand = new ExchangeHandEvent( ( Player * ) this );
}

HumanPlayer::~HumanPlayer()
{
	delete m_pExchangeHand;
}

Card HumanPlayer::show( void )
{
	int nIndex;

	cout << "Please choose a card to show:" << endl;
	m_pHand->showCards();
	cin >> nIndex;

	return m_pHand->takeCard( nIndex - 1 );
}
