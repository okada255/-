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
#include"SceneMap2.h"
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
#include"Objupstage2.h"
#include"ObjTime.h"


//コンストラクタ
CSceneMap2::CSceneMap2()
{

}

//デストラクタ
CSceneMap2::~CSceneMap2()
{


}

//初期化メソッド
void CSceneMap2::InitScene()
{
	//FONT作成
	Font::SetStrTex(L"0123456789分秒");
	Font::SetStrTex(L"0123456789g");

	//外部データの読み込み（ステージ情報）
	unique_ptr<wchar_t> p;//ステージ情報ポインター
	int size;             //ステージ情報の大きさ
	int map[32][32];
	p = Save::ExternalDataOpen(L"MAP2.csv", &size);//外部データ読み込み

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
	Draw::LoadImageW(L"右向き1.png", 2, TEX_SIZE_128);//リス右
	Draw::LoadImageW(L"左向き1.png", 3, TEX_SIZE_128);//リス左
	Draw::LoadImageW(L"後ろ姿1.png", 4, TEX_SIZE_128);//リス上
	Draw::LoadImageW(L"前向き1.png", 5, TEX_SIZE_128);//リス下
	Draw::LoadImageW(L"donatu.png", 6, TEX_SIZE_64);
	Draw::LoadImageW(L"candy.png", 7, TEX_SIZE_64);
	Draw::LoadImageW(L"cookie.png", 8, TEX_SIZE_64);
	Draw::LoadImageW(L"choco.png", 9, TEX_SIZE_64);
	Draw::LoadImageW(L"gumy.png", 10, TEX_SIZE_64);
	
	Draw::LoadImageW(L"upstage.png", 30, TEX_SIZE_64);
	Draw::LoadImageW(L"Back irasuto.png", 50, TEX_SIZE_64);

	//タイム初期化
	m_time = 0;
	//Blockオブジェクト作成
	CObjBlock* objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 9);

	//タイム作成
	CObjTime* objt = new CObjTime();
	Objs::InsertObj(objt, OBJ_TIME, 16);

	//スコア作成
	CObjScore* objs = new CObjScore();
	Objs::InsertObj(objs, OBJ_SCORE, 17);

	//背景オブジェクト生成
	CObjBackGround* back = new CObjBackGround();
	Objs::InsertObj(back, OBJ_BACKGROUND, 1);

	//リス作成
	CObjRisu* objr = new CObjRisu();
	Objs::InsertObj(objr, OBJ_RISU, 12);

	//上り階段作成
	CObjupstage2* obju2 = new CObjupstage2();
	Objs::InsertObj(obju2, OBJ_UPSTAGE2, 18);
}

//実行中メソッド
void CSceneMap2::Scene()
{
	m_time++;
	if (m_time == 1)
	{
		//キャンディ
		CObjCandy* objc;
		objc = new CObjCandy(350,50);
		Objs::InsertObj(objc, OBJ_CANDY, 10);

		objc = new CObjCandy(620, 300);
		Objs::InsertObj(objc, OBJ_CANDY, 10);

		objc = new CObjCandy(250, 550);
		Objs::InsertObj(objc, OBJ_CANDY, 10);

		objc = new CObjCandy(550, 550);
		Objs::InsertObj(objc, OBJ_CANDY, 10);

		//Cookieオブジェクト作成
		CObjCookie* objC;
		objC = new CObjCookie(150, 50);
		Objs::InsertObj(objC, OBJ_COOKIE, 10);

		objC = new CObjCookie(640, 50);
		Objs::InsertObj(objC, OBJ_COOKIE, 10);

		objC = new CObjCookie(300, 285);
		Objs::InsertObj(objC, OBJ_COOKIE, 10);

		objC = new CObjCookie(150,540);
		Objs::InsertObj(objC, OBJ_COOKIE, 10);

		objC = new CObjCookie(500,500);
		Objs::InsertObj(objC, OBJ_COOKIE, 10);

		//Donatuオブジェクト作成
		CObjDonatu* objd;
		objd = new CObjDonatu(440, 100);
		Objs::InsertObj(objd, OBJ_DONATU, 11);

		//Gummyオブジェクト作成
		CObjGummy* objg;
		objg = new CObjGummy(540, 50);
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(310,175);
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(400, 200);
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(140, 400);
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		//Chocoオブジェクト作成
		CObjChoco* obj_c;
		obj_c = new CObjChoco(220,150);
		Objs::InsertObj(obj_c, OBJ_CHOCO, 14);

		obj_c = new CObjChoco(610, 150);
		Objs::InsertObj(obj_c, OBJ_CHOCO, 14);

		obj_c = new CObjChoco(500, 200);
		Objs::InsertObj(obj_c, OBJ_CHOCO, 14);

		obj_c = new CObjChoco(520, 340);
		Objs::InsertObj(obj_c, OBJ_CHOCO, 14);

		obj_c = new CObjChoco(175, 480);
		Objs::InsertObj(obj_c, OBJ_CHOCO, 14);

		obj_c = new CObjChoco(250, 450);
		Objs::InsertObj(obj_c, OBJ_CHOCO, 14);
	}
}