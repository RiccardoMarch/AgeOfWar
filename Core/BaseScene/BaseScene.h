//
// Created by Yikes on 9/12/2022.
//

#ifndef PROJ_ANDROID_BASESCENE_H
#define PROJ_ANDROID_BASESCENE_H

#pragma once

#include "MapLogic/BaseLayer.h"
#include "cocos2d.h"

using namespace std;


class BaseScene : public cocos2d::Scene {
public:
    BaseScene();
    ~BaseScene();

    CREATE_FUNC(BaseScene);

    virtual bool init();

    void onLoadSceneLayer(void);

public:
    class BaseLayer* m_vBaseLayer;
};


#endif //PROJ_ANDROID_BASESCENE_H
