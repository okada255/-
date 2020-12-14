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
#include"SceneMap1B.h"
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
#include"Objupstage.h"
#include"GameL/Audio.h"



//�R���X�g���N�^
CSceneMap1B::CSceneMap1B()
{

}

//�f�X�g���N�^
CSceneMap1B::~CSceneMap1B()
{


}

//���������\�b�h
void CSceneMap1B::InitScene()
{
	//FONT�쐬
	Font::SetStrTex(L"0123456789���b");
	Font::SetStrTex(L"0123456789g");

	//�O���f�[�^�̓ǂݍ��݁i�X�e�[�W���j
	unique_ptr<wchar_t> p;//�X�e�[�W���|�C���^�[
	int size;             //�X�e�[�W���̑傫��
	int map[32][32];
	p = Save::ExternalDataOpen(L"MAP1.csv", &size);//�O���f�[�^�ǂݍ���

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

	//Draw::LoadImageW(L"Back irasuto.png", 50, TEX_SIZE_64);
	Draw::LoadImageW(L"�ڌ̏Ⴕ��.png", 57, TEX_SIZE_64);
	Draw::LoadImageW(L"upstage.png", 30, TEX_SIZE_64);

	Audio::LoadAudio(0, L"Map.wav", SOUND_TYPE::BACK_MUSIC);

	Audio::Start(0);
	Audio::LoadAudio(1, L"Item.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(2, L"Upstage.wav", SOUND_TYPE::EFFECT);

	//�^�C��������
	m_time = 0;
	//Block�I�u�W�F�N�g�쐬
	CObjBlock* objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 9);

	//���X�쐬
	CObjRisu* objr = new CObjRisu();
	Objs::InsertObj(objr, OBJ_RISU, 12);

	//�^�C���쐬
	CObjTime* objt = new CObjTime();
	Objs::InsertObj(objt, OBJ_TIME, 16);

	//�X�R�A�쐬
	CObjScore* objs = new CObjScore();
	Objs::InsertObj(objs, OBJ_SCORE, 17);

	//�w�i�I�u�W�F�N�g����
	CObjBackGround* back = new CObjBackGround();
	Objs::InsertObj(back, OBJ_BACKGROUND, 1);

	//���K�i�쐬
	CObjupstage* obju = new CObjupstage(555, 130);
	Objs::InsertObj(obju, OBJ_UPSTAGE, 18);
}

//���s�����\�b�h
void CSceneMap1B::Scene()
{
	m_time++;
	if (m_time == 1)
	{
		////�L�����f�B
		CObjCandy* objc;
		objc = new CObjCandy(440, 50);
		Objs::InsertObj(objc, OBJ_CANDY, 10);

		objc = new CObjCandy(390, 220);
		Objs::InsertObj(objc, OBJ_CANDY, 10);

		////Cookie�I�u�W�F�N�g�쐬
		CObjCookie* objC;
		objC = new CObjCookie(118, 160);
		Objs::InsertObj(objC, OBJ_COOKIE, 10);

		objC = new CObjCookie(240, 168);
		Objs::InsertObj(objC, OBJ_COOKIE, 10);

		objC = new CObjCookie(50, 540);
		Objs::InsertObj(objC, OBJ_COOKIE, 10);

		objC = new CObjCookie(495, 350);
		Objs::InsertObj(objC, OBJ_COOKIE, 10);

		////Donatu�I�u�W�F�N�g�쐬
		CObjDonatu* objd;
		objd = new CObjDonatu(200, 40);
		Objs::InsertObj(objd, OBJ_DONATU, 11);

		objd = new CObjDonatu(380, 460);
		Objs::InsertObj(objd, OBJ_DONATU, 11);

		////Gummy�I�u�W�F�N�g�쐬
		CObjGummy* objg;
		objg = new CObjGummy(85, 430);
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(240, 420);
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(295, 538);
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(540, 532);
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(560, 240);
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(490, 470);
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(445, 25);
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(300, 299);
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		//Choco�I�u�W�F�N�g�쐬
		CObjChoco* obj_c;
		obj_c = new CObjChoco(50, 40);
		Objs::InsertObj(obj_c, OBJ_CHOCO, 14);

		obj_c = new CObjChoco(475, 165);
		Objs::InsertObj(obj_c, OBJ_CHOCO, 14);

		obj_c = new CObjChoco(190, 480);
		Objs::InsertObj(obj_c, OBJ_CHOCO, 14);

		obj_c = new CObjChoco(370, 350);
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