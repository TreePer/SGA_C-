#include "LevelUp.h"
#include "CursorManager.h"
#include "InputManager.h"
#include "ObjectManager.h"
#include "Stage.h"
#include "SceneManager.h"
#include "Player.h"
#include "PrototypeManager.h"

LevelUp::LevelUp() : select(0), width(0), pObj(nullptr) {
}

LevelUp::~LevelUp() {
}

void LevelUp::Start() {
	srand(GetTickCount64() * GetTickCount64() * GetTickCount64() / 12);
	for (int i = 0; i < 4; ++i) {
		int x = rand() % 6;
		if (i > 0) {
			for (int j = 0; j < i; j++) {
				if (random[j] == x) {
					i--;
					break;
				}
				random[i] = x;
			}
		}
		else {
			random[i] = x;
		}
	}

	text[0][0] = "���ݷ� ����";
	text[0][1] = "�÷��̾��� ��� ������ ��ȭ�˴ϴ�.";
	text[1][0] = "���� ����";
	text[1][1] = "�÷��̾ �Դ� ���ذ� �پ��ϴ�.";
	text[2][0] = "Arrow ��ȭ";
	text[2][1] = "Arrow�� ���ݷ��� �����մϴ�.";
	text[3][0] = "Book ��ȭ";
	text[3][1] = "Book�� ���ݷ��� �����մϴ�.";
	text[4][0] = "Bullet ����";
	text[4][1] = "Bullet�� ���ݷ��� �����մϴ�.";
	text[5][0] = "Fire ����";
	text[5][1] = "Fire�� ���ݷ��� �����մϴ�.";
}

void LevelUp::Update() {

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
		if (select < 3)
			select++;
	if (dwKey & KEY_ENTER) {
		switch (random[select]) {
		case 0 :
			ObjectManager::GetInstance()->GetPlayer()->SetAtk(ObjectManager::GetInstance()->GetPlayer()->GetAtk() + 1);
			break;
		case 1 :
			pObj = ObjectManager::GetInstance()->GetPlayer();
			((Player*)pObj)->SetDef(((Player*)pObj)->GetDef() + 1);
			break;
		case 2 :
			pObj = PrototypeManager::GetInstance()->FindObject("Arrow");
			pObj->SetAtk(pObj->GetAtk() + 10);
			ObjectManager::GetInstance()->UpdateObjectAtk("Arrow", pObj->GetAtk());
			break;
		case 3 :
			pObj = PrototypeManager::GetInstance()->FindObject("Book");
			pObj->SetAtk(pObj->GetAtk() + 10);
			ObjectManager::GetInstance()->UpdateObjectAtk("Book", pObj->GetAtk());
			break;
		case 4 :
			pObj = PrototypeManager::GetInstance()->FindObject("Bullet");
			pObj->SetAtk(pObj->GetAtk() + 10);
			ObjectManager::GetInstance()->UpdateObjectAtk("Bullet", pObj->GetAtk());
			break;
		case 5 :
			pObj = PrototypeManager::GetInstance()->FindObject("Fire");
			pObj->SetAtk(pObj->GetAtk() + 10);
			ObjectManager::GetInstance()->UpdateObjectAtk("Fire", pObj->GetAtk());
			break;
		}
		pObj = ObjectManager::GetInstance()->GetPlayer();
		SceneManager::GetInstance()->SetScene(SCENEID::STAGE);
	}
}

