#pragma once
#include "Scene.h"
class Object;
class Upgrade : public Scene {
private:
	int SP;
	int ATK;
	int DEF;
	int SPEED;
	int MAGNET;
	int select;
	Object* pPlayer;
	int width;
	char* title[4];
public :
	Upgrade();
	virtual ~Upgrade();

	virtual void Start() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
}; 