#if !defined(_IPLAYER_H__INCLUDED_)
#define _IPLAYER_H__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

using namespace std;

class Card;
class Deck;
class ExchangeHandEvent;

class IPlayer
{
public:
    virtual ~IPlayer( void ) {};
    // Destructor

    virtual void setName( string name ) = 0;

    virtual string getName( void ) = 0;

    virtual void drawCards( Deck &Deck ) = 0;

	virtual void exchangeHands( unique_ptr< IPlayer > &otherPlayer ) = 0;

    virtual Card show( void ) = 0;

    virtual void addPoint( int nAmount ) = 0;

    virtual int getPoints( void ) = 0;

    virtual Hand* takeHands( void ) = 0;

    virtual void setHands( Hand *pHand ) = 0;

    virtual void setExchangeHandEvent( ExchangeHandEvent *pEvent ) = 0;
};
#endif // !defined(_IPLAYER_H__INCLUDED_)
