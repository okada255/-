//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawTexture.h"
#include"GameHead.h"

#include"ObjBackGround.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;



//�C�j�V�����C�Y
void CObjBackGround::Init()
{

}

//�A�N�V����
void CObjBackGround::Action()
{

}

//�h���[
void CObjBackGround::Draw()
{
	//�`��J���[��� R G B A
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu
	RECT_F src2;//�`���\���ʒu


	//�؂���ʒu�ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 800.0f;
	src.m_bottom = 600.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	//�؂���ʒu�ݒ�
	src2.m_top = 0.0f;
	src2.m_left = 0.0f;
	src2.m_right = 728.0f;
	src2.m_bottom = 485.0f;

	//�o�^�����O���t�B�b�N�����̏������Ƃɕ\��
	Draw::Draw(57, &src, &dst, c, 0.0f);
	//�o�^�����O���t�B�b�N�����̏������Ƃɕ\��
	Draw::Draw(63, &src2, &dst, c, 0.0f);
}