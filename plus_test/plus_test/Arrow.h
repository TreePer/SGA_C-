#pragma once
#include "SkillBridge.h"
class Arrow : public SkillBridge {
private:
	
public:
	Arrow();
	virtual ~Arrow();

	virtual void Start() override;
	virtual int Update(Transform& _Transform)override;
	virtual void Render()override;
	virtual void Release()override;
	virtual Bridge* Clone()override { return new Arrow(*this); }
};