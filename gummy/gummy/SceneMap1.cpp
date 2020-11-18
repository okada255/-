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
#include"SceneMap1.h"
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



//�R���X�g���N�^
CSceneMap1::CSceneMap1()
{

}

//�f�X�g���N�^
CSceneMap1::~CSceneMap1()
{


}

//���������\�b�h
void CSceneMap1::InitScene()
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
	Draw::LoadImageW(L"�E����.png", 2, TEX_SIZE_128);//���X
	Draw::LoadImageW(L"������.png", 3, TEX_SIZE_128);//���X
	Draw::LoadImageW(L"���p(1).png", 4, TEX_SIZE_128);//���X
	Draw::LoadImageW(L"�O�������X.png", 5, TEX_SIZE_128);//���X
	Draw::LoadImageW(L"donatu.png", 6, TEX_SIZE_64);
	Draw::LoadImageW(L"candy.png", 7, TEX_SIZE_64);
	Draw::LoadImageW(L"cookie.png", 8, TEX_SIZE_64);
	Draw::LoadImageW(L"choco.png", 9, TEX_SIZE_64);
	Draw::LoadImageW(L"gumy.png", 10, TEX_SIZE_64);
	Draw::LoadImageW(L"cake.png", 11, TEX_SIZE_64);

	Draw::LoadImageW(L"Back irasuto.png", 50, TEX_SIZE_64);

	Draw::LoadImageW(L"upstage.png", 30, TEX_SIZE_64);

	//�^�C��������
	m_time = 0;
	//Block�I�u�W�F�N�g�쐬
	CObjBlock* objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 9);

	////Donatu�I�u�W�F�N�g�쐬
	CObjDonatu* objd = new CObjDonatu();
	Objs::InsertObj(objd, OBJ_DONATU, 11);


	////Gummy�I�u�W�F�N�g�쐬
	CObjGummy* objg = new CObjGummy();
	Objs::InsertObj(objg, OBJ_GUMMY, 13);

	//���X�쐬
	CObjRisu* objr = new CObjRisu();
	Objs::InsertObj(objr, OBJ_RISU, 12);

	////BigCake�I�u�W�F�N�g�쐬
	CObjBigCake* objz = new CObjBigCake();
	Objs::InsertObj(objz, OBJ_BIG_CAKE, 20);

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
	CObjupstage* obju = new CObjupstage();
	Objs::InsertObj(obju, OBJ_UPSTAGE, 18);

	//�L�����f�B
	CObjCandy* objc = new CObjCandy(300, 500);
	Objs::InsertObj(objc, OBJ_CANDY, 10);
	
}

//���s�����\�b�h
void CSceneMap1::Scene()
{
	m_time++;
	if (m_time == 1)
	{
		//�L�����f�B
		CObjCandy* objc;
		objc = new CObjCandy(200, 500);
		Objs::InsertObj(objc, OBJ_CANDY, 10);

		//Cookie�I�u�W�F�N�g�쐬
		CObjCookie* objC = new CObjCookie(200, 450);
		Objs::InsertObj(objC, OBJ_COOKIE, 10);

	}
}