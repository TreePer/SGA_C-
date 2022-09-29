#pragma once
#include "Headers.h"

class CursorManger {
private :
	static CursorManger* Instance;
	int BufferIndex;
	HANDLE HBuffer[2];
private :
	CursorManger();
	void ClearBuffer();
	void DeleteBuffer();
	void SetColor(int _color);
public :
	~CursorManger();
	static CursorManger* GetInstance() {
		if (Instance == nullptr)
			Instance = new CursorManger;
		return Instance;
	}
	 
	void CreateBuffer(const int& _Width, const int& _Height);
	void WriteBuffer(float _x, float _y, char* _str, int _color = 15);
	void WriteBuffer(float _x, float _y, int _Value, int _color = 15);
	void WriteBuffer(float _x, float _y, string _string, int _Color = 15);
	void WriteBuffer(Vector3 _Position, char* _str, int _color = 15);
	void WriteBuffer(Vector3 _Position, int _Value, int _color = 15);
	void FlippingBuffer();
};
