#pragma once
#include "Scene.h"
class Menu : public Scene{
private :
	char* mainlogo[32];
	int select;
	int width;
public :
	Menu();
	~Menu();
	virtual void Start() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

