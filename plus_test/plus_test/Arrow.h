#pragma once
#include "Object.h"
class Arrow : public Object {
private:
	
public:
	Arrow();
	Arrow(Transform Info) : Object(Info) {};
	virtual ~Arrow();

	virtual Object* Start(string _Key) override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
	virtual Object* Clone()override { return new Arrow(*this); }
};