#pragma once
#include "Headers.h"

template <typename T>
class ObjectFactory {
public:
	static Object* CreateObject() {
		Object* pObject = new T;
		pObject->Start("Skill");

		return pObject;
	}

	static Object* CreateObject(Vector3 _Position) {
		Object* pObject = new T;
		pObject->Start("Skill");
		pObject->SetPosition(_Position);

		return pObject;
	}

	static Object* CreateObject(Object* _Position) {
		Object* pObject = new T;
		pObject->Start("Skill");
		pObject->SetPosition(_Position->GetPosition());

		return pObject;
	}

};