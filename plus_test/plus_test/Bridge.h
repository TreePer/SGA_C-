#pragma once
#include "Headers.h"

class Object;
class Bridge {
protected :
	Object* pObj;
	Transform Info;
	int ATK;
public :
	Bridge() : pObj(nullptr), ATK(0) {}
	virtual ~Bridge() {}

	void SetObject(Object* _Obj) { pObj = _Obj; }

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

	int GetAtk() { return ATK; }
	void SetAtk(int _Value) { ATK = _Value; }

	virtual void Start() PURE;
	virtual int Update(Transform& _Transform) PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;

	virtual Bridge* Clone()PURE;

};
