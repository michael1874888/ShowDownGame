#include <vector>
#include <stdexcept>
#include <memory>
#include <string>
#include "DeckDef.h"
#include "Card.h"
#include "Hand.h"
#include "Deck.h"
#include "Player.h"
#include "Hand.h"
#include "ExchangeHandEvent.h"

ExchangeHandEvent::ExchangeHandEvent( Player *pPlayer1 )
{
    m_pPlayer1 = pPlayer1;
    m_pPlayer2 = nullptr;
    m_nRound = 0;
}

ExchangeHandEvent::~ExchangeHandEvent()
{
}

void ExchangeHandEvent::setTargetPlayer( Player *pTargetPlayer )
{
	m_pPlayer2 = pTargetPlayer;
}

void ExchangeHandEvent::exchange( void )
{
	Hand *pPlayer1Hand = m_pPlayer1->takeHands();
	Hand *pPlayer2Hand = m_pPlayer2->takeHands();
	m_pPlayer1->setHands( pPlayer2Hand );
	m_pPlayer2->setHands( pPlayer1Hand );
}

void ExchangeHandEvent::updateRound(void)
{
    m_nRound++;

    if( m_nRound >= 3 ) {
        exchange();
        reset();
    }
}

void ExchangeHandEvent::reset()
{
    m_pPlayer2 = nullptr;
    m_nRound = 0;
}