#include "Upgrade.h"
#include "Player.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "CursorManager.h"
#include "ObjectManager.h"

Upgrade::Upgrade() : select(0), pPlayer(nullptr), width(0) {
	for (int i = 0; i < 4; ++i) {
		title[i] = (char*)" ";
	}
}

Upgrade::~Upgrade() {
	Release();
}

void Upgrade::Start() {
	SP = 10;
	ATK = 0;
	DEF = 0;
	SPEED = 0;
	MAGNET = 0;
	pPlayer = ObjectManager::GetInstance()->GetPlayer();

	title[0] = (char*)" _____ _____ _____ _____ _____ ___   _____ ";
	title[1] = (char*)"|  |  |  _  |   __| __  |  _  |   ＼|   __|";
	title[2] = (char*)"|  |  |   __|  |  |    -|     |  |  |   __|";
	title[3] = (char*)"|_____|__|  |_____|__|__|__|__|____/|_____|";
}

void Upgrade::Update() {
	DWORD dwKey = InputManager::GetInstance()->GetKey();
	if (dwKey & KEY_UP)
		if (select > 1)
			select -= 2;
	if (dwKey & KEY_DOWN)
		if (select < 2)
			select += 2;
	if (dwKey & KEY_LEFT)
		if (select > 0)
			select--;
	if (dwKey & KEY_RIGHT)
		if (select < 3 )
			select++;
	if (dwKey & KEY_ENTER) {
		switch (select) {
		case 0 :
			if (SP > 0 && ATK < 3) {
				ATK++;
				SP--;
			}
			break;
		case 1 :
			if (SP > 0 && DEF < 3) {
				DEF++;
				SP--;
			}
			break;
		case 2 :
			if (SP > 0 && SPEED < 3) {
				SPEED++;
				SP--;
			}
			break;
		case 3 :
			if (SP > 0 && MAGNET < 3) {
				MAGNET++;
				SP--;
			}
			break;
		}
	}
	if (dwKey & KEY_ESC) {
		pPlayer->SetAtk(pPlayer->GetAtk() + ATK);
		((Player*)pPlayer)->SetDef(((Player*)pPlayer)->GetDef() + DEF);
		((Player*)pPlayer)->SetSpeed(((Player*)pPlayer)->GetSpeed() + SPEED);
		((Player*)pPlayer)->SetMagnet(((Player*)pPlayer)->GetMagnet() + MAGNET);
		SceneManager::GetInstance()->SetScene(SCENEID::MENU);
	}
}

