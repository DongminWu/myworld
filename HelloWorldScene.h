#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
//#include "HeroMove.h"

USING_NS_CC;


class HelloWorld : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
	void Move4Direction(cocos2d::CCSprite * hero,
        cocos2d::CCTexture2D * herotexture,int direction,float pace,float actTime);


    void MovoToTouch(cocos2d::CCSprite *hero ,float dx,float dy,float v);
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);


    
   
    
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);



    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);


private:

     float touchx,touchy;


};

#endif // __HELLOWORLD_SCENE_H__
