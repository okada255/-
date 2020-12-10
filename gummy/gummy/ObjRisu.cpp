#include"GameL/DrawTexture.h"
#include"GameL/SceneObjManager.h"
#include"GameL/WinInputs.h"
#include"GameL/HitBoxManager.h"
#include"ObjRisu.h"
#include"GameHead.h"

using namespace GameL;

void CObjRisu::Init()
{
	//�����z�u
	m_px = 38.5;
	m_py = (600 / 2) - 16;

	m_vx = 0.0f;
	m_vy = 0.0f;
	m_posture = 0.0f;//�E����0.0f,������1.0f
	//float move = 1.0f;
	m_dash = 200;

	//�����蔻��
	Hits::SetHitBox(this, m_px, m_py, 23.00, 18.85, ELEMENT_PLAYER, OBJ_RISU, 1);
}
void CObjRisu::Action()
{
	//��l���̈ʒu���擾
	CObjRisu* risu = (CObjRisu*)Objs::GetObj(OBJ_RISU);
	float hx = risu->GetX();
	float hy = risu->GetY();

	m_vy = 0.0f;//�ړ��ϐ�
	m_vx = 0.0f;
	m_posture = 0.0f;//�E����0.0f,������1.0f

	m_ani_time = 0;
	m_ani_frame = 1;//�Î~�t���[���������ɂ���

	m_speed_power = 0.5f;//�ʏ푬�x
	//m_ani_max_time = 4;//�A�j���[�V�����Ԋu��

	//Z�L�[���͂ő��x�A�b�v
	if (Input::GetVKey('Z') == true)
	{
		m_dash--;
		if (m_dash >0)
		{
			//�_�b�V�����̑��x
			m_speed_power = 1.5f;
		}
		else
		{
			m_dash = 0;
		}

	}
	else
	{
		//�ʏ푬�x
		m_speed_power = 0.5f;
	}



	//�L�[�̓��͕����Ƀx�N�g���̑��x������
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vx += 1.0f;//m_vx
		m_vx += m_speed_power;
		m_posture = 0.0f;//�E�{�^�����������Ƃ��̕\�������C���X�g
		m_ani_time += 1;
	}

	else if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vx -= 1.0f;//m_vx
		m_vx -= m_speed_power;
		m_posture = 1.0f;//���{�^�����������Ƃ��̕\�������C���X�g
		m_ani_time += 1;
	}

	else if (Input::GetVKey(VK_UP) == true)
	{
		m_vy -= 1.0f;//m_vy
		m_vy -= m_speed_power;
		m_posture = 0.0f;//��{�^�����������Ƃ��̕\�������C���X�g
		m_ani_time += 1;
	}

	

	else if (Input::GetVKey(VK_DOWN) == true)
	{
		m_vy += 1.0f;//m_vy
		m_vy += m_speed_power;
		m_posture = 0.0f;//���{�^�����������Ƃ��̕\�������C���X�g
		m_ani_time += 1;
	}
	//
	if (Input::GetVKey(VK_RIGHT)==true && Input::GetVKey(VK_DOWN) == true)
	{
		m_vx += 0.5f;
		m_vy += 0.5f;
		m_vy += m_speed_power;
		m_vx += m_speed_power;
		m_posture = 0.0f;//���{�^�����������Ƃ��̕\�������C���X�g
		m_ani_time += 1;
	}

	if (Input::GetVKey(VK_RIGHT)==true && Input::GetVKey(VK_UP) == true)
	{
		m_vx += 0.5f;
		m_vy -= 0.5f;
		m_vy -= m_speed_power;
		m_vx += m_speed_power;
		m_posture = 0.0f;//���{�^�����������Ƃ��̕\�������C���X�g
		m_ani_time += 1;
	}

	if (Input::GetVKey(VK_LEFT)==true && Input::GetVKey(VK_DOWN) == true)
	{
		m_vx -= 0.5f;
		m_vy += 0.5f;
		m_vy += m_speed_power;
		m_vx -= m_speed_power;
		m_posture = 1.0f;//���{�^�����������Ƃ��̕\�������C���X�g
		m_ani_time += 1;
	}

	if (Input::GetVKey(VK_LEFT)==true && Input::GetVKey(VK_UP) == true)
	{
		m_vx -= 0.5f;
		m_vy -= 0.5f;
		m_vy -= m_speed_power;
		m_vx -= m_speed_power;
		m_posture = 1.0f;//���{�^�����������Ƃ��̕\�������C���X�g
		m_ani_time += 1;
	}


	else
	{
		m_ani_frame = 1; //�L�[���͂��Ȃ��ꍇ�Î~�t���[���ɂ���
		m_ani_time = 0;
	}

	//�A�j���[�V����
	/*if (m_ani_time > m_ani_max_time)
	{
		m_ani_frame = 1;
		m_ani_time = 0;
	}

	if (m_ani_time == 4)
	{
		m_ani_frame = 0;
	}*/

	//�ʒu�̍X�V
	m_px += m_vx;
	m_py += m_vy;

	if (m_px > 800.0f)
	{
		m_px = 0.0f;//���_��A
	}

	float r = 0.0f;
	r = m_vx * m_vx + m_vy * m_vy;
	r = sqrt(r);

	if (r == 0.0f)
	{
		;
	}
	else
	{
		m_vx = 1.0f / r * m_vx;
		m_vy = 1.0f / r * m_vy;
	}

	//�ړ��x�N�g�������W�ɉ��Z
	m_px += m_vx;
	m_py += m_vy;

	//�̈�O�ɍs���Ȃ�
	if (m_px + 32.0f > 800.0f)
	{
		m_px = 800.0f - 32.0f;
	}
	if (m_py + 32.0f > 600.0f)
	{
		m_py = 600.0f - 32.0f;
	}
	if (m_py < 0.0f)
	{
		m_py = 0.0f;
	}
	if (m_px < 0.0f)
	{
		m_px = 0.0f;
	}

	//HitBox�̓��e�X�V
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_px, m_py);//
}

void CObjRisu::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�؂���ʒu
	src.m_top = 0.0f;// 25.0f;
	src.m_left = 0.0f;// 17.0f;
	src.m_right = 128.0f;// 95.0f;
	src.m_bottom = 128.0f;// 70.0f;

	//�\��
	dst.m_top = 0.0f + m_py;
	dst.m_left = (30.0f *m_posture) + m_px;
	dst.m_right = (30.0 -30.0f * m_posture) + m_px;// dst.m_left;
	dst.m_bottom = 30.0f + m_py;// dst.m_top;

	//2�Ԗڂɓo�^�����O���t�B�b�N�����Ƃ�src.dst.c�̏������Ƃɕ`��
	Draw::Draw(2, &src, &dst, c, 0.0f); //���������Xl�D��x�R�����X
}