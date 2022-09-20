//
// Created by Yikes on 9/12/2022.
//
#include "iostream"
#include "BaseLayer.h"
#include "cocos2d.h"

BaseLayer::BaseLayer() {}
BaseLayer::~BaseLayer() {}

bool BaseLayer::init() {
    if(!Layer::init())
        return false;

    //onCreateBaseTexture();
    onCreateBaseGrid();
    onCreateTouches();
    return true;
}

void BaseLayer::onCreateBaseTexture() {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto originSize = Director::getInstance()->getVisibleOrigin();


    auto bg_left = Sprite::create("base_res/small_magic_bgr_left.png");
    auto bg_right = Sprite::create("base_res/small_magic_bgr_right.png");

    float c_scr_x = (visibleSize.width / 2 + originSize.x);
    float c_scr_y = (visibleSize.height / 2 + originSize.y);

    float max_width = bg_left->getTextureRect().getMaxX() + bg_right->getTextureRect().getMaxX();

    float c_left_x = c_scr_x - ((max_width / 2) - (bg_left->getTextureRect().getMaxX() / 2));
    float s_top_y = c_scr_y;
    float s_left_x_2 = (c_left_x + ((bg_left->getTextureRect().getMaxX() / 2) + (bg_right->getTextureRect().getMaxX() / 2)));

    bg_left->setPosition(Vec2(c_left_x, c_scr_y));
    bg_right->setPosition(Vec2(s_left_x_2, c_scr_y));

    this->addChild(bg_left, 0);
    this->addChild(bg_right, 0);
}

void BaseLayer::onCreateBaseGrid() {
    float offsetX = 12;
    float offsetY = 184;

    for (int x = 0; x < 36; x++) {
        for (int y = 0; y < 36; y++) {
            auto tile = Sprite::create("base_res/build_1_1.png");

            float inc_x = 0.075 / 35;
            float inc_y = 0.012 / 35;

            float tile_size_x = tile->getTextureRect().size.width * (0.86f + (inc_x * x));
            float tile_size_y = tile->getTextureRect().size.height * (0.86f + (inc_y * y));

            tile->setContentSize(Size(tile_size_x, tile_size_y));
            tile->setOpacity(100);

            float p_x = offsetX + ((tile_size_x / 2) * (x + y));
            float p_y = offsetY + ((tile_size_y / 2) * (y - x));

            Vec2 pos = Vec2(p_x, p_y);
            tile->setPosition(pos);

            vGrid[x][y] = pos;
            sGridSprites[x][y] = tile;

            this->addChild(tile, 1);
        }
    }
}

void BaseLayer::onCreateTouches() {
    auto touchListener = EventListenerTouchAllAtOnce::create();

    touchListener->onTouchesBegan = CC_CALLBACK_2(BaseLayer::onTouchesBegan, this);
    touchListener->onTouchesMoved = CC_CALLBACK_2(BaseLayer::onTouchesMoved, this);
    touchListener->onTouchesEnded = CC_CALLBACK_2(BaseLayer::onTouchesEnded, this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
}

Sprite* BaseLayer::getNearestSpriteByLocation(Vec2 location) {
    Sprite* result = sGridSprites[0][0];
    float last_dist = vGrid[0][0].distance(location);

    for(int x = 0; x < 36; x++) {
        for (int y = 0; y < 36; y++) {
            float cur_dist = vGrid[x][y].distance(location);
            if(cur_dist < last_dist) {
                last_dist = cur_dist;
                result = sGridSprites[x][y];
            }
        }
    }

    return result;
}

Vec2 BaseLayer::convertTouchToRelativeMapPosition(Vec2 location) {
    return this->convertToNodeSpace(Director::getInstance()->convertToGL(location));
}
