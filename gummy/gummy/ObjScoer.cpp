//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL/SceneManager.h"
#include"GameL/WinInputs.h"
#include"GameHead.h"
#include"ObjScore.h"
#include"GameL/DrawFont.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjScore::Init()
{
	m_flag_gram = false;
	m_gram = 1000 * 7200;
}

//アクション
void CObjScore::Action()
{
	if (ELEMENT_ITEM == false)
	{
		;
	}
}

//ドロー
void CObjScore::Draw()
{
	int minute; //分
	int second = 500; //秒


	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	wchar_t str[128];


	if (second > 0)
		swprintf_s(str, L"%d", m_gram / 7200);

	Font::StrDraw(str, 740, 10, 20, c);
}