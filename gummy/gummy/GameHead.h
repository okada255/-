#pragma once

//�I�u�W�F�N�g�l�[��------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//�I�u�W�F�N�g������(�֎~)
	//�Q�[���Ŏg���I�u�W�F�N�g�̖��O
	//OBJ_�����ƕ\�L
	OBJ_CANDY,
	OBJ_CANDYUSO,
	OBJ_CHOCO,
	OBJ_CHOCOUSO,
	OBJ_COOKIE,
	OBJ_COOKIEUSO,
	OBJ_DONATU,
	OBJ_DONATUUSO,
	OBJ_GUMMY,
	OBJ_GUMMYUSO,
	OBJ_RISU,
	OBJ_BLOCK,
	OBJ_BIG_CAKE,
	OBJ_BIG_CAKEUSO,
	OBJ_TITLE,
	OBJ_GAME_CLEAR,
	OBJ_TIME,
	OBJ_SCORE,
	OBJ_GAME_OVER,
	OBJ_BACKGROUND,
	OBJ_UPSTAGE,
	OBJ_UPSTAGE2,
	OBJ_UPSTAGE0,
	OBJ_DESCRIPTION,
};
//------------------------------------------------

//�����蔻�葮��----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//�������� �S�Ă̑����Ɠ����蔻�肪���s�����
	//�ȉ��@�����������m�ł͓����蔻��͎��s����Ȃ�
	//�����͒ǉ��\�����A�f�o�b�N���̐F�͏����ݒ蕪��������
	ELEMENT_PLAYER,
	ELEMENT_ENEMY,
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,
};
//------------------------------------------------

//------------------------------------------------
//�Z�[�u�����[�h�ƃV�[���Ԃ̂���肷��f�[�^
struct UserData
{
	int mSeveData;	//�T���v���Z�[�u�f�[�^
	int m_point;
	int m_ranking[16];
};
//------------------------------------------------


//�Q�[�����Ŏg�p�����O���[�o���ϐ��E�萔�E��--



//------------------------------------------------
//�Q�[�����Ŏg�p����N���X�w�b�_------------------


//------------------------------------------------

//�Q�[���V�[���I�u�W�F�N�g�w�b�_------------------
#include"ObjGummy.h"
#include"ObjGummyuso.h"
#include"ObjChoco.h"
#include"ObjChocouso.h"
#include"ObjCookie.h"
#include"ObjCookieuso.h"
#include"ObjDonatu.h"
#include"ObjDonatuuso.h"
#include"ObjCandy.h"
#include"ObjCandyuso.h"
#include"ObjRisu.h"
#include"ObjBlock.h"
#include"ObjBigCake.h"
#include"ObjBigCakeuso.h"
#include"ObjTitle.h"
#include"ObjGameClear.h"
#include"ObjTime.h"
#include"ObjScore.h"
#include"ObjGameOver.h"
#include"ObjBackGround.h"
#include"Objupstage.h"

#include"Objupstage2.h"
#include"Objupstage0.h"


//#include"ObjRisuL.h"
//#include"ObjRisuR.h"
//#include"ObjRisuU.h"
//#include"ObjRisuD.h"

//------------------------------------------------

//�Q�[���V�[���N���X�w�b�_------------------------
#include"SceneMap1.h"
#include"SceneMap1B.h"
#include"SceneMap1C.h"
#include"SceneMap2.h"
#include"SceneMap2B.h"
#include"SceneMap2C.h"
#include"SceneMap3.h"
#include "SceneTitle.h"
#include "SceneGameClear.h"
#include"SceneGameOver.h"
#include"SceneDescription.h"
//-----------------------------------------------

//�V�[���X�^�[�g�N���X---------------------------
//�Q�[���J�n���̃V�[���N���X�o�^
#define SET_GAME_START CSceneTitle
//-----------------------------------------------