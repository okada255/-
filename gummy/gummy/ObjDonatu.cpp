#include"GameL/DrawTexture.h"
#include"GameL/SceneObjManager.h"
#include"ObjDonatu.h"
#include"GameHead.h"
#include"GameL/WinInputs.h"
#include"GameL/HitBoxManager.h"

using namespace GameL;

CObjDonatu::CObjDonatu(float x, float y)
{
	m_x = x;
	m_y = y;
}


void CObjDonatu::Init()
{
	Hits::SetHitBox(this, m_x, m_y, 18.75, 18.75, ELEMENT_ITEM, OBJ_DONATU, 3);
}

void CObjDonatu::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	//��l���ƐڐG���Ă��邩���ׂ�
	if (hit->CheckObjNameHit(OBJ_RISU) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

	}
}

void CObjDonatu::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = m_y;
	dst.m_left = m_x;
	dst.m_right = dst.m_left + 18.75f;
	dst.m_bottom = dst.m_top + 18.75f;

	//�`��
	Draw::Draw(6, &src, &dst, c, 0.0f);
}