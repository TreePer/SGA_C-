#include "Skill.h"
#include "ObjectManager.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "ObjectFactory.h"
#include "Arrow.h"
#include "Bullet.h"
#include "Book.h"
#include "Fire.h"
#include "Bridge.h"

Object* Skill::Start(string _Key) {
    Key = _Key;

    ArrowTime = GetTickCount64();
    BookTime = GetTickCount64();
    BulletTime = GetTickCount64();
    FireTime = GetTickCount64();

    pBridge = nullptr;

    BridgeList[SkillID_Arrow] = new Arrow;
    BridgeList[SkillID_Book] = new Book;
    BridgeList[SkillID_Bullet] = new Bullet;
    BridgeList[SkillID_Fire] = new Fire;


    return this;
}

int Skill::Update() {
    if (pBridge) {
        pBridge->Update();
    }
    
    return 0;
}

void Skill::Render() {
    if (pBridge) {
        pBridge->Render();
    }
}

void Skill::Release() {
    if (pBridge) {
        delete pBridge;
        pBridge = nullptr;
    }
}


Skill::Skill() : pBridge(nullptr), ArrowTime(0), BookTime(0), BulletTime(0), FireTime(0) {
}

Skill::~Skill() {
    Release();
}
