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
	m_time = 120*7200;//時間調整
	m_flag_time = false;//時間計測
}

//アクション
void CObjTime::Action()
{
	//制限時間の120秒とそれが減っていく仕組み
	for (int i = 1; i <= 120; i++)
	{
		m_time--;

		//制限時間終了時に反映される画面
		if (m_time == 0)
		{
			Scene::SetScene(new CSceneGameOver());
		}
	}
}

//ドロー
void CObjTime::Draw()
{
	//m_timeから秒分を求める
	//int minute; //分
	int second =500; //秒
	
	
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	wchar_t str[128];//128文字分の文字列のスペース
	
	
	if (second > 0)
		Font::StrDraw(L"制限時間", 630, 10, 30, c);//表示内容
	swprintf_s(str, L"%d", m_time / 7200);//整数の文字列化

	Font::StrDraw(str, 670, 40, 50, c);//表示位置
}

