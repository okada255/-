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

	//�؂���ʒu�ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 256.0f;
	src.m_bottom = 256.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 600.0f;
	dst.m_bottom = 600.0f;

	//�o�^�����O���t�B�b�N�����̏������Ƃɕ\��
	Draw::Draw(53, &src, &dst, c, 0.0f);
}