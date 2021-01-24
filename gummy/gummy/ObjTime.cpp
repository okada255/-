//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL/SceneManager.h"
#include"GameL/WinInputs.h"
#include"GameHead.h"
#include"ObjTime.h"
#include"GameL/DrawFont.h"
#include"GameL/UserData.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjTime::Init()
{
	m_flag_time = false;
}

//アクション
void CObjTime::Action()
{
		for (int i = 1; i <= 118; i++)
		{
			((UserData*)Save::GetData())->Gtimehakaru--;
			

			if (((UserData*)Save::GetData())->Gtimehakaru == 0)
			{
				Scene::SetScene(new CSceneGameOver());
				((UserData*)Save::GetData())->Gtimehakaru = 871200;
			}
		}
		((UserData*)Save::GetData())->Gtime = ((UserData*)Save::GetData())->Gtimehakaru/7200;
}	

//ドロー
void CObjTime::Draw()
{
	//m_timeから秒分を求める
	//int minute; //分
	int second =500; //秒
	
	
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	wchar_t str[128];
	
	
	if (second > 0)
		Font::StrDraw(L"制限時間", 630, 10, 30, c);
	swprintf_s(str, L"%d", ((UserData*)Save::GetData())->Gtimehakaru / 7200);

	Font::StrDraw(str, 670, 40, 50, c);
}

