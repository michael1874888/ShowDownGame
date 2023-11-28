#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#pragma once

using namespace std;

class HumanPlayer : public Player
{
public:
	HumanPlayer();

	~HumanPlayer();

    Card show( void ) override;
};

#endif