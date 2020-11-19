//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include"GameL/SceneObjManager.h"
#include"GameHead.h"
#include"GameL/UserData.h"
#include"GameL/DrawTexture.h"
#include"GameL/DrawFont.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include"SceneMap1.h"
#include"ObjBlock.h"
#include"ObjCookie.h"
#include"ObjCandy.h"
#include"ObjChoco.h"
#include"ObjDonatu.h"
#include"ObjGummy.h"
#include"ObjRisu.h"
#include"ObjTitle.h"
#include"ObjGameClear.h"
#include"ObjBackGround.h"




//コンストラクタ
CSceneMap3::CSceneMap3()
{

}

//デストラクタ
CSceneMap3::~CSceneMap3()
{


}

//初期化メソッド
void CSceneMap3::InitScene()
{
	//FONT作成
	Font::SetStrTex(L"0123456789分秒");
	Font::SetStrTex(L"0123456789g");

	//外部データの読み込み（ステージ情報）
	unique_ptr<wchar_t> p;//ステージ情報ポインター
	int size;             //ステージ情報の大きさ
	int map[32][32];
	p = Save::ExternalDataOpen(L"MAP3.csv", &size);//外部データ読み込み

	int count = 1;
	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);
			map[i][j] = w;
			count += 2;
		}
	}

	Draw::LoadImageW(L"Block.png", 1, TEX_SIZE_64);
	Draw::LoadImageW(L"risu(2).png", 2, TEX_SIZE_128);//リス
	Draw::LoadImageW(L"gumy.png", 7, TEX_SIZE_64);
	Draw::LoadImageW(L"cake.png", 8, TEX_SIZE_64);

	Draw::LoadImageW(L"Back irasuto.png", 50, TEX_SIZE_64);



	//タイム初期化
	m_time = 0;
	//Blockオブジェクト作成
	CObjBlock* objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 9);

	//リス作成
	CObjRisu* objr = new CObjRisu();
	Objs::InsertObj(objr, OBJ_RISU, 12);

	////BigCakeオブジェクト作成
	//CObjBigCake* objz = new CObjBigCake();
	//Objs::InsertObj(objz, OBJ_BIG_CAKE, 20);

	//タイム作成
	CObjTime* objt = new CObjTime();
	Objs::InsertObj(objt, OBJ_TIME, 16);

	//スコア作成
	CObjScore* objs = new CObjScore();
	Objs::InsertObj(objs, OBJ_SCORE, 17);

	//背景オブジェクト生成
	CObjBackGround* back = new CObjBackGround();
	Objs::InsertObj(back, OBJ_BACKGROUND, 1);

}

//実行中メソッド
void CSceneMap3::Scene()
{
	m_time++;
	if (m_time == 1)
	{
		


	//Gummyオブジェクト作成
		CObjGummy* objg;
		objg = new CObjGummy(140, 50);//C-3
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(140, 440);//C-25
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(140, 520);//C-30
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(160, 165);//D-10
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(195, 330);//E-20
		Objs::InsertObj(objg, OBJ_GUMMY, 13);


		objg = new CObjGummy(235, 165);//H-10
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(245, 270);//I-16
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(245, 415);//I-24
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(315, 65);//L-4
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(330, 285);//M-17
		Objs::InsertObj(objg, OBJ_GUMMY, 13);


		objg = new CObjGummy(340, 435);//N-25
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(385, 225);//P-13
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(385, 520);//P-29
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(425, 20);//R-2
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(425, 180);//R-11
		Objs::InsertObj(objg, OBJ_GUMMY, 13);


		objg = new CObjGummy(485, 255);//U-15
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(485, 415);//U-24
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(510, 535);//V-30
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(490, 90);//V-5
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(505, 50);//W-3
		Objs::InsertObj(objg, OBJ_GUMMY, 13);


		CObjBigCake* objz;
		objz = new CObjBigCake(560, 240);//AB-15
		Objs::InsertObj(objz, OBJ_BIG_CAKE, 50);
		//////BigCakeオブジェクト作成
		//CObjBigCake* objz = new CObjBigCake();
		//Objs::InsertObj(objz, OBJ_BIG_CAKE, 50);

	}
}