#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "GameL\SceneObjManager.h"
#include "SceneDescription.h"
using namespace GameL;

#include "SceneMap1.h"
#include "GameHead.h"
#include "GameL\DrawFont.h"
#include "GameL/Audio.h"
#include"ObjDescription.h"

CSceneDescription::CSceneDescription() {

}

CSceneDescription::~CSceneDescription() {

}
//初期化メソッド
void CSceneDescription::InitScene()



{
	

	Draw::LoadImageW(L"risu(2).png", 2, TEX_SIZE_128);//リス
	Draw::LoadImageW(L"donatu.png", 3, TEX_SIZE_64);
	Draw::LoadImageW(L"candy.png", 4, TEX_SIZE_64);
	Draw::LoadImageW(L"cookie.png", 5, TEX_SIZE_64);
	Draw::LoadImageW(L"choco.png", 6, TEX_SIZE_64);
	Draw::LoadImageW(L"gumy.png", 7, TEX_SIZE_64);
	Draw::LoadImageW(L"cake.png", 8, TEX_SIZE_64);

	Draw::LoadImageW(L"upstage.png", 30, TEX_SIZE_64);//階段
	Audio::LoadAudio(2, L"upstage.wav", SOUND_TYPE::BACK_MUSIC);
	//リス作成
	CObjRisu* objr = new CObjRisu();
	Objs::InsertObj(objr, OBJ_RISU, 12);

	//BigCakeオブジェクト作成
	CObjBigCakeuso* objz = new CObjBigCakeuso(560,240);
	Objs::InsertObj(objz, OBJ_BIG_CAKEUSO, 20);

	//キャンディ嘘
	CObjCandyuso* objc;
	objc = new CObjCandyuso(180, 80);
	Objs::InsertObj(objc, OBJ_CANDYUSO, 10);

	//嘘Cookieオブジェクト作成
	CObjCookieuso* objC;
	objC = new CObjCookieuso(180, 130);
	Objs::InsertObj(objC, OBJ_COOKIEUSO, 10);

	//Donatuオブジェクト作成
	CObjDonatuuso* objd;
	objd = new CObjDonatuuso(180, 180);
	Objs::InsertObj(objd, OBJ_DONATUUSO, 11);

	//Gummyオブジェクト作成
	CObjGummyuso* objg;
	objg = new CObjGummyuso(180, 230);
	Objs::InsertObj(objg, OBJ_GUMMYUSO, 13);

	//Chocoオブジェクト作成
	CObjChocouso* obj_c;
	obj_c = new CObjChocouso(180, 280);
	Objs::InsertObj(obj_c, OBJ_CHOCOUSO, 14);

	//上り階段作成
	CObjupstage0* obju = new CObjupstage0();
	Objs::InsertObj(obju, OBJ_UPSTAGE0, 18);
	
	//スタミナ作成
	CObjGage* objG = new CObjGage();
	Objs::InsertObj(objG, OBJ_GAGE, 27);

	//↓これはCObjDescriptionを表示してます
	CObjDescription* obj = new CObjDescription();
	Objs::InsertObj(obj, OBJ_DESCRIPTION, 10);
}
//実行中メソッド
void CSceneDescription::Scene() {

}