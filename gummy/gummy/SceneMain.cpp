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
#include"SceneMain.h"
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


//�R���X�g���N�^
CSceneMain::CSceneMain()
{

}

//�f�X�g���N�^
CSceneMain::~CSceneMain()
{


}

//���������\�b�h
void CSceneMain::InitScene()
{
	//FONT�쐬
	Font::SetStrTex(L"0123456789���b");
	Font::SetStrTex(L"0123456789g");

	//�O���f�[�^�̓ǂݍ��݁i�X�e�[�W���j
	unique_ptr<wchar_t> p;//�X�e�[�W���|�C���^�[
	int size;             //�X�e�[�W���̑傫��
	int map[32][32];
	p = Save::ExternalDataOpen(L"MAP3.csv", &size);//�O���f�[�^�ǂݍ���

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
	//Block�I�u�W�F�N�g�쐬
	CObjBlock* objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 9);

	////Candy�I�u�W�F�N�g�쐬
	CObjCandy* objc = new CObjCandy();
	Objs::InsertObj(objc, OBJ_CANDY, 10);

	////Cookie�I�u�W�F�N�g�쐬
	CObjCookie* objC = new CObjCookie();
	Objs::InsertObj(objC, OBJ_COOKIE, 15);

	////Donatu�I�u�W�F�N�g�쐬
	CObjDonatu* objd = new CObjDonatu();
	Objs::InsertObj(objd, OBJ_DONATU, 11);

	////Choco�I�u�W�F�N�g�쐬
	CObjChoco* obj_c = new CObjChoco();
	Objs::InsertObj(obj_c, OBJ_CANDY, 14);

	////Gummy�I�u�W�F�N�g�쐬
	CObjGummy* objg = new CObjGummy();
	Objs::InsertObj(objg, OBJ_GUMMY, 13);

	//���X�쐬
	CObjRisu* objr = new CObjRisu();
	Objs::InsertObj(objr, OBJ_RISU, 12);

	////BigCake�I�u�W�F�N�g�쐬
	CObjBigCake* objz = new CObjBigCake();
	Objs::InsertObj(objz, OBJ_BIG_CAKE, 50);

	//�^�C���쐬
	CObjTime* objt = new CObjTime();
	Objs::InsertObj(objt, OBJ_TIME, 16);

	//�X�R�A�쐬
	CObjScore* objs = new CObjScore();
	Objs::InsertObj(objs, OBJ_SCORE, 17);

	//�w�i�I�u�W�F�N�g����
	CObjBackGround* back = new CObjBackGround();
	Objs::InsertObj(back, OBJ_BACKGROUND, 1);
}

//���s�����\�b�h
void CSceneMain::Scene()
{
	m_time = 500 * 7200;
	for (int i = 1; i <= 120; i++)
	{
		m_time--;
	}
	if (m_time == 500)
	{
		CObjCandy* objc = new CObjCandy(500.0f,200);
		Objs::InsertObj(objc, OBJ_CANDY, 10);
	}

}