#include "ObjectpoolManager.h"
#include "PrototypeManager.h"
#include "Object.h"
#include "CursorManager.h"
#include "CollisionManager.h"
#include "Book.h"
#include "CursorManager.h"

ObjectpoolManager* ObjectpoolManager::Instance = nullptr;

bool ObjectpoolManager::FindObject(string _Key) {
	auto iter = DisableList.find(_Key);

	if (iter == DisableList.end())
		return false;
	else
		return true;
}

void ObjectpoolManager::AddObject(string _Key) {
	map<string, list<Object*>>::iterator iter = DisableList.find(_Key);

	if (iter == DisableList.end()) {
		list<Object*> Temp;
		DisableList.insert(make_pair(_Key, Temp));
		iter = DisableList.find(_Key);
	}

	Object* pProtoObj = PrototypeManager::GetInstance()->FindObject(_Key);

	for (int i = 0; i < 5; ++i) {
		if (pProtoObj) {
			Object* pObject = pProtoObj->Clone();
			iter->second.push_back(pObject);
		}
		else {
			return;
		}
	}
}

void ObjectpoolManager::SwitchingObject(string _Key, Vector3 _Position) {
	map<string, list<Object*>>::iterator iter = DisableList.find(_Key);

	if (iter->second.empty())
		AddObject(_Key);


	Object* pObj = iter->second.back();
	pObj->SetPosition(_Position);

	if(_Key == "Enemy")
		pObj->SetHp(200);

	if (_Key == "Bullet")
		pObj->SetTime(GetTickCount64());

	if (_Key == "ExpItem")
		pObj->SetTarger(nullptr);
		

	EnableList[_Key].push_back(pObj);
	iter->second.pop_back();
}

void ObjectpoolManager::SwitchingObject(string _Key, Transform _Info) {
	map<string, list<Object*>>::iterator iter = DisableList.find(_Key);

	if (iter->second.empty())
		AddObject(_Key);


	Object* pObj = iter->second.back();
	pObj->SetPosition(_Info.Position);
	pObj->SetRotation(_Info.Rotation);
	if (_Key == "Bullet")
		pObj->SetTime(GetTickCount64());

	EnableList[_Key].push_back(pObj);
	iter->second.pop_back();
}

void ObjectpoolManager::CollisonObject(Object* _pObj) {
	if (_pObj->GetKey() == "Player") {
		if (!EnableList.empty()) {
			map<string, list<Object*>>::iterator iter = EnableList.find("Enemy");
			if (iter != EnableList.end()) {
				for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2) {
					if (CollisionManager::RectCollision(_pObj->GetTransform(), (*iter2)->GetTransform())) {
						_pObj->SetHp(_pObj->GetHp() - (*iter2)->GetAtk());
					}
				}
			}
		}	
	}
	else {
		if (!EnableList.empty()) {
			map<string, list<Object*>>::iterator iter = EnableList.find("Enemy");
			if (iter != EnableList.end()) {
				for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2) {
					if (_pObj->GetKey() == "Book") {
						for (int i = 0; i < 6; ++i) {
							if (CollisionManager::RectCollision(((Book*)_pObj)->GetTransform(i), (*iter2)->GetTransform())) {
								(*iter2)->SetHp((*iter2)->GetHp() - _pObj->GetAtk());
							}
						}
					}
					else {
						if (CollisionManager::RectCollision(_pObj->GetTransform(), (*iter2)->GetTransform())) {
							(*iter2)->SetHp((*iter2)->GetHp() - _pObj->GetAtk());
						}
					}
				}
			}
		}
	}
}

void ObjectpoolManager::UpdateAtk(string _Key, int _Val) {
	map<string, list<Object*>>::iterator iter = EnableList.find(_Key);
	if (iter != EnableList.end()) {
		for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2) {
			(*iter2)->SetAtk(_Val);
		}
	}
	map<string, list<Object*>>::iterator iter3 = DisableList.find(_Key);
	if (iter3 != DisableList.end()) {
		for (auto iter2 = iter3->second.begin(); iter2 != iter3->second.end(); ++iter2) {
			(*iter2)->SetAtk(_Val);
		}
	}
}

void ObjectpoolManager::Update() {
	for (auto iter = EnableList.begin(); iter != EnableList.end(); ++iter) {
		for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); ) {
			int Result = (*iter2)->Update();

			if (Result) {
				DisableList[(*iter2)->GetKey()].push_back((*iter2));
				iter2 = iter->second.erase(iter2);
			}
			else
				++iter2;
		}
	}
}

void ObjectpoolManager::Render() {
	for (auto iter = EnableList.begin(); iter != EnableList.end(); ++iter) {
		for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2) {
			(*iter2)->Render();
		}
	}	

	CursorManger::GetInstance()->WriteBuffer(10, 10, EnableList["ExpItem"].size());
	CursorManger::GetInstance()->WriteBuffer(10, 11, DisableList["ExpItem"].size());
}

ObjectpoolManager::ObjectpoolManager() {
}

ObjectpoolManager::~ObjectpoolManager() {
}