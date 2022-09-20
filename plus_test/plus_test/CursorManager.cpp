#include "CursorManager.h"

CursorManger* CursorManger::Instance = nullptr;
CursorManger::CursorManger() : BufferIndex(0) {
}

CursorManger::~CursorManger() {
	DeleteBuffer();
}

void CursorManger::CreateBuffer(const int& _Width, const int& _Height) {
	CONSOLE_CURSOR_INFO CursorInfo;

	CursorInfo.bVisible = FALSE;
	CursorInfo.dwSize = 1;

	COORD Size = { (SHORT)(_Width - 1), (SHORT)(_Height - 1) };

	SMALL_RECT Rect = { 0, 0, (SHORT)(_Width), (SHORT)(_Height) };

	HBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(HBuffer[0], Size);
	SetConsoleWindowInfo(HBuffer[0], TRUE, &Rect);
	SetConsoleCursorInfo(HBuffer[0], &CursorInfo);

	HBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(HBuffer[1], Size);
	SetConsoleWindowInfo(HBuffer[1], TRUE, &Rect);
	SetConsoleCursorInfo(HBuffer[1], &CursorInfo);
}

void CursorManger::WriteBuffer(float _x, float _y, char* _str, int _color) {
	COORD pos = { (SHORT)_x, (SHORT)_y };
	DWORD dw = 0;

	SetConsoleCursorPosition(HBuffer[BufferIndex], pos);
	SetColor(_color);
	WriteFile(HBuffer[BufferIndex], _str, (DWORD)strlen(_str), &dw, NULL);
}

void CursorManger::WriteBuffer(float _x, float _y, int _Value, int _color) {

	COORD pos = { (SHORT)_x, (SHORT)_y };
	DWORD dw = 0;

	SetConsoleCursorPosition(HBuffer[BufferIndex], pos);
	SetColor(_color);

	char* _str = new char(sizeof(int));

	_itoa(_Value, _str, 10);

	WriteFile(HBuffer[BufferIndex], _str, (DWORD)strlen(_str), &dw, NULL);
}

void CursorManger::WriteBuffer(Vector3 _Position, char* _str, int _color) {
	COORD pos = { (SHORT)_Position.x, (SHORT)_Position.y };
	DWORD dw = 0;

	SetConsoleCursorPosition(HBuffer[BufferIndex], pos);
	SetColor(_color);
	WriteFile(HBuffer[BufferIndex], _str, (DWORD)strlen(_str), &dw, NULL);
}

void CursorManger::WriteBuffer(Vector3 _Position, int _Value, int _color) {
	COORD pos = { (SHORT)_Position.x, (SHORT)_Position.y };
	DWORD dw = 0;

	SetConsoleCursorPosition(HBuffer[BufferIndex], pos);
	SetColor(_color);

	char* _str = new char(sizeof(int));

	_itoa(_Value, _str, 10);

	WriteFile(HBuffer[BufferIndex], _str, (DWORD)strlen(_str), &dw, NULL);
}

void CursorManger::FlippingBuffer() {
	SetConsoleActiveScreenBuffer(HBuffer[BufferIndex]);
	BufferIndex = !BufferIndex;

	ClearBuffer();
}

void CursorManger::ClearBuffer() {
	COORD Cod = { 0, 0 };
	DWORD dw = 0;
	FillConsoleOutputCharacter(HBuffer[BufferIndex], ' ', 150 * 40, Cod, &dw);
}

void CursorManger::DeleteBuffer() {
	CloseHandle(HBuffer[0]);
	CloseHandle(HBuffer[1]);
}

void CursorManger::SetColor(int _color) {
	SetConsoleTextAttribute(HBuffer[BufferIndex], _color);
}
