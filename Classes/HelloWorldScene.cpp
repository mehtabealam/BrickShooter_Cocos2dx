/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
       auto scene = Scene::createWithPhysics();
       scene->getPhysicsWorld()->setDebugDrawMask( PhysicsWorld::DEBUGDRAW_ALL );
       
       // 'layer' is an autorelease object
       auto layer = HelloWorld::create();
       layer->SetPhysicsWorld( scene->getPhysicsWorld() );

       // add layer as a child to scene
       scene->addChild(layer);
    return  scene;
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
        
    auto edgeBody = PhysicsBody::createEdgeBox( visibleSize, PhysicsMaterial(1, 1, 0), 6 );
        auto edgeNode = Node::create();
        edgeNode ->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y ) );
        edgeNode->setPhysicsBody( edgeBody );
        
        this->addChild( edgeNode );
    
    
     auto ballBody = PhysicsBody::createCircle(10, PhysicsMaterial(1, 1.5, 0));
    ballBody->setMass(1);
    ballBody->setGravityEnable(true);
    auto ballNode = Node::create();
    ballBody->applyImpulse(Vec2(400, 10));
    ballNode->setPosition(Point(200, 200));
    ballNode->setPhysicsBody(ballBody);
    this->addChild(ballNode);
    this->addPedalController();
    return true;
}

void HelloWorld::addPedalController() {
    auto visibleSize = Director::getInstance()->getVisibleSize();
      Vec2 origin = Director::getInstance()->getVisibleOrigin();
      auto pedalBody = PhysicsBody::createBox(Size(visibleSize.width * 0.4, 15));
    pedalBody->setDynamic(false);
    pedalBody->setMass(2);
    pedalBody->setGravityEnable(false);
       auto pedalNode = Node::create();
    pedalNode ->setPosition( Point( visibleSize.width / 2 + origin.x, 20 ) );
    pedalNode->setPhysicsBody(pedalBody);
       this->addChild(pedalNode);
}
