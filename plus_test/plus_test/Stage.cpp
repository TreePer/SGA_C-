#include "Stage.h"
#include "ObjectManager.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "CursorManager.h"
#include "PrototypeManager.h"
#include "Player.h"
#include "Enemy.h"

Stage::Stage() : EnemyTime(0) {
	
}

Stage::~Stage() {
	Release();
}

void Stage::Start() {
	EnemyTime = GetTickCount64();
	Object* pObj = PrototypeManager::GetInstance()->FindObject("Player")->Clone();

	if (pObj != nullptr)
		ObjectManager::GetInstance()->SetPlayer(pObj);
}

void Stage::Update() {
	if (EnemyTime + 300 < GetTickCount64()) {
		
		srand(GetTickCount64() * GetTickCount64() / 2 * 12314);
		float x = rand() % 130;
		float y = rand() % 40;
		ObjectManager::GetInstance()->AddObject(Vector3(x, y), "Enemy");

		EnemyTime = GetTickCount64();
	}
	ObjectManager::GetInstance()->Update();
	DWORD dwKey = InputManager::GetInstance()->GetKey();
}

void Stage::Render() {
	
	ObjectManager::GetInstance()->Render();
}

void Stage::Release() {
}
