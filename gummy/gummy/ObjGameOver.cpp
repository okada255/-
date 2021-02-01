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

	Font::StrDraw(L"GAME OVER", 200, 200, 32, c);
	Font::StrDraw(L"NEXT CHARENGE:ENTER_KEY", 230, 350, 32, c);
}