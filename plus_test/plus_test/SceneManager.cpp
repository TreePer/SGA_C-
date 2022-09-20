#include "SceneManager.h"
#include "Logo.h"
#include "Menu.h"
#include "Stage.h"
#include "Upgrade.h"

SceneManager* SceneManager::Instance = nullptr;

SceneManager::SceneManager() : SceneState(nullptr) {
}

SceneManager::~SceneManager() {
	Release();
}

void SceneManager::SetScene(SCENEID _state) {
	if (SceneState != nullptr) {
		delete SceneState;
		SceneState = nullptr;
	}

	switch (_state) {
	case SCENEID::LOGO :
		SceneState = new Logo;
		break;

	case SCENEID::MENU :
		SceneState = new Menu;
		break;

	case SCENEID::STAGE :
		SceneState = new Stage;
		break;

	case SCENEID::EXIT :
		cout << "EXIT" << endl;
		exit(NULL);
		break;
	case SCENEID::UPGRADE :
		SceneState = new Upgrade;
		break;
	}

	SceneState->Start();
}

void SceneManager::Update() {
	SceneState->Update();
}

void SceneManager::Render() {
	SceneState->Render();
}

void SceneManager::Release() {
	delete SceneState;
	SceneState = nullptr;
}
