#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include"SceneMap1.h"
#include "GameHead.h"
#include "ObjTitle.h"
#include"GameL/UserData.h"
#include"ObjDescription.h"

using namespace GameL;

void CObjDescription::Init() {
	m_key_flag = false;
	m_mou_x = 0;
	m_mou_y = 0;
	m_mou_r = false;
	m_mou_l = false;
}

void CObjDescription::Action() {
	if (Input::GetVKey(VK_RETURN) == true) {
		if (m_key_flag == true) {
			Scene::SetScene(new CSceneMap1());
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
			Scene::SetScene(new CSceneMap1());
		}
	}
}

void CObjDescription::Draw() {
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"�����َq�����Ɠ��_�����炦��I", 220, 200, 30, c);
	Font::StrDraw(L"��", 600, 250, 30, c);
	Font::StrDraw(L"�K�i��", 590, 50, 30, c);
	Font::StrDraw(L"��l���́u���X�v�N",80, 350, 20, c);
	Font::StrDraw(L"��,��,��,���L�[�œ��������", 80, 390, 20, c);
	Font::StrDraw(L"��", 140, 310, 20, c);
	

	Font::StrDraw(L"�K�i��i�ނ�EnterKey�������ƃQ�[�����n�܂��I", 0, 480, 35, c);
	Font::StrDraw(L"���َq���������I", 220, 530, 20, c);

	
}