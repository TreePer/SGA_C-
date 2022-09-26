#pragma once
#include "Object.h"
class Fire : public Object {

public:
	Fire();
	Fire(Transform Info) : Object(Info) {}
	virtual ~Fire();

	virtual Object* Start(string _Key) override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

	virtual Object* Clone()override { return new Fire(*this); }
};