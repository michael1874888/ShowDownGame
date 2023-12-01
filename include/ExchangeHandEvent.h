#ifndef EXCHANGEHANDEVENT_H
#define EXCHANGEHANDEVENT_H

#pragma once

class Player;

class ExchangeHandEvent
{
public:
    ExchangeHandEvent( Player *pPlayer1, Player *pPlayer2 );

    ~ExchangeHandEvent();

    void exchange( void );

    void updateRound( void );

private:
    void reset( void );

    Player *m_pPlayer1;

    Player *m_pPlayer2;

    unsigned int m_nRound;
};

#endif