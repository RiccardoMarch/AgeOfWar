//
// Created by Yikes on 9/12/2022.
//

#include "MainScene.h"
#include "Core/SceneManager.h"

USING_NS_CC;

Scene *MainScene::onCreateScene() {
    return MainScene::create();
}

bool MainScene::init() {
    if(!Scene::init())
        return false;

    onLoadSceneLayer();
    return true;
}

void MainScene::onLoadSceneLayer(void) {
    BaseLayer* layer = BaseLayer::create();
    this->addChild(layer);
}

