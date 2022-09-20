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

ObjectManager::ObjectManager() : pPlayer(nullptr){
	
}

void ObjectManager::Start() {
	pPlayer = ObjectFactory<Player>::CreateObject();
	//((Player*)pPlayer)->CreateWeapon();
}

void ObjectManager::Update() {
	pPlayer->Update();

	/*
	int result = 0; v 
	for (int i = 0; i < 128; ++i) {
		result = 0;
		if (pBullet[i]) {
			result = pBullet[i]->Update();
			for (int j = 0; j < 256; ++j) {
				if(pEnemy[j] != nullptr)
					if (CollisionManager::RectCollision(pEnemy[j]->GetTransform(), pBullet[i]->GetTransform())) {
						dmg = pEnemy[j]->GetHp() - (pPlayer->GetAtk() + pBullet[i]->GetAtk());
							if (dmg > 0) {
								pEnemy[j]->SetHp(dmg);
							}
							else {
								CreateExp(pEnemy[j]);
								delete pEnemy[j];
								pEnemy[j] = nullptr;
							}
						
					}
			}
		}
		if (result) {
			if (pBullet[i]) {
				delete pBullet[i];
				pBullet[i] = nullptr;
			}
		}
	}

	if (pFire) {
		((Fire*)pFire)->GetPlayerInfo(pPlayer);
		pFire->Update();
		for (int i = 0; i < 256; ++i) {
			if (pEnemy[i] != nullptr)
				if (CollisionManager::RectCollision(pEnemy[i]->GetTransform(), pFire->GetTransform())) {
					dmg = pEnemy[i]->GetHp() - (pPlayer->GetAtk() + pFire->GetAtk());
					if (dmg > 0) {
						pEnemy[i]->SetHp(dmg);
					}
					else {
						CreateExp(pEnemy[i]);
						delete pEnemy[i];
						pEnemy[i] = nullptr;
					}
				}
		}
	}

	if (pBook) {
		pBook->SetPosition(pPlayer->GetPosition());
		pBook->Update();
		for (int j = 0; j < 6; ++j) {
			for (int i = 0; i < 256; ++i) {
				if (pEnemy[i] != nullptr)
					if (CollisionManager::RectCollision(pEnemy[i]->GetTransform(), ((Book*)pBook)->GetTransform(j))) {
						dmg = pEnemy[i]->GetHp() - (pPlayer->GetAtk() + pBook->GetAtk());
						if (dmg > 0) {
							pEnemy[i]->SetHp(dmg);
						}
						else {
							CreateExp(pEnemy[i]);
							delete pEnemy[i];
							pEnemy[i] = nullptr;
						}
					}
			}
		}
	}

	for (int i = 0; i < 128; ++i) {
		result = 0;
		if (pArrow[i]) {
			result = pArrow[i]->Update();

			for (int j = 0; j < 256; ++j) {
				if (pEnemy[j] != nullptr)
					if (CollisionManager::RectCollision(pEnemy[j]->GetTransform(), pArrow[i]->GetTransform())) {
						dmg = pEnemy[j]->GetHp() - (pPlayer->GetAtk() + pArrow[i]->GetAtk());
						if (dmg > 0) {
							pEnemy[j]->SetHp(dmg);
						}
						else {
							CreateExp(pEnemy[j]);
							delete pEnemy[j];
							pEnemy[j] = nullptr;
						}

					}
			}
		}
		if (result) {
			if (pArrow[i]) {
				delete pArrow[i];
				pArrow[i] = nullptr;
			}
		}
	}

	for (int i = 0; i < 256; ++i) {
		if (pEnemy[i]) {
			pEnemy[i]->SetTarger(pPlayer);
			pEnemy[i]->Update();
		}
	}

	for (int i = 0; i < 256; ++i) {
		if (pExp[i]) {
			pExp[i]->SetTarger(pPlayer);
			pExp[i]->Update();
			if (CollisionManager::RectCollision(pExp[i]->GetTransform(), pPlayer->GetTransform())) {
				((Player*)pPlayer)->SetExp(((Player*)pPlayer)->GetExp() + ((ExpItem*)pExp[i])->GetExp());
				((Player*)pPlayer)->PlayerLevelCheck();
				delete pExp[i];
				pExp[i] = nullptr;
			}
		}
	}
	*/

	for (auto iter = ObjectList.begin(); iter != ObjectList.end(); ++iter)
		for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
			(*iter2)->Update();

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

	ObjectpoolManager::GetInstance()->SwitchingObject(_Key);
}

void ObjectManager::AddObject(Vector3 _position, string _Key) {
	if (!ObjectpoolManager::GetInstance()->FindObject(_Key))
		ObjectpoolManager::GetInstance()->AddObject(_Key);

	ObjectpoolManager::GetInstance()->SwitchingObject(_Key, _position);
}

/*
void ObjectManager::CreateBullet(int _index) {
	for (int i = 0; i < 128; ++i) {
		if (pBullet[i] == nullptr) {
			pBullet[i] = ObjectFactory<Bullet>::CreateObject(pPlayer->GetPosition());
			break;
		}
	}
}

void ObjectManager::CreateArrow() {
	for (int i = 0; i < 128; ++i) {
		if (pArrow[i] == nullptr) {
			pArrow[i] = ObjectFactory<Arrow>::CreateObject(pPlayer);
			break;
		}
	}
}

void ObjectManager::CreateFire() {
	pFire = ObjectFactory<Fire>::CreateObject();
}

void ObjectManager::CreateBook() {
	pBook = ObjectFactory<Book>::CreateObject(pPlayer->GetPosition());
}

void ObjectManager::CreateExp(Object* _pObject) {
	for (int i = 0; i < 256; ++i) {
		if (pExp[i] == nullptr) {
			pExp[i] = ObjectFactory<ExpItem>::CreateObject(_pObject);
			break;
		}
	}
}

void ObjectManager::FireStat() {
	((Fire*)pFire)->SetStat(!(((Fire*)pFire)->GetStat()));
}

void ObjectManager::BookStat() {
	((Book*)pBook)->SetStat(!(((Book*)pBook)->GetStat()));
}
*/

ObjectManager::~ObjectManager() {
	Release();
}