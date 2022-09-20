#pragma once
#include "Scene.h"

class Stage : public Scene {
private :
	ULONGLONG EnemyTime;
public :
	Stage();
	virtual ~Stage();
	virtual void Start() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

