//
// Created by Yikes on 9/12/2022.
//

#include <iostream>
#include "BaseLayer.h"
#include "cocos2d.h"

void BaseLayer::onTouchesBegan(std::vector<Touch *> pTouches, Event *pEvent) {
    this->onMapTouchesBegan(pTouches, pEvent);
}

void BaseLayer::onTouchesMoved(std::vector<Touch *> pTouches, Event *pEvent) {
    this->onMapTouchesMoved(pTouches, pEvent);
}

void BaseLayer::onTouchesEnded(std::vector<Touch *> pTouches, Event *pEvent) {
    this->onMapTouchesEnded(pTouches, pEvent);
}
