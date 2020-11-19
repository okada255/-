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




//�R���X�g���N�^
CSceneMap3::CSceneMap3()
{

}

//�f�X�g���N�^
CSceneMap3::~CSceneMap3()
{


}

//���������\�b�h
void CSceneMap3::InitScene()
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
	Draw::LoadImageW(L"risu(2).png", 2, TEX_SIZE_128);//���X
	Draw::LoadImageW(L"gumy.png", 7, TEX_SIZE_64);
	Draw::LoadImageW(L"cake.png", 8, TEX_SIZE_64);

	Draw::LoadImageW(L"Back irasuto.png", 50, TEX_SIZE_64);



	//�^�C��������
	m_time = 0;
	//Block�I�u�W�F�N�g�쐬
	CObjBlock* objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 9);

	//���X�쐬
	CObjRisu* objr = new CObjRisu();
	Objs::InsertObj(objr, OBJ_RISU, 12);

	////BigCake�I�u�W�F�N�g�쐬
	//CObjBigCake* objz = new CObjBigCake();
	//Objs::InsertObj(objz, OBJ_BIG_CAKE, 20);

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
void CSceneMap3::Scene()
{
	m_time++;
	if (m_time == 1)
	{
		


	//Gummy�I�u�W�F�N�g�쐬
		CObjGummy* objg;
		objg = new CObjGummy(140, 50);//C-3
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(140, 440);//C-25
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(140, 520);//C-30
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(160, 165);//D-10
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(195, 330);//E-20
		Objs::InsertObj(objg, OBJ_GUMMY, 13);


		objg = new CObjGummy(235, 165);//H-10
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(245, 270);//I-16
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(245, 415);//I-24
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(315, 65);//L-4
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(330, 285);//M-17
		Objs::InsertObj(objg, OBJ_GUMMY, 13);


		objg = new CObjGummy(340, 435);//N-25
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(385, 225);//P-13
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(385, 520);//P-29
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(425, 20);//R-2
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(425, 180);//R-11
		Objs::InsertObj(objg, OBJ_GUMMY, 13);


		objg = new CObjGummy(485, 255);//U-15
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(485, 415);//U-24
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(510, 535);//V-30
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(490, 90);//V-5
		Objs::InsertObj(objg, OBJ_GUMMY, 13);

		objg = new CObjGummy(505, 50);//W-3
		Objs::InsertObj(objg, OBJ_GUMMY, 13);


		CObjBigCake* objz;
		objz = new CObjBigCake(560, 240);//AB-15
		Objs::InsertObj(objz, OBJ_BIG_CAKE, 50);
		//////BigCake�I�u�W�F�N�g�쐬
		//CObjBigCake* objz = new CObjBigCake();
		//Objs::InsertObj(objz, OBJ_BIG_CAKE, 50);

	}
}