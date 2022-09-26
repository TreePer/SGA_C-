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
    
    return 0;
}

void ExpItem::Render() {
    CursorManger::GetInstance()->WriteBuffer(Info.Position, (char*)"o", 3);
}

void ExpItem::Release() {
}
