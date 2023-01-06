#include "MainMenuScene.h"
#include "GameScene.h"
#include "GameOverScene.h"
#include "Adding.h"
#include "../proj.win32/GameScene.h"
#include "../proj.win32/Adding.h"

USING_NS_CC;

Scene* MainMenu::createScene()
{
    return MainMenu::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool MainMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto backgroundSprite = Sprite::create("welcome.jpeg");
    backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    backgroundSprite->setScale(1.5);
    this->addChild(backgroundSprite);

    auto playItem = MenuItemImage::create("p.png", "p.png", CC_CALLBACK_1(MainMenu::GoToLevel, this));
    playItem->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 30));
    playItem->setScale(1);
    auto playItem1 = MenuItemImage::create("pause(1).png", "pause(1).png", CC_CALLBACK_1(MainMenu::menuCloseCallback, this));
    playItem1->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 60));
    playItem1->setScale(1);

    auto menu = Menu::create(playItem, playItem1, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);

    return true;
}

void MainMenu::GoToLevel(cocos2d::Ref* pSender) {

    auto scene = Level::createScene();
    Director::getInstance()->pushScene(TransitionFade::create(TRANSITION_TIME, scene));

}


void MainMenu::GoToGameOver(cocos2d::Ref* pSender) {

    auto scene = GameOver::createScene();
    Director::getInstance()->pushScene(TransitionFade::create(TRANSITION_TIME, scene));

}
void MainMenu::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

}