#ifndef AIPLAYER_H
#define AIPLAYER_H

#pragma once

using namespace std;

class AIPlayer: public Player
{
public:
	AIPlayer();

	~AIPlayer();

    optional< Card > show( void ) override;
};

#endif