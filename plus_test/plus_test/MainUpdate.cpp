#include "MainUpdate.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "CursorManager.h"
#include "PrototypeManager.h"

void MainUpdate::Start() {
	CursorManger::GetInstance()->CreateBuffer(130.0f, 40.0f);
	PrototypeManager::GetInstance()->Initialize();
	SceneManager::GetInstance()->SetScene(SCENEID::LOGO);
}

void MainUpdate::Update() {
	CursorManger::GetInstance()->FlippingBuffer();
	InputManager::GetInstance()->CheckKey();
	SceneManager::GetInstance()->Update();
	
}

void MainUpdate::Render() {
	SceneManager::GetInstance()->Render();
}

void MainUpdate::Release() {
	
}

MainUpdate::MainUpdate() {
}
MainUpdate::~MainUpdate() {
	Release();
}