#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "GameL\SceneObjManager.h"
#include "SceneDescription.h"
using namespace GameL;

#include "SceneMap1.h"
#include "GameHead.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"
#include"ObjDescription.h"

CSceneDescription::CSceneDescription() {

}

CSceneDescription::~CSceneDescription() {

}
//初期化メソッド
void CSceneDescription::InitScene()
{
	

	Draw::LoadImageW(L"右向き1.png", 2, TEX_SIZE_128);//リス右
	Draw::LoadImageW(L"左向き1.png", 3, TEX_SIZE_128);//リス左

	Draw::LoadImageW(L"donatu.png", 6, TEX_SIZE_64);//お菓子
	Draw::LoadImageW(L"candy.png", 7, TEX_SIZE_64);//お菓子
	Draw::LoadImageW(L"cookie.png", 8, TEX_SIZE_64);//お菓子
	Draw::LoadImageW(L"choco.png", 9, TEX_SIZE_64);//お菓子
	Draw::LoadImageW(L"gumy.png", 10, TEX_SIZE_64);//お菓子
	Draw::LoadImageW(L"cake.png", 11, TEX_SIZE_64);//お菓子

	Draw::LoadImageW(L"upstage.png", 30, TEX_SIZE_64);//階段
	
	

	//リス作成
	CObjRisu* objr = new CObjRisu();
	Objs::InsertObj(objr, OBJ_RISU, 12);

	//BigCakeオブジェクト作成
	CObjBigCake* objz = new CObjBigCake();
	Objs::InsertObj(objz, OBJ_BIG_CAKE, 20);

	//キャンディ
	CObjCandy* objc;
	objc = new CObjCandy(180, 80);
	Objs::InsertObj(objc, OBJ_CANDY, 10);

	//Cookieオブジェクト作成
	CObjCookie* objC;
	objC = new CObjCookie(180, 130);
	Objs::InsertObj(objC, OBJ_COOKIE, 10);

	//Donatuオブジェクト作成
	CObjDonatu* objd;
	objd = new CObjDonatu(180, 180);
	Objs::InsertObj(objd, OBJ_DONATU, 11);

	//Gummyオブジェクト作成
	CObjGummy* objg;
	objg = new CObjGummy(180, 230);
	Objs::InsertObj(objg, OBJ_GUMMY, 13);

	//Chocoオブジェクト作成
	CObjChoco* obj_c;
	obj_c = new CObjChoco(180, 280);
	Objs::InsertObj(obj_c, OBJ_CHOCO, 14);

	//上り階段作成
	CObjupstage0* obju = new CObjupstage0();
	Objs::InsertObj(obju, OBJ_UPSTAGE0, 18);
	
	//↓これはCObjDescriptionを表示してます
	CObjDescription* obj = new CObjDescription();
	Objs::InsertObj(obj, OBJ_DESCRIPTION, 10);
}
//実行中メソッド
void CSceneDescription::Scene() {

}