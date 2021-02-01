#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameHead.h"
#include"ObjGameOver.h"

using namespace GameL;

void CObjGameOver::Init()
{
	m_key_flag = false;
}

void CObjGameOver::Action()
{
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

void CObjGameOver::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"GAME OVER", 110, 200, 120, c);
	Font::StrDraw(L"NEXT CHARENGE:ENTER_KEY", 70, 380, 60, c);
}
//100, 200, 120, c 230, 350, 32, c