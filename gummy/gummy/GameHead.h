#pragma once

//オブジェクトネーム------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//オブジェクト名無し(禁止)
	//ゲームで使うオブジェクトの名前
	//OBJ_○○と表記
	OBJ_CANDY,
	OBJ_CANDYUSO,
	OBJ_CHOCO,
	OBJ_CHOCOUSO,
	OBJ_COOKIE,
	OBJ_COOKIEUSO,
	OBJ_DONATU,
	OBJ_DONATUUSO,
	OBJ_GUMMY,
	OBJ_GUMMYUSO,
	OBJ_RISU,
	OBJ_BLOCK,
	OBJ_BIG_CAKE,
	OBJ_BIG_CAKEUSO,
	OBJ_TITLE,
	OBJ_GAME_CLEAR,
	OBJ_TIME,
	OBJ_SCORE,
	OBJ_GAME_OVER,
	OBJ_BACKGROUND,
	OBJ_UPSTAGE,
	OBJ_UPSTAGE2,
	OBJ_UPSTAGE0,
	OBJ_DESCRIPTION,
};
//------------------------------------------------

//当たり判定属性----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//属性無し 全ての属性と当たり判定が実行される
	//以下　同じ属性同士では当たり判定は実行されない
	//属性は追加可能だが、デバック時の色は初期設定分しか無い
	ELEMENT_PLAYER,
	ELEMENT_ENEMY,
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,
};
//------------------------------------------------

//------------------------------------------------
//セーブ＆ロードとシーン間のやり取りするデータ
struct UserData
{
	int mSeveData;	//サンプルセーブデータ
	int m_point;
	int m_ranking[16];
};
//------------------------------------------------


//ゲーム内で使用されるグローバル変数・定数・列挙--



//------------------------------------------------
//ゲーム内で使用するクラスヘッダ------------------


//------------------------------------------------

//ゲームシーンオブジェクトヘッダ------------------
#include"ObjGummy.h"
#include"ObjGummyuso.h"
#include"ObjChoco.h"
#include"ObjChocouso.h"
#include"ObjCookie.h"
#include"ObjCookieuso.h"
#include"ObjDonatu.h"
#include"ObjDonatuuso.h"
#include"ObjCandy.h"
#include"ObjCandyuso.h"
#include"ObjRisu.h"
#include"ObjBlock.h"
#include"ObjBigCake.h"
#include"ObjBigCakeuso.h"
#include"ObjTitle.h"
#include"ObjGameClear.h"
#include"ObjTime.h"
#include"ObjScore.h"
#include"ObjGameOver.h"
#include"ObjBackGround.h"
#include"Objupstage.h"

#include"Objupstage2.h"
#include"Objupstage0.h"


//#include"ObjRisuL.h"
//#include"ObjRisuR.h"
//#include"ObjRisuU.h"
//#include"ObjRisuD.h"

//------------------------------------------------

//ゲームシーンクラスヘッダ------------------------
#include"SceneMap1.h"
#include"SceneMap1B.h"
#include"SceneMap1C.h"
#include"SceneMap2.h"
#include"SceneMap2B.h"
#include"SceneMap2C.h"
#include"SceneMap3.h"
#include "SceneTitle.h"
#include "SceneGameClear.h"
#include"SceneGameOver.h"
#include"SceneDescription.h"
//-----------------------------------------------

//シーンスタートクラス---------------------------
//ゲーム開始時のシーンクラス登録
#define SET_GAME_START CSceneTitle
//-----------------------------------------------