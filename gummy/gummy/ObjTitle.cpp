#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include"SceneMap1.h"
#include "GameHead.h"
#include "ObjTitle.h"
#include"GameL/UserData.h"
#include"GameL/Audio.h"

using namespace GameL;

void CObjTitle::Init() {
	m_key_flag = false;
	m_mou_x = 0;
	m_mou_y = 0;
	m_mou_r = false;
	m_mou_l = false;
	m_time = false;

	//ゲーム実行して一回のみ
	static bool init_point =false;
	if (init_point == false)
	{
		//点数を0にする
		((UserData*)Save::GetData())->m_point=0;
		((UserData*)Save::GetData())->Gtime = 0;
		//ランキング初期化
		for (int i = 0; i < 16; i++)
		{
			((UserData*)Save::GetData())->m_ranking[i] = 0;
		}
		//ロード
		Save::Open();//同フォルダー「UserDate」からデータ所得。
		
		//点数を0にする
		((UserData*)Save::GetData())->m_point = 0;

		init_point = true;
	}

	////得点情報をランキング最下位(描画圏外)に登録
	//((UserData*)Save::GetData())->m_ranking[15] = ((UserData*)Save::GetData())->m_point;

	////得点が高い順に並び変えをする
	//RankingSort(((UserData*)Save::GetData())->m_ranking);

	//ゲームを実行して一回目のみ以外、ランキングをセーブする
	if (init_point==true)
	{
		Save::Seve();//UserDateの情報を同フォルダーに「UserDate」を作成する
	}
	//点数を0にする
	((UserData*)Save::GetData())->m_point = 0;
}

void CObjTitle::Action() {

	if (Input::GetVKey(VK_RETURN) == true) {
		if (m_key_flag == true) {
			Scene::SetScene(new CSceneDescription());
			if (m_time == true) {
				CObjTime* objt = new CObjTime();
				Objs::InsertObj(objt, OBJ_TIME, 16);
				m_time = false;
			}
			else
			{
				m_time = false;
			}
			m_key_flag = false;
		}
	}
	else {
		m_key_flag = true;
	}

	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	//マウスのボタン情報
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();

	//マウスの位置とクリックする場所で当たり判定
	if (m_mou_x > 230 && m_mou_x < 450 && m_mou_y>400 && m_mou_x < 430)
	{
		//マウスのボタンが押されたらメインに移行
		if (m_mou_r == true | m_mou_l == true)
		{
			Scene::SetScene(new CSceneDescription());
		}
	}

	////ランキングリセットの部分との当たり判定
	//if (m_mou_x > CLICK_RESET_POS_X && m_mou_x < CLICK_RESET_POS_X + 100 &&
	//	m_mou_y>CLICK_RESET_POS_Y && m_mou_y < CLICK_RESET_POS_Y + 32)
	//{
	//	//ランキング初期化
	//	for (int i = 0; i < 16; i++)
	//	{
	//		((UserData*)Save::GetData())->m_ranking[i] = 0;
	//	}	
	//}
	m_mou_r = false;
	m_mou_l = false;
}

void CObjTitle::Draw() {
	//描画カラー情報 R G B A
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"GUMMY", 220, 200, 150, c);


	////ランキング
	//Font::StrDraw(L"ランキング",RANKING_POS_X, RANKING_POS_Y, RANKING_FONT_SIZE,c );
	//
	//for(int i = 0;i<RANKING_SCORE_MAX;i++)
	//{
	//	wchar_t str[STR_MAX];
	//	swprintf_s(str,L"%2d位%12d位点",i+SCORE_INIT,(i+SCORE_INIT)*SCORE_POINT_MAX);
	//	Font::StrDraw(str,SCORE_POS_X,SCORE_POS_Y+SCORE_INTERVAL*i,SCORE_FONT_SIZE,c);
	//}

	Font::StrDraw(L"Game Start ", 320, 380, 32, c);
	Font::StrDraw(L" Push [Enter]Key ", 260, 430, 32, c);

	//Font::StrDraw(L"★ClickReset", 600, 380, 16, c);

	

	//RECT_F src;//描画元切り取り位置
	//RECT_F dst;//描画先表示位置

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