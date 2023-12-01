#include <string>
#include <vector>
#include <memory>
#include <optional>
#include "Card.h"
#include "Hand.h"
#include "DeckDef.h"
#include "Deck.h"
#include "ExchangeHandEvent.h"
#include "Player.h"
#include "AIPlayer.h"
#include "HumanPlayer.h"
#include "PlayerFactory.h"

#define MAX_PLAYER_NUM ( 4 )

vector< unique_ptr< Player > > PlayerFactory::createPlayers( const unsigned int nHumanNum )
{
	vector< unique_ptr< Player > > players;

	for( unsigned int i = 0; i < nHumanNum; i++ ) {
		players.push_back( make_unique< HumanPlayer >() );
	}

	for( unsigned int i = 0; i < ( MAX_PLAYER_NUM - nHumanNum ); i++ ) {
		players.push_back( make_unique< AIPlayer >() );
	}

	return players;
}