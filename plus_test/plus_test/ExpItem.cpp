#include "ExpItem.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "Player.h"
#include "CollisionManager.h"
#include "ObjectManager.h"

ExpItem::ExpItem() : EXP(10) {
}

ExpItem::~ExpItem() {
    Release();
}

Object* ExpItem::Start(string _Key) {
    Info.Position = Vector3(0.0f, 0.0f);
    Info.Scale = Vector3(2.0f, 1.0f);
    EXP = 10;
    Target = nullptr;

    return this;
}

int ExpItem::Update() {
    Object* pPlayer = ObjectManager::GetInstance()->GetPlayer();
    if (Target == nullptr) {
        if (CollisionManager::ExpCollision(pPlayer->GetTransform(), Info, ((Player*)pPlayer)->GetMagnet())) {
            Target = pPlayer;
        }
    }
    else {
        Target = ObjectManager::GetInstance()->GetPlayer();
        Info.Direction = MathManager::GetDirection(Info.Position, Target->GetPosition());
        Info.Position += Info.Direction;

        if (CollisionManager::RectCollision(pPlayer->GetTransform(), Info))
            ((Player*)pPlayer)->SetExp(((Player*)pPlayer)->GetExp() + EXP);
            return 1;
    }
    
    return 0;
}

void ExpItem::Render() {
    CursorManger::GetInstance()->WriteBuffer(Info.Position, (char*)"o", 3);
}

void ExpItem::Release() {
}
