#include "stdio.h"
#include "cocos2d.h"


class HeroMove
{
public:
	HeroMove();
	~HeroMove();

	/* data */

	void initWithSprite(CCSprite * hero);
   
    bool heroUpMove();

    bool heroDownMove();

    bool heroLeftMove();

    bool heroRightMove();

private:

	CCSprite * m_hero;


};