#pragma once
#include "SkillBridge.h"
class Bullet : public SkillBridge {
private :
	float Speed;	
	ULONGLONG time;
	float x, y;
	Vector3 test;
public:
	Bullet();
	virtual ~Bullet();

	virtual void Start() override;
	virtual int Update(Transform& _Transform)override;
	virtual void Render()override;
	virtual void Release()override;
	virtual Bridge* Clone()override { return new Bullet(*this); }

	void NewDirection();

};