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
	Font::StrDraw(str, 600, 80, 35, cc);

	//領域外お菓子
	swprintf_s(str, L"：5g", ((UserData*)Save::GetData())->m_point);
	Font::StrDraw(str, 630, 300, 20, cc);
	swprintf_s(str, L"：10g", ((UserData*)Save::GetData())->m_point);
	Font::StrDraw(str, 630, 330, 20, cc);
	swprintf_s(str, L"：15g", ((UserData*)Save::GetData())->m_point);
	Font::StrDraw(str, 630, 360, 20, cc);
	swprintf_s(str, L"：20g", ((UserData*)Save::GetData())->m_point);
	Font::StrDraw(str, 630, 390, 20, cc);
	swprintf_s(str, L"：50g", ((UserData*)Save::GetData())->m_point);
	Font::StrDraw(str, 630, 420, 20, cc);


}