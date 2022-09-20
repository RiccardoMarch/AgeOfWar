//
// Created by Yikes on 9/12/2022.
//

#ifndef PROJ_ANDROID_MAINSCENE_H
#define PROJ_ANDROID_MAINSCENE_H

#include "cocos2d.h"
using namespace std;

USING_NS_CC;

class MainScene : public cocos2d::Scene {

public:
    static cocos2d::Scene* onCreateScene();

    CREATE_FUNC(MainScene);

    void onLoadSceneLayer(void);

    virtual bool init();
};


#endif //PROJ_ANDROID_MAINSCENE_H
