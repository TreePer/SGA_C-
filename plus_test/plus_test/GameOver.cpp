#include "GameOver.h"
#include "InputManager.h"
#include "CursorManager.h"

GameOver::GameOver() {
}

GameOver::~GameOver() {
}

void GameOver::Start() {
}

void GameOver::Update() {
	DWORD dwKey = InputManager::GetInstance()->GetKey();
	if (dwKey & KEY_ENTER) {
		exit(0);
	}
}

void GameOver::Render() {
    int x = 65 - (strlen((char*)" #####     #    #     # #######    ####### #     # ####### ######  ") / 2);

    CursorManger::GetInstance()->WriteBuffer(x, 14, (char*)" #####     #    #     # #######    ####### #     # ####### ######  ", 12);
    CursorManger::GetInstance()->WriteBuffer(x, 15, (char*)"#     #   # #   ##   ## #          #     # #     # #       #     # ", 12);
    CursorManger::GetInstance()->WriteBuffer(x, 16, (char*)"#        #   #  # # # # #          #     # #     # #       #     # ", 12);
    CursorManger::GetInstance()->WriteBuffer(x, 17, (char*)"#  #### #     # #  #  # #####      #     # #     # #####   ######  ", 12);
    CursorManger::GetInstance()->WriteBuffer(x, 18, (char*)"#     # ####### #     # #          #     #  #   #  #       #   #   ", 12);
    CursorManger::GetInstance()->WriteBuffer(x, 19, (char*)"#     # #     # #     # #          #     #   # #   #       #    #  ", 12);
    CursorManger::GetInstance()->WriteBuffer(x, 20, (char*)" #####  #     # #     # #######    #######    #    ####### #     # ", 12);
}

void GameOver::Release() {
}
