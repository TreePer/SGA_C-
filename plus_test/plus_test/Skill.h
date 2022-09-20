#pragma once
#include "Object.h"

class Bridge;
class Skill : public Object {
private :
	Bridge* pBridge;
	static Bridge* BridgeList[SKILL_MAX];

	ULONGLONG ArrowTime;
	ULONGLONG BookTime;
	ULONGLONG BulletTime;
	ULONGLONG FireTime;
public :
	virtual Object* Start(string _Key) override;
	virtual int Update() override;
	virtual void Render() override;
	virtual void Release() override;

	virtual Object* Clone()override { return new Skill(*this); }

	void SetBridge(Bridge* _Bridge) {pBridge = _Bridge;}

	Skill();
	Skill(Transform _Info) : Object(_Info) {};
	virtual ~Skill();
};

