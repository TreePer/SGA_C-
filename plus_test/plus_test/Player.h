#pragma once
#include "Object.h"

class Player : public Object {
private :
	int LV;
	int EXP;
	int MAXEXP;
	int DEF;
	int SPEED;
	int MAGNET;

	ULONGLONG Time;
	ULONGLONG FireTime;
	ULONGLONG BookTime;

	Object* pFire;
public :
	virtual Object* Start(string _Key) override;
	virtual int Update() override;
	virtual void Render() override;
	virtual void Release() override;

	virtual Object* Clone()override { return new Player(*this); }

	void CreateWeapon();

	void SetDef(int _Value);
	void SetSpeed(int _Value);
	void SetMagnet(int _Value);
	void SetExp(int _Value);

	int GetLv() { return LV; }
	int GetExp() { return EXP; }
	int GetMaxExp() { return MAXEXP; }
	int GetDef() { return DEF; }
	int GetSpeed() { return SPEED; }
	int GetMagnet() { return MAGNET; }
	
	void PlayerLevelCheck();
		

	Player();
	Player(Transform _Info) : Object(_Info) {};
	~Player();
};

