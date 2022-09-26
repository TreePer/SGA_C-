#pragma once
#include "Headers.h"
class CollisionManager {
public :
	static bool RectCollision(Transform _Current, Transform _Target) {
		Vector3 CurrentEndPoint = _Current.Position + _Current.Scale;
		Vector3 TargetEndPoint = _Target.Position + _Target.Scale;

		if (_Current.Position.x < TargetEndPoint.x &&
			_Target.Position.x < CurrentEndPoint.x &&
			(int)_Target.Position.y == (int)_Current.Position.y) {
			return true;
		}
		return false;
	}

	static bool ExpCollision(Transform _Current, Transform _Target, int _Magnet) {
		Vector3 CurrentEndPoint = _Current.Position + _Current.Scale + Vector3(_Magnet * 2, _Magnet);
		Vector3 TargetEndPoint = _Target.Position + _Target.Scale;

		if (_Current.Position.x < TargetEndPoint.x &&
			_Target.Position.x < CurrentEndPoint.x &&
			(int)CurrentEndPoint.y > (int)_Target.Position.y &&
			(int)_Current.Position.y < (int)TargetEndPoint.y
			) {
			return true;
		}
		return false;
	}
};

