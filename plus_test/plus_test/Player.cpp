#include "Player.h"
#include "InputManager.h"
#include "ObjectManager.h"
#include "CursorManager.h"
#include "ObjectpoolManager.h"
#include "SceneManager.h"

Object* Player::Start(string _Key) {
	LV = 1;
	EXP = 0;
	MAXEXP = LV * 100;
	ATK = 1;
	DEF = 1;
	SPEED = 1;
	MAGNET = 0;
	HP = 100;
	Key = "Player";

	Time = GetTickCount64();
	FireTime = GetTickCount64();
	BookTime = GetTickCount64();
	
	Info.Position = Vector3(74.0f, 20.0f);
	Info.Rotation = Vector3(1.0f, 0.0f);
	Info.Scale = Vector3(1.0f, 1.0f);
	Target = nullptr;

	return this;
}

int Player::Update() {
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_UP) {
		if (Info.Position.y > 0 + (SPEED / 2))
			Info.Position.y -= 1 + (SPEED / 2);
		Info.Rotation.y = -1;
	}

	if (dwKey & KEY_DOWN) {
		if (Info.Position.y < 39 - (SPEED / 2))
			Info.Position.y += 1 + (SPEED / 2);
		Info.Rotation.y = 1;
	}
		

	if (dwKey & KEY_LEFT) {
		if (Info.Position.x > 0 + SPEED)
			Info.Position.x -= 1 + SPEED;
		Info.Rotation.x = -1;
		Info.Rotation.y = 0;
	}
		

	if (dwKey & KEY_RIGHT) {
		if (Info.Position.x < 128 - SPEED)
			Info.Position.x += 1 + SPEED;
		Info.Rotation.x = 1;
		Info.Rotation.y = 0;
	}

	
	if (ObjectManager::GetInstance()->GetFireTime() + 5100 < GetTickCount64()) {
		ObjectManager::GetInstance()->AddObject(Info, "Fire");
		ObjectManager::GetInstance()->SetFireTime(GetTickCount64());
	}

	if (ObjectManager::GetInstance()->GetBookTime() + 3600 < GetTickCount64()) {
		ObjectManager::GetInstance()->AddObject(Info, "Book");
		ObjectManager::GetInstance()->SetBookTime(GetTickCount64());
	}
	

	if (Time + 500 < GetTickCount64()) {
		ObjectManager::GetInstance()->AddObject(Info, "Arrow");
		ObjectManager::GetInstance()->AddObject(Info, "Bullet");
		Time = GetTickCount64();
	}

	ObjectManager::GetInstance()->CollisionCheck(this);

	if (HP < 1)
		SceneManager::GetInstance()->SetScene(SCENEID::GameOver);

	if (PlayerLevelCheck()) {
		SceneManager::GetInstance()->SetScene(SCENEID::LevelUp);
	}

	return 0;
}

void Player::Render() {
	if(EXP > 0)
		percent = EXP * 100 / MAXEXP;

	for (int i = 0; i < percent; ++i) {
		CursorManger::GetInstance()->WriteBuffer(i, 0, (char*)"|", 3);
	}
	for (int i = percent; i < 130; ++i) {
		CursorManger::GetInstance()->WriteBuffer(i, 0, (char*)"|", 8);
	}
	percent = 0;
	CursorManger::GetInstance()->WriteBuffer(Info.Position, (char*)"P"); 
	char buffer[32] = " ";
	sprintf(buffer, "ATK : %d", ATK);
	CursorManger::GetInstance()->WriteBuffer(1.0f, 1.0f, buffer);
	sprintf(buffer, "DEF : %d", DEF);
	CursorManger::GetInstance()->WriteBuffer(1.0f, 2.0f, buffer);
	sprintf(buffer, "SPEED : %d", SPEED);
	CursorManger::GetInstance()->WriteBuffer(1.0f, 3.0f, buffer);
	sprintf(buffer, "MAGNET : %d", MAGNET);
	CursorManger::GetInstance()->WriteBuffer(1.0f, 4.0f, buffer);
	sprintf(buffer, "EXP : %d", EXP);
	CursorManger::GetInstance()->WriteBuffer(1.0f, 5.0f, buffer);
	sprintf(buffer, "LV : %d", LV);
	CursorManger::GetInstance()->WriteBuffer(1.0f, 6.0f, buffer);
	sprintf(buffer, "HP : %d", HP);
	CursorManger::GetInstance()->WriteBuffer(1.0f, 7.0f, buffer);
}

void Player::Release() {
}
void Player::SetDef(int _Value) { DEF = _Value; }
void Player::SetSpeed(int _Value) { SPEED = _Value; }
void Player::SetMagnet(int _Value) { MAGNET = _Value; }

void Player::SetExp(int _Value) { EXP = EXP + _Value; }



bool Player::PlayerLevelCheck() {
	if (MAXEXP <= EXP) {
		EXP -= MAXEXP;
		++LV;
		MAXEXP = LV * 100;

		return true;
	}

	return false;
}

Player::Player() : FireTime(GetTickCount64()), BookTime(GetTickCount64()), Time(GetTickCount64()) {
}

Player::~Player() {
}
