#include"GameL/DrawTexture.h"
#include"GameL/SceneObjManager.h"
#include"Objupstage.h"
#include"GameHead.h"
#include"GameL/WinInputs.h"
#include"GameL/HitBoxManager.h"


using namespace GameL;

void CObjupstage::Init()
{

}

void CObjupstage::Action()
{
	//CHitBox* hit = Hits::GetHitBox(this);
	//

	////��l���ƐڐG���Ă��邩���ׂ�
	//if (hit->CheckObjNameHit(OBJ_RISU) != nullptr)
	//{
	//	this->SetStatus(false);
	//	Hits::DeleteHitBox(this);
	//}
}

void CObjupstage::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 696.0f;
	src.m_bottom = 696.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 200.0f;
	dst.m_left = 600.0f;
	dst.m_right = dst.m_left + 18.75f;
	dst.m_bottom = dst.m_top + 18.75f;

	//�`��
	Draw::Draw(30, &src, &dst, c, 0.0f);
}
