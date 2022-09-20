#include "MainUpdate.h"

int main(void) {	
	ULONGLONG Time = GetTickCount64();

	system("mode con cols=130 lines=40");

	MainUpdate main;
	main.Start();
	
	while (true) {
		if (Time + 100 <= GetTickCount64()) {
			Time = GetTickCount64();
			system("cls");			

			main.Update();
			main.Render();
			
		}
	}
	
	return 0;
}