#pragma once
#include "Scene.h"
class Object;
class LevelUp : public Scene {
private :
	int select;
	int width;
	int random[4];
	string text[6][2];
	Object* pObj;
private :
public :
	LevelUp();
	virtual ~LevelUp();
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
};