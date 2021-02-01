#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include"GameL/SceneObjManager.h"
#include"GameL/DrawFont.h"
#include"GameL/Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p����w�b�_�[
#include"SceneGameOver.h"
#include"GameHead.h"

//�R���X�g���N�^
CSceneGameOver::CSceneGameOver()
{

}
//�f�X�g���N�^
CSceneGameOver::~CSceneGameOver()
{

}

//���������\�b�h
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

//���s�����\�b�h
void CSceneGameOver::Scene()
{

}