#include "Arrow.h"
#include "CursorManager.h"
Arrow::Arrow() {
}

Arrow::~Arrow() {
    Release();
}

void Arrow::Start() {
    Info.Position = Vector3(0.0f, 0.0f);
    Info.Rotation = Vector3(0.0f, 0.0f);
    Info.Scale = Vector3(2.0f, 1.0f);
    ATK = 200;
}

int Arrow::Update(Transform& _Transform) {
    if (Info.Rotation.y == 0.0f && Info.Rotation.x == 1.0f) {
        if (Info.Position.x < 128)
            Info.Position.x += 2;
        else
            return 1;
    }
    else if (Info.Rotation.y == 0.0f && Info.Rotation.x == -1.0f) {
        if (Info.Position.x > 1)
            Info.Position.x -= 2;
        else
            return 1;
    }
    else if (Info.Rotation.y == 1.0f) {
        if (Info.Position.y < 39)
            Info.Position.y++;
        else
            return 1;
    }
    else if (Info.Rotation.y == -1.0f) {
        if (Info.Position.y > 1)
            Info.Position.y--;
        else
            return 1;
    }
    return 0;
}

void Arrow::Render() {
    if (Info.Rotation.y == 0.0f && Info.Rotation.x == 1.0f) {
        CursorManger::GetInstance()->WriteBuffer(Info.Position, (char*)"กๆ", 6);
    }
    else if (Info.Rotation.y == 0.0f && Info.Rotation.x == -1.0f) {
        CursorManger::GetInstance()->WriteBuffer(Info.Position, (char*)"ก็", 6);
    }
    else if (Info.Rotation.y == 1.0f) {
        CursorManger::GetInstance()->WriteBuffer(Info.Position, (char*)"ก้", 6);
    }
    else if (Info.Rotation.y == -1.0f) {
        CursorManger::GetInstance()->WriteBuffer(Info.Position, (char*)"ก่", 6);
    }
}

void Arrow::Release() {
}
