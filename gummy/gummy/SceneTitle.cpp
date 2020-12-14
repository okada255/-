#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "GameL\SceneObjManager.h"
#include "SceneTitle.h"
using namespace GameL;

#include "SceneMap1.h"
#include "GameHead.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"

CSceneTitle::CSceneTitle() {

}

CSceneTitle::~CSceneTitle() {

}

void CSceneTitle::InitScene() {

	

	//Draw::LoadImageW(L"拝啓.png", 57, TEX_SIZE_64);//タイトル

	Audio::LoadAudio(4, L"Title.wav", SOUND_TYPE::BACK_MUSIC);
	float v = Audio::VolumeMaster(-0.1f);
	Audio::Start(4);
	Font::SetStrTex(L"シューティングゲーム");
	/*Audio::Start(0);*/
	CObjTitle* obj = new CObjTitle();
	Objs::InsertObj(obj, OBJ_TITLE, 10);

	////背景オブジェクト生成
	//CObjBackGround* back = new CObjBackGround();
	//Objs::InsertObj(back, OBJ_BACKGROUND, 1);
}

void CSceneTitle::Scene() {

}