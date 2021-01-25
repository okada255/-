//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include"GameL/SceneObjManager.h"
#include"GameHead.h"
#include"GameL/UserData.h"
#include"GameL/DrawTexture.h"
#include"GameL/DrawFont.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include"SceneMap2C.h"
#include"ObjBlock.h"
#include"ObjCookie.h"
#include"ObjCandy.h"
#include"ObjChoco.h"
#include"ObjDonatu.h"
#include"ObjGummy.h"
#include"ObjRisu.h"
#include"ObjTitle.h"
#include"ObjGameClear.h"
#include"ObjBackGround.h"
#include"Objupstage2.h"
#include"ObjTime.h"
#include"GameL/Audio.h"

//�R���X�g���N�^
CSceneMap2C::CSceneMap2C()
{

}

//�f�X�g���N�^
CSceneMap2C::~CSceneMap2C()
{


}

//���������\�b�h
void CSceneMap2C::InitScene()
{
	//FONT�쐬
	Font::SetStrTex(L"0123456789���b");
	Font::SetStrTex(L"0123456789g");

	//�O���f�[�^�̓ǂݍ��݁i�X�e�[�W���j
	unique_ptr<wchar_t> p;//�X�e�[�W���|�C���^�[
	int size;             //�X�e�[�W���̑傫��
	int map[32][32];
	p = Save::ExternalDataOpen(L"MAP2.csv", &size);//�O���f�[�^�ǂݍ���

	int count = 1;
	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);
			map[i][j] = w;
			count += 2;
		}
	}

	Draw::LoadImageW(L"Block.png", 1, TEX_SIZE_64);
	Draw::LoadImageW(L"risu(2).png", 2, TEX_SIZE_128);//���X
	Draw::LoadImageW(L"donatu.png", 3, TEX_SIZE_64);
	Draw::LoadImageW(L"candy.png", 4, TEX_SIZE_64);
	Draw::LoadImageW(L"cookie.png", 5, TEX_SIZE_64);
	Draw::LoadImageW(L"choco.png", 6, TEX_SIZE_64);
	Draw::LoadImageW(L"gumy.png", 7, TEX_SIZE_64);
	Draw::LoadImageW(L"cake.png", 8, TEX_SIZE_64);

	Draw::LoadImageW(L"upstage.png", 30, TEX_SIZE_64);
	//Draw::LoadImageW(L"Back irasuto.png", 50, TEX_SIZE_64);
	//Draw::LoadImageW(L"�������L�����f�B�[.png", 57, TEX_SIZE_256);
	Draw::LoadImageW(L"�V���v��1.png", 57, TEX_SIZE_64);

	Audio::LoadAudio(0, L"Map.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(1, L"Item.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(2, L"upstage.wav", SOUND_TYPE::EFFECT);
	//�^�C��������
	m_time = 0;
	//Block�I�u�W�F�N�g�쐬
	CObjBlock* objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 9);

	//�^�C���쐬
	CObjTime* objt = new CObjTime();
	Objs::InsertObj(objt, OBJ_TIME, 16);

	//�X�R�A�쐬
	CObjScore* objs = new CObjScore();
	Objs::InsertObj(objs, OBJ_SCORE, 17);

	//�w�i�I�u�W�F�N�g����
	CObjBackGround* back = new CObjBackGround();
	Objs::InsertObj(back, OBJ_BACKGROUND, 1);

	//���X�쐬
	CObjRisu* objr = new CObjRisu();
	Objs::InsertObj(objr, OBJ_RISU, 12);

	//���K�i�쐬
	CObjupstage2* objU = new CObjupstage2(555, 460);
	Objs::InsertObj(objU, OBJ_UPSTAGE, 18);
}

//���s�����\�b�h
void CSceneMap2C::Scene()
{
	m_time++;
	if (m_time == 1)
	{
		Audio::Start(0);

		////�L�����f�B
		CObjCandy* objc;
		objc = new CObjCandy(250, 50);
		Objs::InsertObj(objc, OBJ_CANDY, 10);

		objc = new CObjCandy(520, 300);
		Objs::InsertObj(objc, OBJ_CANDY, 10);

		objc = new CObjCandy(150, 550);
		Objs::InsertObj(objc, OBJ_CANDY, 10);

		objc = new CObjCandy(450, 550);
		Objs::InsertObj(objc, OBJ_CANDY, 10);

		////Cookie�I�u�W�F�N�g�쐬
		CObjCookie* objC;
		objC = new CObjCookie(50, 50);
		Objs::InsertObj(objC, OBJ_COOKIE, 10);

		objC = new CObjCookie(540, 50);
		Objs::InsertObj(objC, OBJ_COOKIE, 10);

		objC = new CObjCookie(200, 285);
		Objs::InsertObj(objC, OBJ_COOKIE, 10);

		objC = new CObjCookie(50, 540);
		Objs::InsertObj(objC, OBJ_COOKIE, 10);

		objC = new CObjCookie(400, 500);
		Objs::InsertObj(objC, OBJ_COOKIE, 10);

		//Donatu�I�u�W�F�N�g�쐬
		CObjDonatu* objd;
		objd = new CObjDonatu(340, 100);
		Objs::InsertObj(objd, OBJ_DONATU, 11);

		//Gummy�I�u�W�F�N�g�쐬
		CObjGummy* objg;
		objg = new CObjGummy(440, 50);
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(210, 175);
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(300, 200);
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(40, 400);
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		//Choco�I�u�W�F�N�g�쐬
		CObjChoco* obj_c;
		obj_c = new CObjChoco(120, 150);
		Objs::InsertObj(obj_c, OBJ_CHOCO, 14);

		obj_c = new CObjChoco(510, 150);
		Objs::InsertObj(obj_c, OBJ_CHOCO, 14);

		obj_c = new CObjChoco(400, 200);
		Objs::InsertObj(obj_c, OBJ_CHOCO, 14);

		obj_c = new CObjChoco(420, 340);
		Objs::InsertObj(obj_c, OBJ_CHOCO, 14);

		obj_c = new CObjChoco(75, 480);
		Objs::InsertObj(obj_c, OBJ_CHOCO, 14);

		obj_c = new CObjChoco(150, 450);
		Objs::InsertObj(obj_c, OBJ_CHOCO, 14);

		//�̈�O���َq�E�����Ȃ���
		obj_c = new CObjChoco(610, 360);
		Objs::InsertObj(obj_c, OBJ_CHOCO, 10);

		objg = new CObjGummy(610, 300);
		Objs::InsertObj(objg, OBJ_GUMMY, 10);

		objd = new CObjDonatu(610, 420);
		Objs::InsertObj(objd, OBJ_DONATU, 10);

		objC = new CObjCookie(610, 390);
		Objs::InsertObj(objC, OBJ_COOKIE, 10);

		objc = new CObjCandy(610, 330);
		Objs::InsertObj(objc, OBJ_CANDY, 10);
	}
}