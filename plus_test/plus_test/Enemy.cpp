#include "Enemy.h"
#include "ObjectManager.h"
#include "MathManager.h"
#include "CursorManager.h"
Enemy::Enemy() {
}

Enemy::~Enemy() {
}

Object* Enemy::Start(string _Key) {
	Key = "Enemy";
	Info.Position = Vector3(0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(1.0f, 1.0f);
	Target = nullptr;
	HP = 200;
	ATK = 5;

	return this;
}

int Enemy::Update() {
	Target = ObjectManager::GetInstance()->GetPlayer();
	Info.Direction = MathManager::GetDirection(Info.Position, Target->GetPosition());
	Info.Position += Info.Direction * 0.3;

	if (HP < 1) {
		ObjectManager::GetInstance()->AddObject(Info.Position, "ExpItem");
		return 1;
	}

	return 0;
}

void Enemy::Render() {
	CursorManger::GetInstance()->WriteBuffer(Info.Position, (char*)"C", 9);
}

void Enemy::Release() {
	delete Target;
	Target = nullptr;
}