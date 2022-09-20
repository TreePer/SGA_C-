#pragma once
#include "Headers.h"

class Object {
protected :
	Transform Info;
	Object* Target;
	string Key;
	int HP;
	int ATK;
public :
	virtual Object* Start(string _Key) PURE;
	virtual int Update() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;

	virtual Object* Clone()PURE;

	Transform GetTransform() { return Info; }

	Vector3 GetPosition() { return Info.Position; }
	Vector3 GetDirection() { return Info.Direction; }
	Vector3 GetRotation() { return Info.Rotation; }
	
	void SetPosition(Vector3 _Position) { Info.Position = _Position; }
	void SetPosition(float _x, float _y) { Info.Position = Vector3(_x, _y); }

	void SetDirection(Vector3 _Direction) { Info.Direction = _Direction; }
	void SetDirection(float _x, float _y) { Info.Direction = Vector3(_x, _y); }

	void SetRotation(Vector3 _Rotation) { Info.Rotation = _Rotation; }
	void SetRotation(float _x, float _y) { Info.Rotation = Vector3(_x, _y); }

	void SetTarger(Object* _Target) { Target = _Target; }

	int GetHp() { return HP; }
	void SetHp(int _HP) { HP = _HP; }

	int GetAtk() { return ATK; }
	void SetAtk(int _Value) { ATK = _Value; }

	string GetKey() { return Key; }
	void SetKey(string _Key) { Key = _Key; }

	Object();
	Object(Transform _Info) : Info(_Info), Target(nullptr) {};
	virtual ~Object();
};

