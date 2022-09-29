#include "ObjectManager.h"
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include "CollisionManager.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "Fire.h"
#include "Book.h"
#include "Arrow.h"
#include "ExpItem.h"
#include "ObjectFactory.h"
#include "ObjectpoolManager.h"

ObjectManager* ObjectManager::Instance = nullptr;

ObjectManager::ObjectManager() : pPlayer(nullptr), FireTime(0), BookTime(0){
	
}

void ObjectManager::Start() {
	FireTime = GetTickCount64();
	BookTime = GetTickCount64();
}

void ObjectManager::Update() {

	for (auto iter = ObjectList.begin(); iter != ObjectList.end(); ++iter)
		for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
			(*iter2)->Update();

	pPlayer->Update();
	ObjectpoolManager::GetInstance()->Update();
}

void ObjectManager::Render() {

	for (auto iter = ObjectList.begin(); iter != ObjectList.end(); ++iter)
		for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
			(*iter2)->Render();
	
	pPlayer->Render();
	ObjectpoolManager::GetInstance()->Render();
}

void ObjectManager::Release() {
	
	delete pPlayer;
	pPlayer = nullptr;
}

void ObjectManager::AddObject(string _Key) {
	if (!ObjectpoolManager::GetInstance()->FindObject(_Key))
		ObjectpoolManager::GetInstance()->AddObject(_Key);

	ObjectpoolManager::GetInstance()->SwitchingObject(_Key, Vector3());
}

void ObjectManager::AddObject(Vector3 _Position, string _Key) {
	if (!ObjectpoolManager::GetInstance()->FindObject(_Key))
		ObjectpoolManager::GetInstance()->AddObject(_Key);

	ObjectpoolManager::GetInstance()->SwitchingObject(_Key, _Position);
}

void ObjectManager::AddObject(Transform _Info, string _Key) {
	if (!ObjectpoolManager::GetInstance()->FindObject(_Key))
		ObjectpoolManager::GetInstance()->AddObject(_Key);

	ObjectpoolManager::GetInstance()->SwitchingObject(_Key, _Info);
}

void ObjectManager::CollisionCheck(Object* _pObj) {
	ObjectpoolManager::GetInstance()->CollisonObject(_pObj);
}

void ObjectManager::UpdateObjectAtk(string _Key, int _Val) {
	ObjectpoolManager::GetInstance()->UpdateAtk(_Key, _Val);

}

ObjectManager::~ObjectManager() {
	Release();
}