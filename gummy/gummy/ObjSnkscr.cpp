#include"GameHead.h"
#include"GameL/WinInputs.h"
#include"GameL/HitBoxManager.h"
#include"ObjBigCake.h"
#include"GameL/DrawTexture.h"
#include"GameL/SceneObjManager.h"
#include "GameL\Audio.h"
#include"GameL/UserData.h"

using namespace GameL;

CObjSnkscr::CObjSnkscr(float x, float y)
{
	m_x = x;
	m_y = y;
}
void CObjSnkscr::Init()
{

}

void CObjSnkscr::Action()
{
	
	
}


void CObjSnkscr::Draw()
{
	// �`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 714.0f;
	src.m_bottom = 869.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = m_y;/*300.0f;*/
	dst.m_left = m_x;//550.0f;
	dst.m_right = dst.m_left + 210.5f;
	dst.m_bottom = dst.m_top + 210.5f;

	//�`��
	Draw::Draw(20, &src, &dst, c, 0.0f);
}