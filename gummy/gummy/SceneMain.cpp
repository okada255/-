//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include"GameL/SceneObjManager.h"
#include"GameL/GameHead.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include"SceneMain.h"
#include"GameL/GameHead.h"
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
	//Block�I�u�W�F�N�g�쐬
	CObjBlock* objb = new CObjBlock();
	Objs::InsertObj(objb, OBJ_BLOCK, 9);

	//Candy�I�u�W�F�N�g�쐬
	CObjCandy* objb = new CObjCandy();
	Objs::InsertObj(objb, OBJ_CANDY, 9);

	//Cookie�I�u�W�F�N�g�쐬
	CObjCookie* objb = new CObjCookie();
	Objs::InsertObj(objb, OBJ_COOKIE, 9);

	//Donatu�I�u�W�F�N�g�쐬
	CObjDonatu* objb = new CObjDonatu();
	Objs::InsertObj(objb, OBJ_DONATU, 9);

	//Choco�I�u�W�F�N�g�쐬
	CObjChoco* objb = new CObjChoco();
	Objs::InsertObj(objb, OBJ_CANDY, 9);

	//Gummy�I�u�W�F�N�g�쐬
	CObjGummy* objb = new CObjGummy();
	Objs::InsertObj(objb, OBJ_GUMMY, 9);
}

//���s�����\�b�h
void CSceneMain::Scene()
{

}