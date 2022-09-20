//
// Created by Yikes on 9/12/2022.
//

#include "iostream"
#include "BaseLayer.h"
#include "cocos2d.h"

void BaseLayer::onMapTouchesBegan(std::vector<Touch *> pTouches, Event *pEvent) {
    this->pTouchBeganPoint = pTouches[0]->getLocation();
    this->bIsMoved = false;
}

void BaseLayer::onMapTouchesMoved(std::vector<Touch *> pTouches, Event *pEvent) {
    auto winSize = Director::getInstance()->getWinSize();
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto visibleOrigin = Director::getInstance()->getVisibleOrigin();

    if (pTouches.size() == 1) {
        auto touch = pTouches[0];
        auto diff = touch->getDelta();
        auto curPos = this->getPosition();

        auto f_distance = touch->getLocation().distance(this->pTouchBeganPoint);

        if(f_distance < this->fTouchSlop)
            return;

        this->bIsMoved = true;

        auto pos = curPos + diff;
        auto bgSize = this->getBoundingBox().size;

        auto x = pos.x;
        auto y = pos.y;

        float min_x = -(bgSize.width - (visibleSize.width / 2));
        float max_x = bgSize.width - (visibleSize.width / 2);
        float min_y = -(bgSize.height - (visibleSize.height / 2));
        float max_y = bgSize.height - (visibleSize.height / 2);

        pos.x = MIN(min_x, MAX(max_x, x));
        pos.y = MIN(min_y, MAX(max_y, y));

        this->setPosition(pos);



        if (pos.x >= bgSize.width * this->getAnchorPoint().x || pos.x <= -bgSize.width + winSize.width + bgSize.width * this->getAnchorPoint().x) {
            diff.x = 0;
        }
        if (pos.y >= bgSize.height * this->getAnchorPoint().y || pos.y <= -bgSize.height + winSize.height + bgSize.height * this->getAnchorPoint().y) {
            diff.y = 0;
        }

        vMapLayerOrigin += diff;
    }
    else if (pTouches.size() > 1) {
        bIsMoved = true;

        auto point1 = pTouches[0]->getLocation();
        auto point2 = pTouches[1]->getLocation();

        auto cur_dist = point1.distance(point2);

        auto prev_dist = pTouches[0]->getPreviousLocation().distance(
                            pTouches[1]->getPreviousLocation());

        auto v_point1 = point1 - vMapLayerOrigin;
        auto v_point2 = point2 - vMapLayerOrigin;

        auto rel_mid_x = (v_point1.x + v_point2.x) / 2;
        auto rel_mid_y = (v_point1.y + v_point2.y) / 2;

        auto anchorX = rel_mid_x/this->getBoundingBox().size.width;
        auto anchorY = rel_mid_y/this->getBoundingBox().size.height;

        //this->setAnchorPoint(Vec2(anchorX, anchorY));

        auto scale = this->getScale() * (cur_dist / prev_dist);
        scale = MIN(5, MAX(0.25f, scale));
        this->setScale(scale);

        //vMapLayerOrigin = Vec2()
    }
}

void BaseLayer::onMapTouchesEnded(std::vector<Touch *> pTouches, Event *pEvent) {
    if (bIsMoved)
        return;

    auto location = this->convertTouchToRelativeMapPosition(pTouches[0]->getLocationInView());
    Sprite* cur_tile = this->getNearestSpriteByLocation(location);

    if(cur_tile->getOpacity() == 100)
        cur_tile->setOpacity(0);
    else
        cur_tile->setOpacity(100);
}