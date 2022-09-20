#include "Menu.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "CursorManager.h"
#include "ObjectManager.h"

Menu::Menu() : select(0), width(0) {
	mainlogo[0] = (char*)"@@@@@@@@  @@@@@@@@  @@@@@@@@  @@@@@@@@@  @@@@@@@@  @@@@@@@@  @@@@@@@@@@@  @@@@@@@@@@@  @@@@@@@@  @@@@@@@@";
	mainlogo[1] = (char*)"@@!  @@@  @@!  @@@  @@!  @@@  !@@        @@!  @@@  @@!  @@@  @@! @@! @@!  @@! @@! @@!  @@!       @@!  @@@";
	mainlogo[2] = (char*)"!@!  @!@  !@!  @!@  !@!  @!@  !@!        !@!  @!@  !@!  @!@  !@! !@! !@!  !@! !@! !@!  !@!       !@!  @!@";
	mainlogo[3] = (char*)"@!@@!@!   @!@!!@!   @!@  !@!  !@! @!@!@  @!@!!@!   @!@!@!@!  @!! !!@ @!@  @!! !!@ @!@  @!!!:!    @!@!!@!";
	mainlogo[4] = (char*)"!!@!!!    !!@!@!    !@!  !!!  !!! !!@!!  !!@!@!    !!!@!!!!  !@!   ! !@!  !@!   ! !@!  !!!!!:    !!@!@!";
	mainlogo[5] = (char*)"!!:       !!: :!!   !!:  !!!  :!!   !!:  !!: :!!   !!:  !!!  !!:     !!:  !!:     !!:  !!:       !!: :!!";
	mainlogo[6] = (char*)":!:       :!:  !:!  :!:  !:!  :!:   !::  :!:  !:!  :!:  !:!  :!:     :!:  :!:     :!:  :!:       :!:  !:!";
	mainlogo[7] = (char*)" ::       ::   :::  ::::: ::   ::: ::::  ::   :::  ::   :::  :::     ::   :::     ::    :: ::::  ::   :::";
	mainlogo[8] = (char*)" :         :   : :   : :  :    :: :: :    :   : :   :   : :   :      :     :      :    : :: ::    :   : :";
	mainlogo[9] = (char*)" ";
	mainlogo[10] = (char*)" ";
	mainlogo[11] = (char*)" @@@@@@   @@@  @@@  @@@@@@@   @@@  @@@  @@@  @@@  @@@   @@@@@@   @@@@@@@";
	mainlogo[12] = (char*)"@@@@@@@   @@@  @@@  @@@@@@@@  @@@  @@@  @@@  @@@  @@@  @@@@@@@@  @@@@@@@@";
	mainlogo[13] = (char*)"!@@       @@!  @@@  @@!  @@@  @@!  @@@  @@!  @@!  @@@  @@!  @@@  @@!  @@@";
	mainlogo[14] = (char*)"!@!       !@!  @!@  !@!  @!@  !@!  @!@  !@!  !@!  @!@  !@!  @!@  !@!  @!@";
	mainlogo[15] = (char*)"!!@@!!    @!@  !@!  @!@!!@!   @!@  !@!  !!@  @!@  !@!  @!@  !@!  @!@!!@!";
	mainlogo[16] = (char*)" !!@!!!   !@!  !!!  !!@!@!    !@!  !!!  !!!  !@!  !!!  !@!  !!!  !!@!@!";
	mainlogo[17] = (char*)"     !:!  !!:  !!!  !!: :!!   :!:  !!:  !!:  :!:  !!:  !!:  !!!  !!: :!!";
	mainlogo[18] = (char*)"    !:!   :!:  !:!  :!:  !:!   ::!!:!   :!:   ::!!:!   :!:  !:!  :!:  !:!";
	mainlogo[19] = (char*)":::: ::   ::::: ::  ::   :::    ::::     ::    ::::    ::::: ::  ::   :::";
	mainlogo[20] = (char*)":: : :     : :  :    :   : :     :      :       :       : :  :    :   : :";
}

Menu::~Menu() {
	Release();
}

void Menu::Start() {
}

void Menu::Update() {
	DWORD dwKey = InputManager::GetInstance()->GetKey();
	if (dwKey & KEY_ENTER)
		switch (select) {
		case 0:
			SceneManager::GetInstance()->SetScene(SCENEID::STAGE);
			break;

		case 1:
			SceneManager::GetInstance()->SetScene(SCENEID::UPGRADE);
			break;

		case 2:
			SceneManager::GetInstance()->SetScene(SCENEID::STAGE);
			break;

		case 3:
			SceneManager::GetInstance()->SetScene(SCENEID::EXIT);
			break;
		}
	if (dwKey & KEY_UP)
		if (select > 0)
			select--;
	if (dwKey & KEY_DOWN)
		if (select < 3)
			select++;

}

