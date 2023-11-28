#ifndef PLAYER_H
#define PLAYER_H

#pragma once

class ExchangeHandEvent;

class Player
{
public:
    Player();

    ~Player();

    void setName( string name );

    string getName( void );

    void drawCards( Deck &Deck );

	void exchangeHands( unique_ptr<Player> &OtherPlayer );

    virtual Card show( void ) = 0;

    void addPoint( int nAmount );

    int getPoints( void );

    Hand* takeHands( void );

    void setHands( Hand *pHand );

    void setExchangeHandEvent( ExchangeHandEvent *pEvent );

protected:
    string m_Name;

    Hand *m_pHand;

    int m_nPoints;

    ExchangeHandEvent *m_pExchangeHand;
};

#endif