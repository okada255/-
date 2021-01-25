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
//���������\�b�h
void CSceneDescription::InitScene()



{
	

	Draw::LoadImageW(L"risu(2).png", 2, TEX_SIZE_128);//���X
	Draw::LoadImageW(L"donatu.png", 3, TEX_SIZE_64);
	Draw::LoadImageW(L"candy.png", 4, TEX_SIZE_64);
	Draw::LoadImageW(L"cookie.png", 5, TEX_SIZE_64);
	Draw::LoadImageW(L"choco.png", 6, TEX_SIZE_64);
	Draw::LoadImageW(L"gumy.png", 7, TEX_SIZE_64);
	Draw::LoadImageW(L"cake.png", 8, TEX_SIZE_64);

	Draw::LoadImageW(L"upstage.png", 30, TEX_SIZE_64);//�K�i
	Audio::LoadAudio(2, L"upstage.wav", SOUND_TYPE::BACK_MUSIC);
	//���X�쐬
	CObjRisu* objr = new CObjRisu();
	Objs::InsertObj(objr, OBJ_RISU, 12);

	//BigCake�I�u�W�F�N�g�쐬
	CObjBigCakeuso* objz = new CObjBigCakeuso(560,240);
	Objs::InsertObj(objz, OBJ_BIG_CAKEUSO, 20);

	//�L�����f�B�R
	CObjCandyuso* objc;
	objc = new CObjCandyuso(180, 80);
	Objs::InsertObj(objc, OBJ_CANDYUSO, 10);

	//�RCookie�I�u�W�F�N�g�쐬
	CObjCookieuso* objC;
	objC = new CObjCookieuso(180, 130);
	Objs::InsertObj(objC, OBJ_COOKIEUSO, 10);

	//Donatu�I�u�W�F�N�g�쐬
	CObjDonatuuso* objd;
	objd = new CObjDonatuuso(180, 180);
	Objs::InsertObj(objd, OBJ_DONATUUSO, 11);

	//Gummy�I�u�W�F�N�g�쐬
	CObjGummyuso* objg;
	objg = new CObjGummyuso(180, 230);
	Objs::InsertObj(objg, OBJ_GUMMYUSO, 13);

	//Choco�I�u�W�F�N�g�쐬
	CObjChocouso* obj_c;
	obj_c = new CObjChocouso(180, 280);
	Objs::InsertObj(obj_c, OBJ_CHOCOUSO, 14);

	//���K�i�쐬
	CObjupstage0* obju = new CObjupstage0();
	Objs::InsertObj(obju, OBJ_UPSTAGE0, 18);
	
	//�X�^�~�i�쐬
	CObjGage* objG = new CObjGage();
	Objs::InsertObj(objG, OBJ_GAGE, 27);

	//�������CObjDescription��\�����Ă܂�
	CObjDescription* obj = new CObjDescription();
	Objs::InsertObj(obj, OBJ_DESCRIPTION, 10);
}
//���s�����\�b�h
void CSceneDescription::Scene() {

}