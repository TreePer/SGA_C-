#pragma once
#include "Bridge.h"

class SkillBridge : public Bridge {
public:
	virtual void Start()PURE;
	virtual int  Update(Transform& _Transform)PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
public:
	SkillBridge() {}
	virtual ~SkillBridge() {}
};