void Upgrade::Render() {
	char buffer[8] = " ";
	sprintf(buffer, "%d", ((Player*)pPlayer)->GetAtk());
	CursorManger::GetInstance()->WriteBuffer(1.0f, 1.0f, buffer);

	width = 65 - (strlen(title[3]) / 2);
	for (int i = 0; i < 4; ++i) {
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)2 + i, title[i], 8);
	}

	sprintf(buffer, "SP : %d", SP);
	CursorManger::GetInstance()->WriteBuffer(120.0f, 7.0f, buffer, 8);

	width = 33 - (strlen(" -------------------------------------------------------- ") / 2);
	

	switch (select) {
	case 0 :
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)8,  (char*)"  ======================================================= " , 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)9,  (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)10, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)11, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)12, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)13, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)14, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)15, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)16, (char*)"  ======================================================= " , 8);

		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)8,  (char*)" -------------------------------------------------------- ", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)9,  (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)10, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)11, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)12, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)13, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)14, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)15, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)16, (char*)" -------------------------------------------------------- ", 8);

		CursorManger::GetInstance()->WriteBuffer((float)width, (float)18, (char*)" -------------------------------------------------------- ", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)19, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)20, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)21, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)22, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)23, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)24, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)25, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)26, (char*)" -------------------------------------------------------- ", 8);

		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)18, (char*)" -------------------------------------------------------- ", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)19, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)20, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)21, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)22, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)23, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)24, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)25, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)26, (char*)" -------------------------------------------------------- ", 8);
		break;
	case 1 :
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)8, (char*)" -------------------------------------------------------- ", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)9, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)10, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)11, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)12, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)13, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)14, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)15, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)16, (char*)" -------------------------------------------------------- ", 8);

		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)8,  (char*)"  ======================================================= ", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)9,  (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)10, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)11, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)12, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)13, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)14, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)15, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)16, (char*)"  ======================================================= ", 8);

		CursorManger::GetInstance()->WriteBuffer((float)width, (float)18, (char*)" -------------------------------------------------------- ", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)19, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)20, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)21, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)22, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)23, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)24, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)25, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)26, (char*)" -------------------------------------------------------- ", 8);

		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)18, (char*)" -------------------------------------------------------- ", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)19, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)20, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)21, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)22, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)23, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)24, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)25, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)26, (char*)" -------------------------------------------------------- ", 8);
		break;
	case 2 :
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)8,  (char*)" -------------------------------------------------------- ", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)9,  (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)10, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)11, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)12, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)13, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)14, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)15, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)16, (char*)" -------------------------------------------------------- ", 8);

		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)8, (char*)" -------------------------------------------------------- ", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)9, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)10, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)11, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)12, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)13, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)14, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)15, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)16, (char*)" -------------------------------------------------------- ", 8);

		CursorManger::GetInstance()->WriteBuffer((float)width, (float)18, (char*)"  ======================================================= ", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)19, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)20, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)21, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)22, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)23, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)24, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)25, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)26, (char*)"  ======================================================= ", 8);

		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)18, (char*)" -------------------------------------------------------- ", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)19, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)20, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)21, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)22, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)23, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)24, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)25, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)26, (char*)" -------------------------------------------------------- ", 8);
		break;
	case 3 :

		CursorManger::GetInstance()->WriteBuffer((float)width, (float)8, (char*)" -------------------------------------------------------- ", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)9, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)10, (char*)"|                                                        |", 8);;
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)11, (char*)"|                                                        |", 8);;
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)12, (char*)"|                                                        |", 8);;
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)13, (char*)"|                                                        |", 8);;
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)14, (char*)"|                                                        |", 8);;
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)15, (char*)"|                                                        |", 8);;
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)16, (char*)" -------------------------------------------------------- ", 8);

		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)8, (char*)" -------------------------------------------------------- ", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)9, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)10, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)11, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)12, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)13, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)14, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)15, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)16, (char*)" -------------------------------------------------------- ", 8);

		CursorManger::GetInstance()->WriteBuffer((float)width, (float)18, (char*)" -------------------------------------------------------- ", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)19, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)20, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)21, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)22, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)23, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)24, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)25, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)26, (char*)" -------------------------------------------------------- ", 8);

		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)18, (char*)"  ======================================================= ", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)19, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)20, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)21, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)22, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)23, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)24, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)25, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 65, (float)26, (char*)"  ======================================================= ", 8);
		break;
	}

	CursorManger::GetInstance()->WriteBuffer((float)width + 4, 10.0f, (char*)"공격력 증가", 8);
	CursorManger::GetInstance()->WriteBuffer((float)width + 4, 11.0f, (char*)"플레이어의 모든 공격이 강화됩니다.", 8);
	CursorManger::GetInstance()->WriteBuffer((float)width + 4 + 65, 10.0f, (char*)"방어력 증가", 8);
	CursorManger::GetInstance()->WriteBuffer((float)width + 4 + 65, 11.0f, (char*)"플레이어가 입는 피해가 줄어듭니다.", 8);
	CursorManger::GetInstance()->WriteBuffer((float)width + 4, 20.0f, (char*)"이동속도 증가", 8);
	CursorManger::GetInstance()->WriteBuffer((float)width + 4, 21.0f, (char*)"플레이어의 이동속도가 증가합니다.", 8);
	CursorManger::GetInstance()->WriteBuffer((float)width + 4 + 65, 20.0f, (char*)"획득 범위 증가", 8);
	CursorManger::GetInstance()->WriteBuffer((float)width + 4 + 65, 21.0f, (char*)"플레이어가 더 넓은 범위의 아이템을 획득합니다.", 8);

	switch (ATK) {
	case 0 :
		CursorManger::GetInstance()->WriteBuffer((float)width + 4 + 44, 14.0f, (char*)"□ □ □", 8);
		break;
	case 1 :
		CursorManger::GetInstance()->WriteBuffer((float)width + 4 + 44, 14.0f, (char*)"■ □ □", 8);
		break;
	case 2 :
		CursorManger::GetInstance()->WriteBuffer((float)width + 4 + 44, 14.0f, (char*)"■ ■ □", 8);
		break;
	case 3 :
		CursorManger::GetInstance()->WriteBuffer((float)width + 4 + 44, 14.0f, (char*)"■ ■ ■", 8);
		break;
	}

	switch (DEF) {
	case 0:
		CursorManger::GetInstance()->WriteBuffer((float)width + 4 + 44 + 65, 14.0f, (char*)"□ □ □", 8);
		break;
	case 1:
		CursorManger::GetInstance()->WriteBuffer((float)width + 4 + 44 + 65, 14.0f, (char*)"■ □ □", 8);
		break;
	case 2:
		CursorManger::GetInstance()->WriteBuffer((float)width + 4 + 44 + 65, 14.0f, (char*)"■ ■ □", 8);
		break;
	case 3:
		CursorManger::GetInstance()->WriteBuffer((float)width + 4 + 44 + 65, 14.0f, (char*)"■ ■ ■", 8);
		break;
	}

	switch (SPEED) {
	case 0:
		CursorManger::GetInstance()->WriteBuffer((float)width + 4 + 44, 24.0f, (char*)"□ □ □", 8);
		break;
	case 1:
		CursorManger::GetInstance()->WriteBuffer((float)width + 4 + 44, 24.0f, (char*)"■ □ □", 8);
		break;
	case 2:
		CursorManger::GetInstance()->WriteBuffer((float)width + 4 + 44, 24.0f, (char*)"■ ■ □", 8);
		break;
	case 3:
		CursorManger::GetInstance()->WriteBuffer((float)width + 4 + 44, 24.0f, (char*)"■ ■ ■", 8);
		break;
	}

	switch (MAGNET) {
	case 0:
		CursorManger::GetInstance()->WriteBuffer((float)width + 4 + 44 + 65, 24.0f, (char*)"□ □ □", 8);
		break;
	case 1:
		CursorManger::GetInstance()->WriteBuffer((float)width + 4 + 44 + 65, 24.0f, (char*)"■ □ □", 8);
		break;
	case 2:
		CursorManger::GetInstance()->WriteBuffer((float)width + 4 + 44 + 65, 24.0f, (char*)"■ ■ □", 8);
		break;
	case 3:
		CursorManger::GetInstance()->WriteBuffer((float)width + 4 + 44 + 65, 24.0f, (char*)"■ ■ ■", 8);
		break;
	}

	
}

void Upgrade::Release() {
}
