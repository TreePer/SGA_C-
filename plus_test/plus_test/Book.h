#pragma once
#include "Object.h"
class Book : public Object {
private:
	int onoff;
	int stat[8];
	float angle;
	ULONGLONG Time1;
	Transform* Texture[8];
	float x[16];
	float y[16];
public:
	Book();
	Book(Transform Info) : Object(Info) {}
	virtual ~Book();

	virtual Object* Start(string _Key) override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
	virtual Object* Clone()override { return new Book(*this); }

	Transform GetTransform(int i) { return *Texture[i]; }
};

