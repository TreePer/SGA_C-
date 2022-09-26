#include "Fire.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "Object.h"
#include "ObjectManager.h"

Fire::Fire() {
}

Fire::~Fire() {
	Release();
}


Object* Fire::Start(string _Key) {
	Info.Position = Vector3(0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(5.0f, 1.0f);

	ATK = 20;

	return this;
}

int Fire::Update() {
	Info.Position = ObjectManager::GetInstance()->GetPlayer()->GetPosition();
	Info.Rotation = ObjectManager::GetInstance()->GetPlayer()->GetRotation();

	Info.Position.x += 1;

	if (Info.Rotation.x == -1) {
		Info.Position.x -= 6;
	}

	if (ObjectManager::GetInstance()->GetFireTime() + 5000 < GetTickCount64()) {
		ObjectManager::GetInstance()->SetFireTime(GetTickCount64());
		return 1;
	}	

	ObjectManager::GetInstance()->CollisionCheck(this);
	

	return 0;
}

void Fire::Render() {
	if (Info.Rotation.x == 1) {
		if(Info.Position.x < 129)
			CursorManger::GetInstance()->WriteBuffer(Info.Position.x, Info.Position.y, (char*)"o", 12);
		if (Info.Position.x + 1 < 129)
			CursorManger::GetInstance()->WriteBuffer(Info.Position.x + 1, Info.Position.y, (char*)"o", 12);
		if (Info.Position.x + 2 < 129)
			CursorManger::GetInstance()->WriteBuffer(Info.Position.x + 2, Info.Position.y, (char*)"O", 12);
		if (Info.Position.x + 3 < 129)
			CursorManger::GetInstance()->WriteBuffer(Info.Position.x + 3, Info.Position.y, (char*)"O", 12);
		if (Info.Position.x + 4 < 129)
			CursorManger::GetInstance()->WriteBuffer(Info.Position.x + 4, Info.Position.y, (char*)"0", 12);
	}
	else if (Info.Rotation.x == -1) {
		if (Info.Position.x > 0)
			CursorManger::GetInstance()->WriteBuffer(Info.Position.x, Info.Position.y, (char*)"0", 12);
		if (Info.Position.x + 1 > 0)
			CursorManger::GetInstance()->WriteBuffer(Info.Position.x + 1, Info.Position.y, (char*)"O", 12);
		if (Info.Position.x + 2 > 0)
			CursorManger::GetInstance()->WriteBuffer(Info.Position.x + 2, Info.Position.y, (char*)"O", 12);
		if (Info.Position.x + 3 > 0)
			CursorManger::GetInstance()->WriteBuffer(Info.Position.x + 3, Info.Position.y, (char*)"o", 12);
		if (Info.Position.x + 4 > 0)
			CursorManger::GetInstance()->WriteBuffer(Info.Position.x + 4, Info.Position.y, (char*)"o", 12);
	}
}

void Fire::Release() {
}