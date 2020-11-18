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
#include"Objupstage.h"



//コンストラクタ
CSceneMap1::CSceneMap1()
{

}

//デストラクタ
CSceneMap1::~CSceneMap1()
{


}

//初期化メソッド
void CSceneMap1::InitScene()
{
	//FONT作成
	Font::SetStrTex(L"0123456789分秒");
	Font::SetStrTex(L"0123456789g");

	//外部データの読み込み（ステージ情報）
	unique_ptr<wchar_t> p;//ステージ情報ポインター
	int size;             //ステージ情報の大きさ
	int map[32][32];
	p = Save::ExternalDataOpen(L"MAP1.csv", &size);//外部データ読み込み

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
	Draw::LoadImageW(L"右向き.png", 2, TEX_SIZE_128);//リス
	Draw::LoadImageW(L"左向き.png", 3, TEX_SIZE_128);//リス
	Draw::LoadImageW(L"後ろ姿(1).png", 4, TEX_SIZE_128);//リス
	Draw::LoadImageW(L"前向きリス.png", 5, TEX_SIZE_128);//リス
	Draw::LoadImageW(L"donatu.png", 6, TEX_SIZE_64);
	Draw::LoadImageW(L"candy.png", 7, TEX_SIZE_64);
	Draw::LoadImageW(L"cookie.png", 8, TEX_SIZE_64);
	Draw::LoadImageW(L"choco.png", 9, TEX_SIZE_64);
	Draw::LoadImageW(L"gumy.png", 10, TEX_SIZE_64);
	Draw::LoadImageW(L"cake.png", 11, TEX_SIZE_64);

	Draw::LoadImageW(L"Back irasuto.png", 50, TEX_SIZE_64);

	Draw::LoadImageW(L"upstage.png", 30, TEX_SIZE_64);

	//タイム初期化
	m_time = 0;
	//Blockオブジェクト作成
	CObjBlock* objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 9);

	////Donatuオブジェクト作成
	CObjDonatu* objd = new CObjDonatu();
	Objs::InsertObj(objd, OBJ_DONATU, 11);


	////Gummyオブジェクト作成
	CObjGummy* objg = new CObjGummy();
	Objs::InsertObj(objg, OBJ_GUMMY, 13);

	//リス作成
	CObjRisu* objr = new CObjRisu();
	Objs::InsertObj(objr, OBJ_RISU, 12);

	////BigCakeオブジェクト作成
	CObjBigCake* objz = new CObjBigCake();
	Objs::InsertObj(objz, OBJ_BIG_CAKE, 20);

	//タイム作成
	CObjTime* objt = new CObjTime();
	Objs::InsertObj(objt, OBJ_TIME, 16);

	//スコア作成
	CObjScore* objs = new CObjScore();
	Objs::InsertObj(objs, OBJ_SCORE, 17);

	//背景オブジェクト生成
	CObjBackGround* back = new CObjBackGround();
	Objs::InsertObj(back, OBJ_BACKGROUND, 1);

	//上り階段作成
	CObjupstage* obju = new CObjupstage();
	Objs::InsertObj(obju, OBJ_UPSTAGE, 18);

	//キャンディ
	CObjCandy* objc = new CObjCandy(300, 500);
	Objs::InsertObj(objc, OBJ_CANDY, 10);
	
}

//実行中メソッド
void CSceneMap1::Scene()
{
	m_time++;
	if (m_time == 1)
	{
		//キャンディ
		CObjCandy* objc;
		objc = new CObjCandy(200, 500);
		Objs::InsertObj(objc, OBJ_CANDY, 10);

		//Cookieオブジェクト作成
		CObjCookie* objC = new CObjCookie(200, 450);
		Objs::InsertObj(objC, OBJ_COOKIE, 10);

	}
}