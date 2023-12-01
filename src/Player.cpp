#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>
#include <optional>
#include "Card.h"
#include "Hand.h"
#include "DeckDef.h"
#include "Deck.h"
#include "ExchangeHandEvent.h"
#include "Player.h"

Player::Player()
{
    m_nPoints = 0;
	m_pHand = new Hand();
}

Player::~Player()
{
	delete m_pHand;
}

void Player::setName( string name )
{
    m_Name = name;
}

string Player::getName( void )
{
    return m_Name;
}

void Player::drawCards( Deck &Deck )
{
    try {
		m_pHand->setCard( Deck.drawCard() );
	} catch( const out_of_range &err ) {
		cout << "Cannot draw card: " << err.what() << endl;
	}
}

void Player::exchangeHands( unique_ptr<Player> &OtherPlayer )
{
	shared_ptr< ExchangeHandEvent > Event = make_shared< ExchangeHandEvent >( this, OtherPlayer.get() );
	m_ExchangeHandEvents.push_back( Event );
	Event->exchange();
}

void Player::addPoint( int nAmount )
{
    m_nPoints += nAmount;
}

int Player::getPoints( void )
{
    return m_nPoints;
}

Hand *Player::takeHands( void )
{
    Hand *pTakeHand = m_pHand;
	m_pHand = nullptr;
	return pTakeHand;
}

void Player::setHands( Hand *pHand )
{
    m_pHand = pHand;
}

void Player::notifyRoundFinished( void )
{
	for( auto &Event : m_ExchangeHandEvents ) {
		Event->updateRound();
	}
}
