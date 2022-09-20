#pragma once
#include "SkillBridge.h"
class Fire : public SkillBridge {
private:
	int stat;
public:
	Fire();
	virtual ~Fire();

	virtual void Start() override;
	virtual int Update(Transform& _Transform)override;
	virtual void Render()override;
	virtual void Release()override;

	int GetStat() { return stat; }
	void SetStat(int _a) { stat = _a; }

	void GetPlayerInfo(Object* _pPlayer);

	virtual Bridge* Clone()override { return new Fire(*this); }
};