#pragma once
#include "Headers.h"

class Object;
class PrototypeManager {
private :
	static PrototypeManager* Instance;
	map<string, Object*> ObjectList;
private :
	PrototypeManager();
public :
	static PrototypeManager* GetInstance() {
		if (Instance == nullptr)
			Instance = new PrototypeManager;
		return Instance;
	}
	void Initialize();
	Object* FindObject(string _Key);
	~PrototypeManager();
};

