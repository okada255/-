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
#include"SceneMap2.h"
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


//�R���X�g���N�^
CSceneMap2::CSceneMap2()
{

}

//�f�X�g���N�^
CSceneMap2::~CSceneMap2()
{


}

//���������\�b�h
void CSceneMap2::InitScene()
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
	Draw::LoadImageW(L"�E����1.png", 2, TEX_SIZE_128);//���X�E
	Draw::LoadImageW(L"������1.png", 3, TEX_SIZE_128);//���X��
	Draw::LoadImageW(L"���p1.png", 4, TEX_SIZE_128);//���X��
	Draw::LoadImageW(L"�O����1.png", 5, TEX_SIZE_128);//���X��
	Draw::LoadImageW(L"donatu.png", 6, TEX_SIZE_64);
	Draw::LoadImageW(L"candy.png", 7, TEX_SIZE_64);
	Draw::LoadImageW(L"cookie.png", 8, TEX_SIZE_64);
	Draw::LoadImageW(L"choco.png", 9, TEX_SIZE_64);
	Draw::LoadImageW(L"gumy.png", 10, TEX_SIZE_64);
	
	Draw::LoadImageW(L"upstage.png", 30, TEX_SIZE_64);
	Draw::LoadImageW(L"Back irasuto.png", 50, TEX_SIZE_64);

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
	CObjupstage2* obju2 = new CObjupstage2();
	Objs::InsertObj(obju2, OBJ_UPSTAGE2, 18);
}

//���s�����\�b�h
void CSceneMap2::Scene()
{
	m_time++;
	if (m_time == 1)
	{
		//�L�����f�B
		CObjCandy* objc;
		objc = new CObjCandy(350,50);
		Objs::InsertObj(objc, OBJ_CANDY, 10);

		objc = new CObjCandy(620, 300);
		Objs::InsertObj(objc, OBJ_CANDY, 10);

		objc = new CObjCandy(250, 550);
		Objs::InsertObj(objc, OBJ_CANDY, 10);

		objc = new CObjCandy(550, 550);
		Objs::InsertObj(objc, OBJ_CANDY, 10);

		//Cookie�I�u�W�F�N�g�쐬
		CObjCookie* objC;
		objC = new CObjCookie(150, 50);
		Objs::InsertObj(objC, OBJ_COOKIE, 10);

		objC = new CObjCookie(640, 50);
		Objs::InsertObj(objC, OBJ_COOKIE, 10);

		objC = new CObjCookie(300, 285);
		Objs::InsertObj(objC, OBJ_COOKIE, 10);

		objC = new CObjCookie(150,540);
		Objs::InsertObj(objC, OBJ_COOKIE, 10);

		objC = new CObjCookie(500,500);
		Objs::InsertObj(objC, OBJ_COOKIE, 10);

		//Donatu�I�u�W�F�N�g�쐬
		CObjDonatu* objd;
		objd = new CObjDonatu(440, 100);
		Objs::InsertObj(objd, OBJ_DONATU, 11);

		//Gummy�I�u�W�F�N�g�쐬
		CObjGummy* objg;
		objg = new CObjGummy(540, 50);
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(310,175);
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(400, 200);
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(140, 400);
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		//Choco�I�u�W�F�N�g�쐬
		CObjChoco* obj_c;
		obj_c = new CObjChoco(220,150);
		Objs::InsertObj(obj_c, OBJ_CHOCO, 14);

		obj_c = new CObjChoco(610, 150);
		Objs::InsertObj(obj_c, OBJ_CHOCO, 14);

		obj_c = new CObjChoco(500, 200);
		Objs::InsertObj(obj_c, OBJ_CHOCO, 14);

		obj_c = new CObjChoco(520, 340);
		Objs::InsertObj(obj_c, OBJ_CHOCO, 14);

		obj_c = new CObjChoco(175, 480);
		Objs::InsertObj(obj_c, OBJ_CHOCO, 14);

		obj_c = new CObjChoco(250, 450);
		Objs::InsertObj(obj_c, OBJ_CHOCO, 14);
	}
}