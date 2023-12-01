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
#include "AIPlayer.h"

AIPlayer::AIPlayer()
{
}

AIPlayer::~AIPlayer()
{
}

optional< Card > AIPlayer::show( void )
{
	return m_pHand->takeRandomCard();
}
