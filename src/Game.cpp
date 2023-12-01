#include <iostream>
#include <string>
#include <vector>
#include <memory> 
#include "DeckDef.h"
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "ExchangeHandEvent.h"
#include "Player.h"
#include "PlayerFactory.h"
#include "Game.h"

#define TOTAL_ROUNDS ( 13 )
#define TOTAL_PLAYER_NUM ( 4 )

Game::Game()
{
}

Game::~Game()
{
}

void Game::start( void )
{
	// create players
	createPlayers();

    // name players
	namePlayers();

	// shuffle
	m_Deck.shuffle();

	// draw cards form deck
	drawCards();

    // execute rounds
	executeRounds();

	// show winner
	showWinner();
}

void Game::executeRounds( void )
{
	vector< Card > CompareList;

	for( int i = 0; i < TOTAL_ROUNDS; i++ ) {
		// initialize vector
		CompareList.clear();

		// take turn
		takeTurn( &CompareList );

		// display cards
		displayCards( CompareList );

		// decide winner and give points to players
		pickWinnerForRound( CompareList );

		// notify players that the current round is over
		notifyRoundFinished();
	}
}

void Game::takeTurn( vector< Card > *pCompareList )
{
    for( int i = 0; i < TOTAL_PLAYER_NUM; i++ ) {
		// exchange hands
		exchangeHands( i  );

    	// show card
		pCompareList->push_back( m_pPlayers[ i ]->show() );
	}
}

void Game::createPlayers( void )
{
	unsigned int HumanPlayerNum = 0;

	do {
		cout << "Game Start!" << endl;
		cout << "Please input number of human players(1~4): ";
		cin >> HumanPlayerNum;
	} while( HumanPlayerNum < 1 || HumanPlayerNum > 4 );

	m_pPlayers = PlayerFactory::createPlayers( HumanPlayerNum );
}

void Game::namePlayers( void )
{
	cout << "Input player name" << endl;

	string PlayerName;
	for( int i = 0; i < TOTAL_PLAYER_NUM; i++ ) {
		cout << "Player " << i + 1 << ": ";
		cin >> PlayerName;
		m_pPlayers[ i ]->setName( PlayerName );
	}
}

void Game::drawCards( void )
{
	cout << "Start drawing cards!" << endl;
	while( m_Deck.getCardNum() > 0 ) {
		for( int i = 0; i < TOTAL_PLAYER_NUM; i++ ) {
			if( m_Deck.getCardNum() == 0 ) {
				break;
			}

			m_pPlayers[ i ]->drawCards( m_Deck );
		}
	}

	cout << "Draw cards Finished!" << endl;
}

void Game::exchangeHands( int nCurPlayerID )
{
	string WantExchange;
	int nPlayerID;

	// ask player if want to exchange
	cout << "Do ypu want to exchange hands with other player?(y/n)" << endl;
	cin >> WantExchange;

	// return if the player doesn't want to exchange
	if( WantExchange == "n" ) {
		return;
	}

	// ask target to exchange
	do {
		cout << "Please choose player you want to exchange: ";
		cin >> nPlayerID;
		nPlayerID -= 1;		//  -1 to match the real index
	}while( nPlayerID < 0 || nPlayerID >= TOTAL_PLAYER_NUM || nPlayerID == nCurPlayerID );

	// exchange hands
	m_pPlayers[ nCurPlayerID ]->exchangeHands( m_pPlayers[ nPlayerID ] );
}

void Game::displayCards( const vector< Card > &CompareList )
{
	for( size_t i = 0; i < CompareList.size(); i++ ) {
		cout << "Player" << i + 1 << ": " << CompareList[ i ].getSuit() << " " << CompareList[ i ].getRank() << endl;
	}
}

void Game::pickWinnerForRound( const vector< Card > &CompareList )
{
	int nWinnerIndex = 0;

	for( size_t i = 0; i < CompareList.size() - 1; i++ ) {
		if( CompareList[ i + 1 ] > CompareList[ i ] ) {
			nWinnerIndex = i + 1;
		}
	}

	m_pPlayers[ nWinnerIndex ]->addPoint( 1 );
	cout << m_pPlayers[ nWinnerIndex ]->getName() << " win the round" << endl;
}

void Game::showWinner( void )
{
	int nWinnerIdx = 0;

	for( size_t i = 0; i < ( m_pPlayers.size() - 1 ); i++ ) {
		if( m_pPlayers[ i + 1 ]->getPoints() > m_pPlayers[ i ]->getPoints() ) {
			nWinnerIdx = i + 1;
		}
	}

	cout << "The winner goes to :" << m_pPlayers[ nWinnerIdx ]->getName() << endl;
}

void Game::notifyRoundFinished( void )
{
	for( auto &Player : m_pPlayers ) {
		Player->notifyRoundFinished();
	}
}
