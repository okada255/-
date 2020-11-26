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
	m_time = 120*7200;//���Ԓ���
	m_flag_time = false;//���Ԍv��
}

//�A�N�V����
void CObjTime::Action()
{
	//�������Ԃ�120�b�Ƃ��ꂪ�����Ă����d�g��
	for (int i = 1; i <= 120; i++)
	{
		m_time--;

		//�������ԏI�����ɔ��f�������
		if (m_time == 0)
		{
			Scene::SetScene(new CSceneGameOver());
		}
	}
}

//�h���[
void CObjTime::Draw()
{
	//m_time����b�������߂�
	//int minute; //��
	int second =500; //�b
	
	
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	wchar_t str[128];//128�������̕�����̃X�y�[�X
	
	
	if (second > 0)
		Font::StrDraw(L"��������", 630, 10, 30, c);//�\�����e
	swprintf_s(str, L"%d", m_time / 7200);//�����̕�����

	Font::StrDraw(str, 670, 40, 50, c);//�\���ʒu
}

