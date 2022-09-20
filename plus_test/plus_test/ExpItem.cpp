#include "ExpItem.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "Player.h"
#include "CollisionManager.h"

ExpItem::ExpItem() : EXP(10), stat(0) {
}

ExpItem::~ExpItem() {
    Release();
}

Object* ExpItem::Start(string _Key) {
    Info.Position = Vector3(0.0f, 0.0f);
    Info.Scale = Vector3(1.0f, 1.0f);

    Target = nullptr;

    return this;
}

int ExpItem::Update() {
    
    switch (((Player*)Target)->GetMagnet()) {
    case 0:
        Info.Direction = Vector3(0.0f, 0.0f);
        break;
     default :
         if (CollisionManager::ExpCollision(Info, Target->GetTransform(), ((Player*)Target)->GetMagnet())) 
             stat = 1;
    }
    
    if (stat) 
        Info.Direction = MathManager::GetDirection(Info.Position, Target->GetPosition());
    

    Info.Position += Info.Direction * 2.0f;

    return 0;
}

void ExpItem::Render() {
    CursorManger::GetInstance()->WriteBuffer(Info.Position, (char*)"o", 3);
}

void ExpItem::Release() {
}
