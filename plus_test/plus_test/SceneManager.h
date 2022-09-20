#pragma once
#include "Headers.h"

class Scene;
class SceneManager {
private :
	static SceneManager* Instance;
	Scene* SceneState;
private :
	SceneManager();

public :
	~SceneManager();

	static SceneManager* GetInstance() {
		if (Instance == nullptr)
			Instance = new SceneManager;
		return Instance;
	}

	void SetScene(SCENEID _state);
	void Update();
	void Render();
	void Release();
};

