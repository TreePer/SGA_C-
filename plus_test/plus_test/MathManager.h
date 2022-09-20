#pragma once
#include "Headers.h"
class MathManager {
public :
	static float GetDistance(const Vector3& _APoint, const Vector3& _BPoint) {
		const float Width = _APoint.x - _BPoint.x;
		const float Height = _APoint.y - _BPoint.y;

		return sqrt(pow(Width, 2) + pow(Height, 2));
	}

	static Vector3 GetDirection(const Vector3& _Current, const Vector3& _Target) {
		const float Width = _Target.x - _Current.x;
		const float Height = _Target.y - _Current.y;

		const float Distance = sqrt(pow(Width, 2) + pow(Height, 2));
		

		return Vector3(Width / Distance, Height / Distance);
	}
};

