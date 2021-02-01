#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include"GameL/SceneObjManager.h"
#include"GameL/DrawFont.h"
#include"GameL/Audio.h"

//使用するネームスペース
using namespace GameL;

//使用するヘッダー
#include"SceneGameOver.h"
#include"GameHead.h"

//コンストラクタ
CSceneGameOver::CSceneGameOver()
{

}
//デストラクタ
CSceneGameOver::~CSceneGameOver()
{

}

//初期化メソッド
void CSceneGameOver::InitScene()
{

	Font::SetStrTex(L"GAMEOVER");
	Font::SetStrTex(L"Congratulations!");
	Font::SetStrTex(L"THE END");

	Audio::LoadAudio(0, L"GameOver.wav", SOUND_TYPE::BACK_MUSIC);
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((1.0-v));
	Audio::Start(0);

	CObjGameOver* obj = new CObjGameOver();
	Objs::InsertObj(obj, OBJ_GAME_OVER, 17);
}

//実行中メソッド
void CSceneGameOver::Scene()
{

}