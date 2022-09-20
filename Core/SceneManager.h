//
// Created by Yikes on 9/12/2022.
//

#ifndef PROJ_ANDROID_SCENEMANAGER_H
#define PROJ_ANDROID_SCENEMANAGER_H

#pragma once
#include "cocos2d.h"
using namespace cocos2d;

#include "BaseScene/BaseScene.h"

enum SCENE_ID {
    SCENE_BASE
};

class SceneManager {
public:
    class Scene *m_vBaseScene;

public:
    SceneManager();
    ~SceneManager();

    bool init(void);
    bool onRunScene(int iSceneId, bool bReplace);

    static SceneManager* getInstance(void);
    static void onReleaseSceneManager(void);

    Scene* getSceneById(int iSceneId);
};


#endif //PROJ_ANDROID_SCENEMANAGER_H
