//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include"GameL/SceneObjManager.h"
#include"GameHead.h"
#include"GameL/UserData.h"
#include"GameL/DrawTexture.h"

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

	Draw::LoadImageW(L"Block.png", 1, TEX_SIZE_512);
	Draw::LoadImageW(L"Donatu.png", 1, TEX_SIZE_64);

	//Block�I�u�W�F�N�g�쐬
	CObjBlock* objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 9);

	////Candy�I�u�W�F�N�g�쐬
	//CObjCandy* objb = new CObjCandy();
	//Objs::InsertObj(objb, OBJ_CANDY, 9);

	////Cookie�I�u�W�F�N�g�쐬
	//CObjCookie* objb = new CObjCookie();
	//Objs::InsertObj(objb, OBJ_COOKIE, 9);

	////Donatu�I�u�W�F�N�g�쐬
	//CObjDonatu* objb = new CObjDonatu();
	//Objs::InsertObj(objb, OBJ_DONATU, 9);

	////Choco�I�u�W�F�N�g�쐬
	//CObjChoco* objb = new CObjChoco();
	//Objs::InsertObj(objb, OBJ_CANDY, 9);

	////Gummy�I�u�W�F�N�g�쐬
	//CObjGummy* objb = new CObjGummy();
	//Objs::InsertObj(objb, OBJ_GUMMY, 9);

	////���X�쐬
	//CObjRisu* objb = new CObjRisu();
	//Objs::InsertObj(objb, OBJ_RISU, 9);
}

//���s�����\�b�h
void CSceneMain::Scene()
{

}