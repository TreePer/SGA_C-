#pragma once
#include "Headers.h"

class Object;
class ObjectpoolManager {
private :
	static ObjectpoolManager* Instance;
	map<string, list<Object*>> EnableList;
	map<string, list<Object*>> DisableList;
private :
	ObjectpoolManager();
public :
	static ObjectpoolManager* GetInstance() {
		if (Instance == nullptr)
			Instance = new ObjectpoolManager;
		return Instance;
	}

	bool FindObject(string _Key);
	void AddObject(string _Key);
	void SwitchingObject(string _Key, Vector3 _Position = Vector3());
	void SwitchingObject(string _Key, Transform _Info = Transform());
	void Update();
	void Render();

	~ObjectpoolManager();

};

