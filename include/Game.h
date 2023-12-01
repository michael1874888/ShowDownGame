#ifndef GAME_H
#define GAME_H

#pragma once

using namespace std;

class Game
{
public:
    Game();

    ~Game();

    void start( void );

private:
    void executeRounds( void );

    void takeTurn( vector< Card > *pCompareList );

    void createPlayers( void );

    void namePlayers( void );

    void drawCards( void );

    void exchangeHands( int nCurPlayerID );

    void displayCards( const vector< Card > &CompareList );

    void pickWinnerForRound( const vector< Card > &CompareList );

    void showWinner( void );

    void notifyRoundFinished( void );

	vector< unique_ptr< Player > > m_pPlayers;

    Deck m_Deck;
};

#endif