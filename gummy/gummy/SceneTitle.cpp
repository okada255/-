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

	Audio::LoadAudio(0, L"Title.wav", SOUND_TYPE::BACK_MUSIC);
	float v = Audio::VolumeMaster(-0.5f);
	Audio::Start(0);

	Font::SetStrTex(L"シューティングゲーム");
	/*Audio::Start(0);*/
	CObjTitle* obj = new CObjTitle();
	Objs::InsertObj(obj, OBJ_TITLE, 10);
}

void CSceneTitle::Scene() {

}