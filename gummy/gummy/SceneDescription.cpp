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
//���������\�b�h
void CSceneDescription::InitScene()
{
	

	Draw::LoadImageW(L"�E����1.png", 2, TEX_SIZE_128);//���X�E
	Draw::LoadImageW(L"������1.png", 3, TEX_SIZE_128);//���X��

	Draw::LoadImageW(L"donatu.png", 6, TEX_SIZE_64);//���َq
	Draw::LoadImageW(L"candy.png", 7, TEX_SIZE_64);//���َq
	Draw::LoadImageW(L"cookie.png", 8, TEX_SIZE_64);//���َq
	Draw::LoadImageW(L"choco.png", 9, TEX_SIZE_64);//���َq
	Draw::LoadImageW(L"gumy.png", 10, TEX_SIZE_64);//���َq
	Draw::LoadImageW(L"cake.png", 11, TEX_SIZE_64);//���َq

	Draw::LoadImageW(L"upstage.png", 30, TEX_SIZE_64);//�K�i
	
	

	//���X�쐬
	CObjRisu* objr = new CObjRisu();
	Objs::InsertObj(objr, OBJ_RISU, 12);

	//BigCake�I�u�W�F�N�g�쐬
	CObjBigCake* objz = new CObjBigCake();
	Objs::InsertObj(objz, OBJ_BIG_CAKE, 20);

	//�L�����f�B
	CObjCandy* objc;
	objc = new CObjCandy(180, 80);
	Objs::InsertObj(objc, OBJ_CANDY, 10);

	//Cookie�I�u�W�F�N�g�쐬
	CObjCookie* objC;
	objC = new CObjCookie(180, 130);
	Objs::InsertObj(objC, OBJ_COOKIE, 10);

	//Donatu�I�u�W�F�N�g�쐬
	CObjDonatu* objd;
	objd = new CObjDonatu(180, 180);
	Objs::InsertObj(objd, OBJ_DONATU, 11);

	//Gummy�I�u�W�F�N�g�쐬
	CObjGummy* objg;
	objg = new CObjGummy(180, 230);
	Objs::InsertObj(objg, OBJ_GUMMY, 13);

	//Choco�I�u�W�F�N�g�쐬
	CObjChoco* obj_c;
	obj_c = new CObjChoco(180, 280);
	Objs::InsertObj(obj_c, OBJ_CHOCO, 14);

	//���K�i�쐬
	CObjupstage0* obju = new CObjupstage0();
	Objs::InsertObj(obju, OBJ_UPSTAGE0, 18);
	
	//�������CObjDescription��\�����Ă܂�
	CObjDescription* obj = new CObjDescription();
	Objs::InsertObj(obj, OBJ_DESCRIPTION, 10);
}
//���s�����\�b�h
void CSceneDescription::Scene() {

}