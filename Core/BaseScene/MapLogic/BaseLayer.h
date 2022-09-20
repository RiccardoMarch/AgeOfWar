//
// Created by Yikes on 9/12/2022.
//

#ifndef PROJ_ANDROID_BASELAYER_H
#define PROJ_ANDROID_BASELAYER_H

#pragma once

#include "cocos2d.h"

using namespace std;
USING_NS_CC;

#define BUILD_Z_ORDER_MAX 10000

class BaseLayer : public Layer {
public:
    enum LAYER_HANDLE_STATE {
        STATE_NULL = 0,
        STATE_ZOOM = 1,
        STATE_MOVE = 2,
        STATE_DRAG = 3
    };

public:
    BaseLayer();
    ~BaseLayer();

    virtual bool init();

    CREATE_FUNC(BaseLayer);

public:
    virtual void onTouchesBegan(std::vector<Touch*>, Event*);
    virtual void onTouchesMoved(std::vector<Touch*>, Event*);
    virtual void onTouchesEnded(std::vector<Touch*>, Event*);

    virtual void onMapTouchesBegan(std::vector<Touch*>, Event*);
    virtual void onMapTouchesMoved(std::vector<Touch*>, Event*);
    virtual void onMapTouchesEnded(std::vector<Touch*>, Event*);

    void onCreateBaseTexture();
    void onCreateBaseGrid();
    void onCreateTouches();

    Sprite* getNearestSpriteByLocation(Vec2);

    Vec2  convertTouchToRelativeMapPosition(Vec2);


public:
    bool bIsMoved;

    float fTouchSlop = 3.4f;

    Point pTouchBeganPoint;

    Vec2 vGrid[36][36];
    Sprite* sGridSprites[36][36];
    Vec2 vMapLayerOrigin;
};


#endif //PROJ_ANDROID_BASELAYER_H