void LevelUp::Render() {
	Stage s;
	s.Render();
	Player p;
	p.Render();

	CursorManger::GetInstance()->WriteBuffer(1, 6, (char*)"  ============================================================================================================================ ", 8);
	for(int i = 7; i < 28; ++i) 
	CursorManger::GetInstance()->WriteBuffer(1, i, (char*)"||                                                                                                                            ||", 8);
	
	CursorManger::GetInstance()->WriteBuffer(1, 28, (char*)"  ============================================================================================================================ ", 8);

	width = 33 - (strlen(" -------------------------------------------------------- ") / 2);

	switch (select) {
	case 0:
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)8, (char*)"  ======================================================= ", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)9, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)10, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)11, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)12, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)13, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)14, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)15, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)16, (char*)"  ======================================================= ", 8);

		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)8, (char*)" -------------------------------------------------------- ", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)9, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)10, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)11, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)12, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)13, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)14, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)15, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)16, (char*)" -------------------------------------------------------- ", 8);

		CursorManger::GetInstance()->WriteBuffer((float)width, (float)18, (char*)" -------------------------------------------------------- ", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)19, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)20, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)21, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)22, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)23, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)24, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)25, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)26, (char*)" -------------------------------------------------------- ", 8);

		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)18, (char*)" -------------------------------------------------------- ", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)19, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)20, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)21, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)22, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)23, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)24, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)25, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)26, (char*)" -------------------------------------------------------- ", 8);
		break;
	case 1:
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)8, (char*)" -------------------------------------------------------- ", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)9, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)10, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)11, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)12, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)13, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)14, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)15, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)16, (char*)" -------------------------------------------------------- ", 8);

		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)8, (char*)"  ======================================================= ", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)9, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)10, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)11, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)12, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)13, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)14, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)15, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)16, (char*)"  ======================================================= ", 8);

		CursorManger::GetInstance()->WriteBuffer((float)width, (float)18, (char*)" -------------------------------------------------------- ", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)19, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)20, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)21, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)22, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)23, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)24, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)25, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)26, (char*)" -------------------------------------------------------- ", 8);

		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)18, (char*)" -------------------------------------------------------- ", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)19, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)20, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)21, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)22, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)23, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)24, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)25, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)26, (char*)" -------------------------------------------------------- ", 8);
		break;
	case 2:
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)8, (char*)" -------------------------------------------------------- ", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)9, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)10, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)11, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)12, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)13, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)14, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)15, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)16, (char*)" -------------------------------------------------------- ", 8);

		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)8, (char*)" -------------------------------------------------------- ", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)9, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)10, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)11, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)12, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)13, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)14, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)15, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)16, (char*)" -------------------------------------------------------- ", 8);

		CursorManger::GetInstance()->WriteBuffer((float)width, (float)18, (char*)"  ======================================================= ", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)19, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)20, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)21, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)22, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)23, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)24, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)25, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)26, (char*)"  ======================================================= ", 8);

		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)18, (char*)" -------------------------------------------------------- ", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)19, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)20, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)21, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)22, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)23, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)24, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)25, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)26, (char*)" -------------------------------------------------------- ", 8);
		break;
	case 3:

		CursorManger::GetInstance()->WriteBuffer((float)width, (float)8, (char*)" -------------------------------------------------------- ", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)9, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)10, (char*)"|                                                        |", 8);;
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)11, (char*)"|                                                        |", 8);;
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)12, (char*)"|                                                        |", 8);;
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)13, (char*)"|                                                        |", 8);;
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)14, (char*)"|                                                        |", 8);;
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)15, (char*)"|                                                        |", 8);;
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)16, (char*)" -------------------------------------------------------- ", 8);

		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)8, (char*)" -------------------------------------------------------- ", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)9, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)10, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)11, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)12, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)13, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)14, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)15, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)16, (char*)" -------------------------------------------------------- ", 8);

		CursorManger::GetInstance()->WriteBuffer((float)width, (float)18, (char*)" -------------------------------------------------------- ", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)19, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)20, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)21, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)22, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)23, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)24, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)25, (char*)"|                                                        |", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width, (float)26, (char*)" -------------------------------------------------------- ", 8);

		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)18, (char*)"  ======================================================= ", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)19, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)20, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)21, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)22, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)23, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)24, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)25, (char*)"||                                                       ||", 8);
		CursorManger::GetInstance()->WriteBuffer((float)width + 63, (float)26, (char*)"  ======================================================= ", 8);
		break;
	}

	CursorManger::GetInstance()->WriteBuffer((float)width + 4, 10.0f, text[random[0]][0], 8);
	CursorManger::GetInstance()->WriteBuffer((float)width + 4, 11.0f, text[random[0]][1], 8);
	CursorManger::GetInstance()->WriteBuffer((float)width + 4 + 63, 10.0f, text[random[1]][0], 8);
	CursorManger::GetInstance()->WriteBuffer((float)width + 4 + 63, 11.0f, text[random[1]][1], 8);
	CursorManger::GetInstance()->WriteBuffer((float)width + 4, 20.0f, text[random[2]][0], 8);
	CursorManger::GetInstance()->WriteBuffer((float)width + 4, 21.0f, text[random[2]][1], 8);
	CursorManger::GetInstance()->WriteBuffer((float)width + 4 + 63, 20.0f, text[random[3]][0], 8);
	CursorManger::GetInstance()->WriteBuffer((float)width + 4 + 63, 21.0f, text[random[3]][1], 8);
}

void LevelUp::Release() {
}
