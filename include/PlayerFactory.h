#ifndef PLAYERFACTORY_H
#define PLAYERFACTORY_H

#pragma once

using namespace std;

class PlayerFactory
{
public:
	static vector< unique_ptr< Player > > createPlayers( const unsigned int nHumanNum );
};

#endif