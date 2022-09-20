#pragma once

struct Vector3 {
	float x, y, z;

	Vector3() : x(0), y(0), z(0) {};
	Vector3(float _x, float _y) : x(_x), y(_y), z(0) {};
	Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {};

	Vector3 operator+ (Vector3 _v1) {
		return Vector3(x + _v1.x, y + _v1.y, z + _v1.z);
	}

	Vector3 operator- (Vector3 _v1) {
		return Vector3(x - _v1.x, y - _v1.y, z - _v1.z);
	}

	Vector3 operator+= (Vector3 _v1) {
		return Vector3(x += _v1.x, y += _v1.y, z += _v1.z);
	}

	Vector3 operator* (float _fNum) {
		return Vector3(x * _fNum, y * _fNum, z * _fNum);
	}
};

struct Transform {
	Vector3 Position;
	Vector3 Rotation;
	Vector3 Scale;
	Vector3 Direction;
};
