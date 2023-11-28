#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <cassert>
#include <string>
#include "Card.h"
#include "Hand.h"

Hand::Hand()
{
}

Hand::~Hand()
{
}

void Hand::setCard( Card Card )
{
    m_Cards.push_back( Card );
}

Card Hand::takeCard( int nIndex )
{
    // TODO: deal with empty cards
    Card takeCard = std::move( m_Cards[ nIndex ] );

	// 從 vector 中移除該 Card
	m_Cards.erase( m_Cards.begin() + nIndex );

	return takeCard;
}

Card Hand::takeRandomCard( void )
{
	std::random_device rd;
	std::mt19937 gen( rd() );// 以隨機數種子初始化 Mersenne Twister 產生器

	assert( m_Cards.empty() == false );

	std::uniform_int_distribution<> dis( 0, m_Cards.size() - 1 );// 均勻分佈
	int nRandomIndex = dis( gen );                                // 產生一個隨機索引

	// 取出隨機選擇的 Card
	return takeCard( nRandomIndex );
}

int Hand::getCardCount() const
{
    return m_Cards.size();
}

void Hand::showCards( void )
{
	for( size_t i = 0; i < m_Cards.size(); i++ ) {
        cout << i + 1 << ": " << m_Cards[ i ].getSuit() << " " << m_Cards[ i ].getRank() << endl;
    }
}