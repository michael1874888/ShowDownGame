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
#include "AIPlayer.h"

AIPlayer::AIPlayer()
{
	m_pExchangeHand = new ExchangeHandEvent( ( Player * ) this );
}

AIPlayer::~AIPlayer()
{
	delete m_pExchangeHand;
}

Card AIPlayer::show( void )
{
	return m_pHand->takeRandomCard();
}
