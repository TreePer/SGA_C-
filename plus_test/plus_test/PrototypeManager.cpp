#include "PrototypeManager.h"
#include "Enemy.h"
#include "Player.h"
#include "ExpItem.h"
#include "Arrow.h"
#include "Book.h"
#include "Bullet.h"
#include "Fire.h"

PrototypeManager* PrototypeManager::Instance = nullptr;



void PrototypeManager::Initialize() {
    Transform Info;

	Info.Position = Vector3(0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(0.0f, 0.0f);
	Info.Direction = Vector3(0.0f, 0.0f);

	string Key = "";

	Key = "Enemy";
	ObjectList[Key] = (new Enemy(Info))->Start(Key);

	Key = "Player";
	ObjectList[Key] = (new Player(Info))->Start(Key);

	Key = "ExpItem";
	ObjectList[Key] = (new ExpItem(Info))->Start(Key);

	Key = "Arrow";
	ObjectList[Key] = (new Arrow(Info))->Start(Key);
	Key = "Book";
	ObjectList[Key] = (new Book(Info))->Start(Key);
	Key = "Bullet";
	ObjectList[Key] = (new Bullet(Info))->Start(Key);
	Key = "Fire";
	ObjectList[Key] = (new Fire(Info))->Start(Key);
}

Object* PrototypeManager::FindObject(string _Key) {
	map<string, Object*>::iterator iter = ObjectList.find(_Key);

	if (iter == ObjectList.end())
		return nullptr;
	else
		return iter->second;
}

PrototypeManager::PrototypeManager() {
}

PrototypeManager::~PrototypeManager() {
}
