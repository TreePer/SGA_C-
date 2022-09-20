#pragma once
#include "Headers.h"
class Object;
class ObjectManager {
private :
	static ObjectManager* Instance;
	map<string, list<Object*>> ObjectList;
	Object* pPlayer;

	int dmg;
private :
	ObjectManager();
public :
	static ObjectManager* GetInstance() {
		if (Instance == nullptr)
			Instance = new ObjectManager;
		return Instance;
	}

	void Start();
	void Update();
	void Render();
	void Release();

	void AddObject(string _Key);
	void AddObject(Vector3 _position, string _Key);

	void CreateBullet(int _Index);
	void CreateArrow();
	void CreateFire();
	void CreateBook();
	void CreateExp(Object* _pObject);

	Object* GetPlayer() { return pPlayer; }
	void SetPlayer(Object* _Object) { pPlayer = _Object; }
	//Object* GetFire() { if(pFire) return pFire; }
	//Object* GetBook() { if(pBook) return pBook; }


	/*
	void FireStat();
	void BookStat();

	*/

	~ObjectManager();
};

