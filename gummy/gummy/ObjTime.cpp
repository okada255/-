//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL/SceneManager.h"
#include"GameL/WinInputs.h"
#include"GameHead.h"
#include"ObjTime.h"
#include"GameL/DrawFont.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjTime::Init()
{
	m_time = 500*60*60;
	m_flag_time = false;
}

//アクション
void CObjTime::Action()
{
	m_time--;
	
}

//ドロー
void CObjTime::Draw()
{
	//m_timeから秒分を求める
	int minute; //分
	int second =500; //秒
	
	
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	wchar_t str[128];
	
	
	if (second > 0)
		swprintf_s(str, L"%d",second);

	Font::StrDraw(str, 10, 10, 20, c);
}

