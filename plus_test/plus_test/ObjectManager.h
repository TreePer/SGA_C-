#pragma once
#include "Headers.h"
class Object;
class ObjectManager {
private :
	static ObjectManager* Instance;
	map<string, list<Object*>> ObjectList;
	Object* pPlayer;
	ULONGLONG FireTime;
	ULONGLONG BookTime;
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
	void AddObject(Vector3 _Position, string _Key);
	void AddObject(Transform _Info, string _Key);

	Object* GetPlayer() { return pPlayer; }
	void SetPlayer(Object* _Object) { pPlayer = _Object; }

	ULONGLONG GetFireTime() { return FireTime; }
	void SetFireTime(ULONGLONG _time) { FireTime = _time; }
	ULONGLONG GetBookTime() { return BookTime; }
	void SetBookTime(ULONGLONG _time) { BookTime = _time; }
	
	~ObjectManager();
};

