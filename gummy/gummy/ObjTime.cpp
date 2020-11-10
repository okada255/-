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
	m_time = 500*7200;
	m_flag_time = false;
}

//�A�N�V����
void CObjTime::Action()
{
	for (int i = 1; i <= 500; i++)
	{
		m_time--;
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
	int minute; //��
	int second =500; //�b
	
	
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	wchar_t str[128];
	
	
	if (second > 0)
		swprintf_s(str, L"%d",m_time/7200);

	Font::StrDraw(str, 10, 10, 20, c);
}

