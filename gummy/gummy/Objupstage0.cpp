#include"GameL/DrawTexture.h"
#include"GameL/SceneObjManager.h"
#include"Objupstage0.h"
#include"GameHead.h"
#include"GameL/WinInputs.h"
#include"GameL/HitBoxManager.h"
#include"GameL/Audio.h"
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

using namespace GameL;

void CObjupstage0::Init()
{
	m_x = 660;
	m_y = 100;
	Hits::SetHitBox(this, m_x, m_y, 26.25, 26.25, ELEMENT_ITEM, OBJ_UPSTAGE0, 30);
}

void CObjupstage0::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	//��l���ƐڐG���Ă��邩���ׂ�
	if (hit->CheckObjNameHit(OBJ_RISU) != nullptr)
	{
		Audio::Start(2);
		this->SetStatus(false);
		srand(time(NULL));
		ai = rand() % 3;
		if (ai == 0)
		{
			Scene::SetScene(new CSceneMap1());
		}
		else if (ai == 1)
		{
			Scene::SetScene(new CSceneMap1B());
		}
		else if (ai == 2)
		{
			Scene::SetScene(new CSceneMap1C());
		}
	}
}

void CObjupstage0::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 499.0f;
	src.m_bottom = 499.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 100.0f;
	dst.m_left = 660.0f;
	dst.m_right = dst.m_left + 26.25f;
	dst.m_bottom = dst.m_top + 26.25f;

	//�`��
	Draw::Draw(30, &src, &dst, c, 0.0f);

	////�؂���ʒu�ݒ�
	//src.m_top = 0.0f;
	//src.m_left = 0.0f;
	//src.m_right = 1200.0f;
	//src.m_bottom = 800.0f;

	////�\���ʒu�̐ݒ�
	//dst.m_top = 0.0f;
	//dst.m_left = 0.0f;
	//dst.m_right = 800.0f;
	//dst.m_bottom = 600.0f;

	////�o�^�����O���t�B�b�N�����̏������Ƃɕ\��
	//Draw::Draw(52, &src, &dst, c, 0.0f);
}