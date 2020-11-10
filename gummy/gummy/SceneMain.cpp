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
//#include"ObjRisu.h"
#include"ObjRisuR.h"
#include"ObjRisuL.h"
#include"ObjRisuU.h"
#include"ObjRisuD.h"
#include"ObjTitle.h"
#include"ObjGameClear.h"


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
	Draw::LoadImageW(L"�E����.png", 2, TEX_SIZE_128);//�E���X
	Draw::LoadImageW(L"������.png", 3, TEX_SIZE_128);//�����X
	Draw::LoadImageW(L"�O�������X.png", 4, TEX_SIZE_128);//�O�������X
	Draw::LoadImageW(L"������(1).png", 5, TEX_SIZE_128);//���������X
	Draw::LoadImageW(L"donatu.png",6, TEX_SIZE_64);
	Draw::LoadImageW(L"candy.png", 7, TEX_SIZE_64);
	Draw::LoadImageW(L"cookie.png",8, TEX_SIZE_64);
	Draw::LoadImageW(L"choco.png",9, TEX_SIZE_64);
	Draw::LoadImageW(L"gumy.png",10, TEX_SIZE_64);


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

	//���X�쐬�E	
	CObjRisuR* objr = new CObjRisuR();
	Objs::InsertObj(objr, OBJ_RISUR, 12);

	//���X�쐬��
	CObjRisuL* objr = new CObjRisuL();
	Objs::InsertObj(objr, OBJ_RISUL, 12);

	//���X�쐬��
	CObjRisuU* objr = new CObjRisuU();
	Objs::InsertObj(objr, OBJ_RISUU, 12);

	//���X�쐬��
	CObjRisuD* objr = new CObjRisuD();
	Objs::InsertObj(objr, OBJ_RISUD, 12);

	////���X�쐬
	//CObjRisu* objr = new CObjRisu();
	//Objs::InsertObj(objr, OBJ_RISU, 12);


	//�^�C���쐬
	CObjTime* objt = new CObjTime();
	Objs::InsertObj(objt, OBJ_TIME, 16);

	//�X�R�A�쐬
	CObjScore* objs = new CObjScore();
	Objs::InsertObj(objs, OBJ_SCORE, 17);
}

//���s�����\�b�h
void CSceneMain::Scene()
{

}