#include "Book.h"
#include "CursorManager.h"
#include "MathManager.h"

Book::Book() : angle(0), Time(0), onoff(0) {
	for (int i = 0; i < 8; ++i)
		Texture[i] = nullptr;

	x[0] = 6;
	x[1] = 5;
	x[2] = 3;
	x[3] = 0;
	x[4] = -3;
	x[5] = -5;
	x[6] = -6;
	x[7] = -5;
	x[8] = -3;
	x[9] = 0;
	x[10] = 3;
	x[11] = 5;
	

	y[0] = 0;
	y[1] = 2;
	y[2] = 3;
	y[3] = 3;
	y[4] = 3;
	y[5] = 2;
	y[6] = 0;
	y[7] = -2;
	y[8] = -3;
	y[9] = -3;
	y[10] = -3;
	y[11] = -2;

}

Book::~Book() {
	Release();
}

void Book::Start() {
	Info.Position = Vector3(0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(2.0f, 1.0f);

	angle = 0.0f;
	ATK = 200;
	Time = GetTickCount64();

	for (int i = 0; i < 8; ++i) {
		Texture[i] = new Transform;
	}
	/*
	float radian = 0.0f;
	float radian2 = 0.0f;

	int k = 0;

	for (int i = 0; i <= 360; ++i) {
		radian = i * 3.141592 / 6;
		radian2 = i * 3.141592 / 3;
		if (k > 0) {
			int check = 1;
			for (int j = 0; j < i; ++j) {
				if ((x[j] == round(cos(radian) * 6)) && (y[j] == round(sin(radian2) * 3))) {
					check = 0;
					break;
				}
			}
			if (check) {
				x[k] = round(cos(radian) * 6);
				y[k] = round(sin(radian2) * 3);
				++k;
			}
		}
		else {
			x[k] = round(cos(radian) * 6);
			y[k] = round(sin(radian2) * 3);
			++k;
		}
	}
	*/

	for (int i = 0; i < 6; ++i) {
		stat[i] = i * 2;
	}
}

int Book::Update(Transform& _Transform) {
	if (Time + 40 < GetTickCount64()) {

		for (int i = 0; i < 6; ++i) {
			if (stat[i] + 1 < 12)
				stat[i] += 1;
			else
				stat[i] = 12 - stat[i] - 1;

			Texture[i]->Position = Info.Position + Vector3(x[stat[i]], y[stat[i]]);
		}

		Time = GetTickCount64();
	}

	return 0;
}

void Book::Render() {

	for (int i = 0; i < 6; i++) {
		CursorManger::GetInstance()->WriteBuffer(Texture[i]->Position.x, Texture[i]->Position.y, (char*)"бр", 13);
	}
}

void Book::Release() {
}