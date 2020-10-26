#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjTitle.h"

using namespace GameL;

void CObjTitle::Init() {
	m_key_flag = false;
}

void CObjTitle::Action() {
	if (Input::GetVKey(VK_RETURN) == true) {
		if (m_key_flag == true) {
			Scene::SetScene(new CSceneMain());
			m_key_flag = false;
		}
	}
	else {
		m_key_flag = true;
	}
}

void CObjTitle::Draw() {
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"GUMMY", 220, 200, 150, c);

	Font::StrDraw(L"Game Start ", 320, 380, 32, c);
	Font::StrDraw(L" Push [Enter]Key ", 260, 430, 32, c);

}