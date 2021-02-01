#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameHead.h"
#include "ObjTitle.h"
#include"GameL/UserData.h"
#include"GameL/Audio.h"

using namespace GameL;

void CObjTitle::Init() {
	m_key_flag = false;

	//�Q�[�����s���Ĉ��̂�
	static bool init_point =false;
	if (init_point == false)
	{
		//�_����0�ɂ���
		((UserData*)Save::GetData())->m_point=0;
		((UserData*)Save::GetData())->Gtime = 0;
		
		//���[�h
		Save::Open();//���t�H���_�[�uUserDate�v����f�[�^�����B
		
		//�_����0�ɂ���
		((UserData*)Save::GetData())->m_point = 0;

		init_point = true;
	}

	//�Q�[�������s���Ĉ��ڂ݈̂ȊO�A�����L���O���Z�[�u����
	if (init_point==true)
	{
		Save::Seve();//UserDate�̏��𓯃t�H���_�[�ɁuUserDate�v���쐬����
	}
	//�_����0�ɂ���
	((UserData*)Save::GetData())->m_point = 0;

	((UserData*)Save::GetData())->Gtimehakaru = 871200;//���ԏ�����
}

void CObjTitle::Action() {

	if (Input::GetVKey(VK_RETURN) == true) {
		if (m_key_flag == true) {
			Scene::SetScene(new CSceneDescription());
			m_key_flag = false;
		}
	}
	else {
		m_key_flag = true;
	}


}

void CObjTitle::Draw() {
	//�`��J���[��� R G B A
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"GUMMY", 220, 200, 150, c);

	Font::StrDraw(L"Game Start ", 320, 380, 32, c);
	Font::StrDraw(L" Push [Enter]Key ", 260, 430, 32, c);


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