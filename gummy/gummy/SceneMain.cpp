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
#include"SceneMain.h"
#include"ObjBlock.h"
#include"ObjCookie.h"
#include"ObjCandy.h"
#include"ObjChoco.h"
#include"ObjDonatu.h"
#include"ObjGummy.h"
//#include"ObjRisu.h"
#include"ObjRisuR.h"
#include"ObjRisuL.h"
#include"ObjRisuU.h"
#include"ObjRisuD.h"
#include"ObjTitle.h"
#include"ObjGameClear.h"


//コンストラクタ
CSceneMain::CSceneMain()
{

}

//デストラクタ
CSceneMain::~CSceneMain()
{


}

//初期化メソッド
void CSceneMain::InitScene()
{
	//FONT作成
	Font::SetStrTex(L"0123456789分秒");

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
	Draw::LoadImageW(L"右向き.png", 2, TEX_SIZE_128);//右リス
	Draw::LoadImageW(L"左向き.png", 3, TEX_SIZE_128);//左リス
	Draw::LoadImageW(L"前向きリス.png", 4, TEX_SIZE_128);//前向きリス
	Draw::LoadImageW(L"後ろ向き(1).png", 5, TEX_SIZE_128);//後ろ向きリス
	Draw::LoadImageW(L"donatu.png",6, TEX_SIZE_64);
	Draw::LoadImageW(L"candy.png", 7, TEX_SIZE_64);
	Draw::LoadImageW(L"cookie.png",8, TEX_SIZE_64);
	Draw::LoadImageW(L"choco.png",9, TEX_SIZE_64);
	Draw::LoadImageW(L"gumy.png",10, TEX_SIZE_64);


	//Blockオブジェクト作成
	CObjBlock* objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 9);

	////Candyオブジェクト作成
	CObjCandy* objc = new CObjCandy();
	Objs::InsertObj(objc, OBJ_CANDY, 10);

	////Cookieオブジェクト作成
	CObjCookie* objC = new CObjCookie();
	Objs::InsertObj(objC, OBJ_COOKIE, 15);

	////Donatuオブジェクト作成
	CObjDonatu* objd = new CObjDonatu();
	Objs::InsertObj(objd, OBJ_DONATU, 11);

	////Chocoオブジェクト作成
	CObjChoco* obj_c = new CObjChoco();
	Objs::InsertObj(obj_c, OBJ_CANDY, 14);

	////Gummyオブジェクト作成
	CObjGummy* objg = new CObjGummy();
	Objs::InsertObj(objg, OBJ_GUMMY, 13);

	//リス作成右	
	CObjRisuR* objr = new CObjRisuR();
	Objs::InsertObj(objr, OBJ_RISUR, 12);

	//リス作成左
	CObjRisuL* objr = new CObjRisuL();
	Objs::InsertObj(objr, OBJ_RISUL, 12);

	//リス作成上
	CObjRisuU* objr = new CObjRisuU();
	Objs::InsertObj(objr, OBJ_RISUU, 12);

	//リス作成下
	CObjRisuD* objr = new CObjRisuD();
	Objs::InsertObj(objr, OBJ_RISUD, 12);

	////リス作成
	//CObjRisu* objr = new CObjRisu();
	//Objs::InsertObj(objr, OBJ_RISU, 12);


	//タイム作成
	CObjTime* objt = new CObjTime();
	Objs::InsertObj(objt, OBJ_TIME, 16);

	//スコア作成
	CObjScore* objs = new CObjScore();
	Objs::InsertObj(objs, OBJ_SCORE, 17);
}

//実行中メソッド
void CSceneMain::Scene()
{

}