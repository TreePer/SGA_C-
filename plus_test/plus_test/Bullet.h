#pragma once
#include "Object.h"
class Bullet : public Object {
private :
	float Speed;	
	float x, y;
	Vector3 test;
public:
	Bullet();
	Bullet(Transform Info) : Object(Info) {}
	virtual ~Bullet();

	virtual Object* Start(string _Key) override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
	virtual Object* Clone()override { return new Bullet(*this); }

	void NewDirection();

};