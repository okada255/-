//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL/SceneManager.h"
#include"GameL/WinInputs.h"
#include"GameHead.h"
#include"ObjScore.h"
#include"GameL/DrawFont.h"
#include"GameL/UserData.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjScore::Init()
{
	m_gram = 0;
	m_flag_gram = false;

}

//アクション
void CObjScore::Action()
{
	m_gram = 0;
	if (ELEMENT_ITEM == false)
	{
		;
	}
	m_gram = 0;
	if (OBJ_TIME == false)
	{
		;
	}

}

//ドロー
void CObjScore::Draw()
{


	float cc[4] = { 1.0f,1.0f,1.0f,1.0f };
	wchar_t str[128];
	swprintf_s(str, L"得点：%dg", ((UserData*)Save::GetData())->m_point);
	Font::StrDraw(str, 697, 10, 18.2, cc);
}