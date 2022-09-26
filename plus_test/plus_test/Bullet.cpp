#include "Bullet.h"
#include "CursorManager.h"
#include "MathManager.h"

Bullet::Bullet() : Speed(0), x(0), y(0) {
}

Bullet::~Bullet() {
	Release();
}

Object* Bullet::Start(string _Key) {
	Info.Position = Vector3(0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(1.0f, 1.0f);
	NewDirection();

	Speed = 3.0f;

	ATK = 50;

	time = GetTickCount64();
	
	return this;
}

int Bullet::Update() {
	if (time + 10000 <= GetTickCount64()) {
		time = GetTickCount64();
		return 1;
	}

	if (Info.Position.x > 0 && Info.Position.x < 1) {
		Info.Position.x = 0;
		NewDirection();
	}
	if (Info.Position.x > 128 && Info.Position.x < 129) {
		Info.Position.x = 129;
		NewDirection();
	}
	if (Info.Position.y > 0 && Info.Position.y < 1) {
		Info.Position.y = 0;
		NewDirection();
	}
	if (Info.Position.y > 38 && Info.Position.y < 39) {
		Info.Position.y = 39;
		NewDirection();
	}


	test = Info.Position + Info.Direction * 5;

	if (test.x < 0.0f || test.x > 129.0f ||
		test.y < 0.0f || test.y > 39.0f) {
		test = Info.Position + Info.Direction;
		if (test.x < 0.0f || test.x > 129.0f ||
			test.y < 0.0f || test.y > 39.0f) {
			NewDirection();
		}
		else {
			Info.Position += Info.Direction;
		}
	}
	else {
		Info.Position += Info.Direction * 5;
	}

	return 0;
}


void Bullet::Render() {

	CursorManger::GetInstance()->WriteBuffer(Info.Position, (char*)"O");

}

void Bullet::Release() {
}

void Bullet::NewDirection() {
	srand(GetTickCount64());

	x = rand() % 130;
	y = rand() % 40;

	if (x > y) {
		y /= x;
		x /= x;
	}
	else {
		x /= y;
		y /= y;
	}
	int a = rand() % 4;
	if (a == 0)
		x *= -1;
	else if (a == 1)
		y *= -1;
	else if (a == 2) {
		x *= -1;
		y *= -1;
	}
	if (Info.Position.x < 1) {
		if (x > 0)
			Info.Direction = Vector3(x, y);
		else 
			Info.Direction = Vector3(x * -1, y);
	}
	else if (Info.Position.x > 128) {
		if (x < 0)
			Info.Direction = Vector3(x, y);
		else
			Info.Direction = Vector3(x * -1, y);
	}
	else if (Info.Position.y < 1) {
		if (y > 0)
			Info.Direction = Vector3(x, y);
		else
			Info.Direction = Vector3(x, y * -1);
	}
	else {
		if (y < 0)
			Info.Direction = Vector3(x, y);
		else
			Info.Direction = Vector3(x, y * -1);
	}
	
}
