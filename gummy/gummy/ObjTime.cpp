//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawTexture.h"
#include"GameL/SceneManager.h"
#include"GameL/WinInputs.h"
#include"GameHead.h"
#include"ObjTime.h"
#include"GameL/DrawFont.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjTime::Init()
{
	m_time = 500*60*60;
	m_flag_time = false;
}

//�A�N�V����
void CObjTime::Action()
{
	m_time--;
	
}

//�h���[
void CObjTime::Draw()
{
	//m_time����b�������߂�
	int minute; //��
	int second =500; //�b
	
	
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	wchar_t str[128];
	
	
	if (second > 0)
		swprintf_s(str, L"%d",second);

	Font::StrDraw(str, 10, 10, 20, c);
}

