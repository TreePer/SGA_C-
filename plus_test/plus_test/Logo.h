#pragma once
#include "Scene.h"

class Logo : public Scene{
private :
	ULONGLONG time;
	char* mainlogo[32];
	int width;
public :
	Logo();
	virtual ~Logo();
	virtual void Start() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

