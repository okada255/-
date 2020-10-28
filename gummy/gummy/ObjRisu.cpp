#include"GameL/DrawTexture.h"
#include"GameL/SceneObjManager.h"
#include"GameL/WinInputs.h"
#include"GameL/HitBoxManager.h"

#include"ObjRisu.h"
#include"GameHead.h"

using namespace GameL;

void CObjRisu::Init()
{
	m_px = 100;
	m_py = (600 / 2) - 16;
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_posture = 0.0f;//�E����0.0f,������1.0f

	//�����蔻��
	Hits::SetHitBox(this, m_px, m_py, 32, 32, ELEMENT_PLAYER, OBJ_RISU, 1);
}
void CObjRisu::Action()
{
	m_vx = 0.0f;
	m_vy = 0.0f;

	//�L�[�̓��͕����Ƀx�N�g���̑��x������
	if(Input::GetVKey(VK_RIGHT) == true)
	{
		m_vx += 0.1f;
		m_posture = 1.0f;
	}

	if(Input::GetVKey(VK_LEFT) == true)
	{
		m_vx -= 0.1f;
		m_posture = 0.0f;
	}

	if(Input::GetVKey(VK_UP) == true)
	{
		m_vy -= 1.0f;
	}

	if(Input::GetVKey(VK_DOWN) == true)
	{
		m_vy += 1.0f;
	}

	//�ʒu�̍X�V
	m_px += m_vx;
	m_py += m_vy;

	if(m_px > 800.0f)
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
	hit->SetPos(m_px, m_py);
}

void CObjRisu::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	//�؂���ʒu
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 108.0f;
	src.m_bottom = 108.0f;

	//�\��
	dst.m_top = 0.0f+ m_py;
	dst.m_left = 0.0f+ m_px;
	dst.m_right = 32.0f + dst.m_left;
	dst.m_bottom = 32.0f + dst.m_top;

	//2�Ԗڂɓo�^�����O���t�B�b�N�����Ƃ�src.dst.c�̏������Ƃɕ`��
	Draw::Draw(2, &src, &dst, c, 0.0f);
}