#ifndef __MAIN_MENU_SCENE_H__
#define __MAIN_MENU_SCENE_H__

#include "cocos2d.h"

class MainMenu : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    void menuCloseCallback(cocos2d::Ref* pSender);
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(MainMenu);
private:
    void GoToLevel(cocos2d::Ref* sender);
    void GoToGameOver(cocos2d::Ref* sender);
};

#endif // __MAIN_MENU_SCENE_H__