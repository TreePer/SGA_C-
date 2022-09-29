#pragma once
#include "Scene.h"
class GameOver : public Scene {
public:
	GameOver();
	virtual ~GameOver();
	virtual void Start() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

