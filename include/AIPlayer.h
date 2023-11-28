#ifndef AIPLAYER_H
#define AIPLAYER_H

#pragma once

using namespace std;

class AIPlayer: public Player
{
public:
	AIPlayer();

	~AIPlayer();

    Card show( void ) override;
};

#endif