void Menu::Render() {

	width = 65 - strlen(mainlogo[2]) / 2;

	for (int i = 0; i < 10; ++i) {
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)2 + i, mainlogo[i], 4);
	}

	width = 65 - strlen(mainlogo[13]) / 2;

	for (int i = 10; i < 21; ++i) {
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)2 + i, mainlogo[i], 4);
	}

	width = 65 - (strlen(" ---------------------------------------------------------- ") / 2);
	CursorManger::GetInstance()->WriteBuffer((float)width, (float) 26, (char*)" ---------------------------------------------------------- " , 4);
	CursorManger::GetInstance()->WriteBuffer((float)width, (float) 27, (char*)"|                                                           |", 4);
	CursorManger::GetInstance()->WriteBuffer((float)width, (float) 28, (char*)"|                                                           |", 4);
	CursorManger::GetInstance()->WriteBuffer((float)width, (float) 29, (char*)"|                                                           |", 4);
	CursorManger::GetInstance()->WriteBuffer((float)width, (float) 30, (char*)"|                                                           |", 4);
	CursorManger::GetInstance()->WriteBuffer((float)width, (float) 31, (char*)"|                                                           |", 4);
	CursorManger::GetInstance()->WriteBuffer((float)width, (float) 32, (char*)"|                                                           |", 4);
	CursorManger::GetInstance()->WriteBuffer((float)width, (float) 33, (char*)"|                                                           |", 4);
	CursorManger::GetInstance()->WriteBuffer((float)width, (float) 34, (char*)"|                                                           |", 4);
	CursorManger::GetInstance()->WriteBuffer((float)width, (float) 35, (char*)"|                                                           |", 4);
	CursorManger::GetInstance()->WriteBuffer((float)width, (float) 36, (char*)"|                                                           |", 4);
	CursorManger::GetInstance()->WriteBuffer((float)width, (float) 37, (char*)"|                                                           |", 4);
	CursorManger::GetInstance()->WriteBuffer((float)width, (float) 38, (char*)" ----------------------------------------------------------- ", 4);

	switch (select) {
	case 0:
		CursorManger::GetInstance()->WriteBuffer((float)width + 25, (float)29, (char*)"START ¢¸", 4);
		CursorManger::GetInstance()->WriteBuffer((float)width + 25, (float)31, (char*)"UPGRADE   ", 4);
		CursorManger::GetInstance()->WriteBuffer((float)width + 25, (float)33, (char*)"OPTION    ", 4);
		CursorManger::GetInstance()->WriteBuffer((float)width + 25, (float)35, (char*)"EXIT      ", 4);
		break;

	case 1:
		CursorManger::GetInstance()->WriteBuffer((float)width + 25, (float)29, (char*)"START     ", 4);
		CursorManger::GetInstance()->WriteBuffer((float)width + 25, (float)31, (char*)"UPGRADE ¢¸", 4);
		CursorManger::GetInstance()->WriteBuffer((float)width + 25, (float)33, (char*)"OPTION    ", 4);
		CursorManger::GetInstance()->WriteBuffer((float)width + 25, (float)35, (char*)"EXIT      ", 4);
		break;

	case 2:
		CursorManger::GetInstance()->WriteBuffer((float)width + 25, (float)29, (char*)"START     ", 4);
		CursorManger::GetInstance()->WriteBuffer((float)width + 25, (float)31, (char*)"UPGRADE   ", 4);
		CursorManger::GetInstance()->WriteBuffer((float)width + 25, (float)33, (char*)"OPTION ¢¸", 4);
		CursorManger::GetInstance()->WriteBuffer((float)width + 25, (float)35, (char*)"EXIT      ", 4);
		break;

	case 3:
		CursorManger::GetInstance()->WriteBuffer((float)width + 25, (float)29, (char*)"START     ", 4);
		CursorManger::GetInstance()->WriteBuffer((float)width + 25, (float)31, (char*)"UPGRADE   ", 4);
		CursorManger::GetInstance()->WriteBuffer((float)width + 25, (float)33, (char*)"OPTION    ", 4);
		CursorManger::GetInstance()->WriteBuffer((float)width + 25, (float)35, (char*)"EXIT ¢¸", 4);
		break;
	}
}

void Menu::Release() {
}
