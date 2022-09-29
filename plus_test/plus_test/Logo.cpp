#include "Logo.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "CursorManager.h"
#include "ObjectManager.h"
#include "PrototypeManager.h"
#include "Player.h"

Logo::Logo() : time(GetTickCount64()), width(0){

	mainlogo[0]  = (char*)"@@@@@@@@  @@@@@@@@  @@@@@@@@  @@@@@@@@@  @@@@@@@@  @@@@@@@@  @@@@@@@@@@@  @@@@@@@@@@@  @@@@@@@@  @@@@@@@@";
	mainlogo[1]  = (char*)"@@!  @@@  @@!  @@@  @@!  @@@  !@@        @@!  @@@  @@!  @@@  @@! @@! @@!  @@! @@! @@!  @@!       @@!  @@@";
	mainlogo[2]  = (char*)"!@!  @!@  !@!  @!@  !@!  @!@  !@!        !@!  @!@  !@!  @!@  !@! !@! !@!  !@! !@! !@!  !@!       !@!  @!@";
	mainlogo[3]  = (char*)"@!@@!@!   @!@!!@!   @!@  !@!  !@! @!@!@  @!@!!@!   @!@!@!@!  @!! !!@ @!@  @!! !!@ @!@  @!!!:!    @!@!!@!";
	mainlogo[4]  = (char*)"!!@!!!    !!@!@!    !@!  !!!  !!! !!@!!  !!@!@!    !!!@!!!!  !@!   ! !@!  !@!   ! !@!  !!!!!:    !!@!@!";
	mainlogo[5]  = (char*)"!!:       !!: :!!   !!:  !!!  :!!   !!:  !!: :!!   !!:  !!!  !!:     !!:  !!:     !!:  !!:       !!: :!!";
	mainlogo[6]  = (char*)":!:       :!:  !:!  :!:  !:!  :!:   !::  :!:  !:!  :!:  !:!  :!:     :!:  :!:     :!:  :!:       :!:  !:!";
	mainlogo[7]  = (char*)" ::       ::   :::  ::::: ::   ::: ::::  ::   :::  ::   :::  :::     ::   :::     ::    :: ::::  ::   :::";
	mainlogo[8]  = (char*)" :         :   : :   : :  :    :: :: :    :   : :   :   : :   :      :     :      :    : :: ::    :   : :";
	mainlogo[9]  = (char*)" ";
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

Logo::~Logo() {
	Release();
}

void Logo::Start() {
	ObjectManager::GetInstance()->Start();
	Object* pObj = PrototypeManager::GetInstance()->FindObject("Player")->Clone();
	ObjectManager::GetInstance()->AddObject("Fire");
	ObjectManager::GetInstance()->AddObject("Book");
	if (pObj != nullptr)
		ObjectManager::GetInstance()->SetPlayer(pObj);
}

void Logo::Update() {
	if (time + 3000 <= GetTickCount64()) 
		SceneManager::GetInstance()->SetScene(SCENEID::MENU);
	/*
	DWORD dwKey = InputManager::GetInstance()->GetKey();
	if (dwKey & KEY_ENTER)
		SceneManager::GetInstance()->SetScene(SCENEID::MENU);
	*/
}
 

void Logo::Render() {

	width = 65 - strlen(mainlogo[2]) / 2;

	for (int i = 0; i < 10; ++i) {
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)7 + i, mainlogo[i], 2);
	}

	width = 65 - strlen(mainlogo[13]) / 2;

	for (int i = 10; i < 21; ++i) {
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)7 + i, mainlogo[i], 2);
	}
}

void Logo::Release() {
}