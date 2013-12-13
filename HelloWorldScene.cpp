#include "HelloWorldScene.h"
#include "AppMacros.h"

#define UP 1
#define DOWN 2
#define RIGHT 3
#define LEFT 4

USING_NS_CC;




void HelloWorld::Move4Direction(cocos2d::CCSprite * hero,
    cocos2d::CCTexture2D * herotexture,int direction,float pace,float actTime){

    


        //4*4.48*48  png
    CCSpriteFrame * frame0 = new CCSpriteFrame();
    CCSpriteFrame * frame1 = new CCSpriteFrame();
    CCSpriteFrame * frame2 = new CCSpriteFrame();
    CCSpriteFrame * frame3 = new CCSpriteFrame();

    //frame init

    



    if(direction==DOWN){
    frame0->initWithTexture(herotexture,CCRect(24*0,24*0,24,24));
    
    frame1->initWithTexture(herotexture,CCRect(24*1,24*0,24,24));

    frame2->initWithTexture(herotexture,CCRect(24*2,24*0,24,24));

    frame3->initWithTexture(herotexture,CCRect(24*3,24*0,24,24));
    }
    if(direction==UP){
    frame0->initWithTexture(herotexture,CCRect(24*0,24*2,24,24));
    
    frame1->initWithTexture(herotexture,CCRect(24*1,24*2,24,24));

    frame2->initWithTexture(herotexture,CCRect(24*2,24*2,24,24));

    frame3->initWithTexture(herotexture,CCRect(24*3,24*2,24,24));
    } 
    if(direction==RIGHT){
    frame0->initWithTexture(herotexture,CCRect(24*0,24*3,24,24));
    
    frame1->initWithTexture(herotexture,CCRect(24*1,24*3,24,24));

    frame2->initWithTexture(herotexture,CCRect(24*2,24*3,24,24));

    frame3->initWithTexture(herotexture,CCRect(24*3,24*3,24,24));
    } 
    if(direction==LEFT){
    frame0->initWithTexture(herotexture,CCRect(24*0,24*1,24,24));
    
    frame1->initWithTexture(herotexture,CCRect(24*1,24*1,24,24));

    frame2->initWithTexture(herotexture,CCRect(24*2,24*1,24,24));

    frame3->initWithTexture(herotexture,CCRect(24*3,24*1,24,24));
    }




    CCArray* frames=new CCArray();

    frames->addObject(frame0);
    frames->addObject(frame1);
    frames->addObject(frame2);
    frames->addObject(frame3);

    CCAnimation * frameAnimation= new CCAnimation();

    frameAnimation->initWithSpriteFrames(frames,actTime/4);

    CCAnimate * animate=new CCAnimate();

    animate->initWithAnimation(frameAnimation);


    CCMoveTo * moveTo=new CCMoveTo();
   
    if(direction==UP){
    moveTo->initWithDuration(actTime,
        ccp(hero->getPosition().x,hero->getPosition().y+pace));
    }
    if(direction==DOWN){
    moveTo->initWithDuration(actTime,
        ccp(hero->getPosition().x,hero->getPosition().y-pace));
    }
    if(direction==RIGHT){
    moveTo->initWithDuration(actTime,
        ccp(hero->getPosition().x+pace,hero->getPosition().y));
    }
    if(direction==LEFT){
    moveTo->initWithDuration(actTime,
        ccp(hero->getPosition().x-pace,hero->getPosition().y+pace));
    }


    CCSpawn * together =new CCSpawn();

    together->initWithTwoActions(moveTo,animate);

    hero->runAction(together);
    // hero->runAction(animate);


}




CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Arial", TITLE_FONT_SIZE);
    
    // position the label on the center of the screen
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(pLabel, 1);
    /*
    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);
    */

    CCImage * heroimage=new CCImage();  
    heroimage->initWithImageFile("myhero.png");

    CCTexture2D * herotexture =new CCTexture2D();
    herotexture->initWithImage(heroimage);

    // CCSpriteFrame * frame0 = new CCSpriteFrame();
    // CCSpriteFrame * frame1 = new CCSpriteFrame();
    // CCSpriteFrame * frame2 = new CCSpriteFrame();
    // CCSpriteFrame * frame3 = new CCSpriteFrame();

    // frame0->initWithTexture(herotexture,CCRect(24*0,24*0,24,24));
    
    // frame1->initWithTexture(herotexture,CCRect(24*1,24*0,24,24));

    // frame2->initWithTexture(herotexture,CCRect(24*2,24*0,24,24));

    // frame3->initWithTexture(herotexture,CCRect(24*3,24*0,24,24));


    // CCArray* heroanimationarray=new CCArray();
    // heroanimationarray->addObject(frame0);
    // heroanimationarray->addObject(frame1);
    // heroanimationarray->addObject(frame2);
    // heroanimationarray->addObject(frame3);


    // CCAnimation * heroanimation= new CCAnimation();

    // heroanimation->initWithSpriteFrames(heroanimationarray,0.1f);

    CCSprite * herosprite =new CCSprite();

    // //herosprite->initWithSpriteFrame(frame0);
    herosprite->initWithTexture(herotexture,CCRect(24*0,24*0,24,24));
    herosprite->setPosition(ccp(visibleSize.width/2,visibleSize.height/2));

    
    CCSprite * herosprite2 =new CCSprite();

     herosprite2->initWithTexture(herotexture,CCRect(24,24*0,24,24));
    herosprite2->setPosition(ccp(visibleSize.width/2,visibleSize.height/2+24));
      Move4Direction(herosprite,herotexture,RIGHT,10,0.4);

    this->addChild(herosprite,999);

     this->addChild(herosprite2,999);

    //must translate to CCanimate  the CCanimation extends from CCobject  CCanimate extends from CCAction

    //the runAction(* CCAction)

   //  CCAnimate * heroanimate = new CCAnimate();
   //  heroanimate->initWithAnimation(heroanimation);

   //  herosprite->runAction(heroanimate);

   //  herosprite2->setTextureRect(CCRect(24*0,24*2,24,24));

   //  CCMoveTo * moveTo=new CCMoveTo();
   //  moveTo->initWithDuration(0.4f,
   //      ccp(herosprite->getPosition().x,herosprite->getPosition().y-10));

   // // CCActionInterval * heroaction=new CCActionInterval();

   //  herosprite->runAction(moveTo);

    //herosprite2->setPosition(ccp(herosprite2->getPosition().x-24,herosprite2->getPosition().y));
    //herosprite2->setVisible(false);
   

   // herosprite->setTexture(f)


    return true;    
}


void HelloWorld::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}
