#pragma once
#include "SkillBridge.h"
class Book : public SkillBridge {
private:
	int onoff;
	int stat[8];
	float angle;
	Transform* Texture[8];
	ULONGLONG Time;
	float x[16];
	float y[16];
public:
	Book();
	virtual ~Book();

	virtual void Start() override;
	virtual int Update(Transform& _Transform)override;
	virtual void Render()override;
	virtual void Release()override;
	virtual Bridge* Clone()override { return new Book(*this); }

	int GetStat() { return onoff; }
	void SetStat(int _a) { onoff = _a; }

	Transform GetTransform(int i) { return *Texture[i]; }
};

