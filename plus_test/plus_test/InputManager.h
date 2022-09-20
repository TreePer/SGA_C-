#pragma once
#include "Headers.h"
class InputManager {
private :
	static InputManager* Instance;
	DWORD dwKey;
private :
	InputManager();
public :
	~InputManager();

	static InputManager* GetInstance() {
		if (Instance == nullptr)
			Instance = new InputManager;
		return Instance;
	}

	void CheckKey();
	DWORD GetKey() {
		return dwKey;
	}

};