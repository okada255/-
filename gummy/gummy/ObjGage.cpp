#include"GameL/DrawTexture.h"
#include"GameL/SceneObjManager.h"
#include"GameL/WinInputs.h"
#include"ObjGage.h"
#include"GameHead.h"
#include"GameL/DrawFont.h"
#include"ObjRisu.h"

using namespace GameL;


void CObjGage::Init()
{
	m_flag_gage = false;
}

void CObjGage::Action()
{
		//Zキー入力で速度アップ
		if (Input::GetVKey('Z') == true)
		{
			if (m_sutamina >= 0)
			{
				m_sutamina -= 4500;
			}
		}
	 if(m_sutamina<=720000)
		{
			m_sutamina+=2000;
		}
}

void CObjGage::Draw()
{
	int second = 500; //秒

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	wchar_t str[128];

	if (second > 0)
		Font::StrDraw(L"スタミナ", 630, 130, 30, c);
	swprintf_s(str, L"%d", m_sutamina/7200);

	Font::StrDraw(str, 670, 160, 50, c);
}