#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameHead.h"
#include "ObjTitle.h"
#include"GameL/UserData.h"
#include"GameL/Audio.h"

using namespace GameL;

void CObjTitle::Init() {
	m_key_flag = false;

	//ゲーム実行して一回のみ
	static bool init_point =false;
	if (init_point == false)
	{
		//点数を0にする
		((UserData*)Save::GetData())->m_point=0;
		((UserData*)Save::GetData())->Gtime = 0;
		
		//ロード
		Save::Open();//同フォルダー「UserDate」からデータ所得。
		
		//点数を0にする
		((UserData*)Save::GetData())->m_point = 0;

		init_point = true;
	}

	//ゲームを実行して一回目のみ以外、ランキングをセーブする
	if (init_point==true)
	{
		Save::Seve();//UserDateの情報を同フォルダーに「UserDate」を作成する
	}
	//点数を0にする
	((UserData*)Save::GetData())->m_point = 0;

	((UserData*)Save::GetData())->Gtimehakaru = 871200;//時間初期化
}

void CObjTitle::Action() {

	if (Input::GetVKey(VK_RETURN) == true) {
		if (m_key_flag == true) {
			Scene::SetScene(new CSceneDescription());
			m_key_flag = false;
		}
	}
	else {
		m_key_flag = true;
	}


}

void CObjTitle::Draw() {
	//描画カラー情報 R G B A
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"GUMMY", 220, 200, 150, c);

	Font::StrDraw(L"Game Start ", 320, 380, 32, c);
	Font::StrDraw(L" Push [Enter]Key ", 260, 430, 32, c);


}

void CObjTitle::RankingSort(int rank[16])
{
	//値交換用変数
	int w;

	//バブルソート
	for (int i = 0; i < 15; i++)
	{
		for (int j = i+1; i < 16; i++)
		{
			if (rank[i]<rank[i])
			{
				//値を交換
				w = rank[i];
				rank[i] = rank[j];
				rank[j]=w;
			}
		}
	}
}