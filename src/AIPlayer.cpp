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
}

AIPlayer::~AIPlayer()
{
}

Card AIPlayer::show( void )
{
	return m_pHand->takeRandomCard();
}
