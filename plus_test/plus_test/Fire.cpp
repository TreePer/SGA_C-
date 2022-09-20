#include "Fire.h"
#include "CursorManager.h"
#include "MathManager.h"

Fire::Fire() : stat(0) {
}

Fire::~Fire() {
	Release();
}


void Fire::Start() {
	Info.Position = Vector3(0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(5.0f, 1.0f);

	ATK = 20;
}

int Fire::Update(Transform& _Transform) {
	if (Info.Rotation.x == -1) {
		Info.Position.x -= 7;
	}
	return 0;
}

void Fire::Render() {
	if (Info.Rotation.x == 1) {
		CursorManger::GetInstance()->WriteBuffer(Info.Position.x, Info.Position.y, (char*)"ooOO0", 12);
	}
	else if (Info.Rotation.x == -1) {
		CursorManger::GetInstance()->WriteBuffer(Info.Position.x, Info.Position.y, (char*)"0OOoo", 12);
	}
}

void Fire::Release() {
}

void Fire::GetPlayerInfo(Object* _pPlayer) {
	Info.Rotation = _pPlayer->GetRotation();
	Info.Position = _pPlayer->GetPosition() + Vector3(2, 0);
}
