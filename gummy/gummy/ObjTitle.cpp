#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjTitle.h"
#include"GameL/UserData.h"

using namespace GameL;

//ai

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

	//ランキング
	Font::StrDraw(L"ランキング",600,0,24,c);
	
	for(int i = 0;i<15;i++)
	{
		wchar_t str[256];
		swprintf_s(str,L"%2d位%12d位点",i+1,(i+1)*100);
		Font::StrDraw(str,670,24+24*i,12,c);
	}

	Font::StrDraw(L"Game Start ", 320, 380, 32, c);
	Font::StrDraw(L" Push [Enter]Key ", 260, 430, 32, c);

	Font::StrDraw(L"★ClickReset", 600, 380, 16, c);
}