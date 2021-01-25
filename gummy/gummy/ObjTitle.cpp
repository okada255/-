#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include"SceneMap1.h"
#include "GameHead.h"
#include "ObjTitle.h"
#include"GameL/UserData.h"
#include"GameL/Audio.h"

using namespace GameL;

void CObjTitle::Init() {
	m_key_flag = false;
	m_mou_x = 0;
	m_mou_y = 0;
	m_mou_r = false;
	m_mou_l = false;
	m_time = false;

	//�Q�[�����s���Ĉ��̂�
	static bool init_point =false;
	if (init_point == false)
	{
		//�_����0�ɂ���
		((UserData*)Save::GetData())->m_point=0;
		((UserData*)Save::GetData())->Gtime = 0;
		//�����L���O������
		for (int i = 0; i < 16; i++)
		{
			((UserData*)Save::GetData())->m_ranking[i] = 0;
		}
		//���[�h
		Save::Open();//���t�H���_�[�uUserDate�v����f�[�^�����B
		
		//�_����0�ɂ���
		((UserData*)Save::GetData())->m_point = 0;

		init_point = true;
	}

	////���_���������L���O�ŉ���(�`�挗�O)�ɓo�^
	//((UserData*)Save::GetData())->m_ranking[15] = ((UserData*)Save::GetData())->m_point;

	////���_���������ɕ��ѕς�������
	//RankingSort(((UserData*)Save::GetData())->m_ranking);

	//�Q�[�������s���Ĉ��ڂ݈̂ȊO�A�����L���O���Z�[�u����
	if (init_point==true)
	{
		Save::Seve();//UserDate�̏��𓯃t�H���_�[�ɁuUserDate�v���쐬����
	}
	//�_����0�ɂ���
	((UserData*)Save::GetData())->m_point = 0;
}

void CObjTitle::Action() {

	if (Input::GetVKey(VK_RETURN) == true) {
		if (m_key_flag == true) {
			Scene::SetScene(new CSceneDescription());
			if (m_time == true) {
				CObjTime* objt = new CObjTime();
				Objs::InsertObj(objt, OBJ_TIME, 16);
				m_time = false;
			}
			else
			{
				m_time = false;
			}
			m_key_flag = false;
		}
	}
	else {
		m_key_flag = true;
	}

	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	//�}�E�X�̃{�^�����
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();

	//�}�E�X�̈ʒu�ƃN���b�N����ꏊ�œ����蔻��
	if (m_mou_x > 230 && m_mou_x < 450 && m_mou_y>400 && m_mou_x < 430)
	{
		//�}�E�X�̃{�^���������ꂽ�烁�C���Ɉڍs
		if (m_mou_r == true | m_mou_l == true)
		{
			Scene::SetScene(new CSceneDescription());
		}
	}

	////�����L���O���Z�b�g�̕����Ƃ̓����蔻��
	//if (m_mou_x > CLICK_RESET_POS_X && m_mou_x < CLICK_RESET_POS_X + 100 &&
	//	m_mou_y>CLICK_RESET_POS_Y && m_mou_y < CLICK_RESET_POS_Y + 32)
	//{
	//	//�����L���O������
	//	for (int i = 0; i < 16; i++)
	//	{
	//		((UserData*)Save::GetData())->m_ranking[i] = 0;
	//	}	
	//}
	m_mou_r = false;
	m_mou_l = false;
}

void CObjTitle::Draw() {
	//�`��J���[��� R G B A
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"GUMMY", 220, 200, 150, c);


	////�����L���O
	//Font::StrDraw(L"�����L���O",RANKING_POS_X, RANKING_POS_Y, RANKING_FONT_SIZE,c );
	//
	//for(int i = 0;i<RANKING_SCORE_MAX;i++)
	//{
	//	wchar_t str[STR_MAX];
	//	swprintf_s(str,L"%2d��%12d�ʓ_",i+SCORE_INIT,(i+SCORE_INIT)*SCORE_POINT_MAX);
	//	Font::StrDraw(str,SCORE_POS_X,SCORE_POS_Y+SCORE_INTERVAL*i,SCORE_FONT_SIZE,c);
	//}

	Font::StrDraw(L"Game Start ", 320, 380, 32, c);
	Font::StrDraw(L" Push [Enter]Key ", 260, 430, 32, c);

	//Font::StrDraw(L"��ClickReset", 600, 380, 16, c);

	

	//RECT_F src;//�`�挳�؂���ʒu
	//RECT_F dst;//�`���\���ʒu

}

void CObjTitle::RankingSort(int rank[16])
{
	//�l�����p�ϐ�
	int w;

	//�o�u���\�[�g
	for (int i = 0; i < 15; i++)
	{
		for (int j = i+1; i < 16; i++)
		{
			if (rank[i]<rank[i])
			{
				//�l������
				w = rank[i];
				rank[i] = rank[j];
				rank[j]=w;
			}
		}
	}
}