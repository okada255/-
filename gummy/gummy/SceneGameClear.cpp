#define _SECURE_SCL (0)
#define _HAS_ITENATOR_DEBUGGING (0)

#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"

using namespace GameL;

#include "SceneGameClear.h"
#include "ObjGameClear.h"
#include "GameHead.h"

CSceneGameClear::CSceneGameClear() {

}

CSceneGameClear::~CSceneGameClear() {
}

void CSceneGameClear::InitScene() {
	Font::SetStrTex(L"BOSS TERMINATED");
	Font::SetStrTex(L"congratulations!");
	Font::SetStrTex(L"THE END");

	CObjGameClear* obj = new CObjGameClear();
	Objs::InsertObj(obj, OBJ_GAME_CLEAR, 10);
}

void CSceneGameClear::Scene() {

}