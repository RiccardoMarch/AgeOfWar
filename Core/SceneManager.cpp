//
// Created by Yikes on 9/12/2022.
//

#include "SceneManager.h"

SceneManager* m_vSceneManager = NULL;

SceneManager::SceneManager() { }
SceneManager::~SceneManager() { }

SceneManager* SceneManager::getInstance() {
    if(m_vSceneManager == NULL) {
        m_vSceneManager = new SceneManager();
    }

    return m_vSceneManager;
}

void SceneManager::onReleaseSceneManager() {
    if(m_vSceneManager) {
        delete m_vSceneManager;
        m_vSceneManager = NULL;
    }
}

bool SceneManager::init() {
    m_vBaseScene = NULL;
    return true;
}

bool SceneManager::onRunScene(int iSceneId, bool bReplace) {
    switch (iSceneId) {
        case SCENE_BASE: {
            if (m_vBaseScene == NULL) {
                m_vBaseScene = BaseScene::create();

                if (m_vBaseScene)
                    m_vBaseScene->autorelease();
            }

            Director::getInstance()->pushScene(m_vBaseScene);

            return true;
        }

        default:
            return false;
    }
}
