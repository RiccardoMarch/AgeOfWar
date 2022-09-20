//
// Created by Yikes on 9/12/2022.
//

#include "BaseScene.h"

#include "Core/SceneManager.h"

#include "cocos2d.h"

BaseScene::BaseScene() {
    m_vBaseLayer = NULL;
}

BaseScene::~BaseScene() {
    //SceneManager::getInstance()->m_vBaseScene = NULL;
}

bool BaseScene::init() {
    if (!Scene::init()) {
        return false;
    }

    onLoadSceneLayer();
    return true;
}

void BaseScene::onLoadSceneLayer() {
    m_vBaseLayer = BaseLayer::create();
    this->addChild(m_vBaseLayer);
}

