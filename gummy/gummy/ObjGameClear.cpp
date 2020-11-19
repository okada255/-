#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjGameClear.h"
#include"GameL/UserData.h"

using namespace GameL;

void CObjGameClear::Init() {
	m_key_flag = false;
}

void CObjGameClear::Action() {
	if (Input::GetVKey(VK_RETURN) == true) {
		if (m_key_flag == true) {
			Scene::SetScene(new CSceneTitle());
			m_key_flag = false;
		}
	}
	else {
		m_key_flag = true;
	}

}

void CObjGameClear::Draw() {
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"GAME CLEAR", 100, 200, 120, c);
	Font::StrDraw(L"NEXT CHARENGE:ENTER_KEY", 230, 350, 30, c);

	float cc[4] = { 1.0f,1.0f,1.0f,1.0f };
	wchar_t str[128];
	swprintf_s(str, L"“¾“_F%d“_", ((UserData*)Save::GetData())->m_point);
	Font::StrDraw(str, 260, 50, 60, cc);
}
