//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawTexture.h"
#include"GameL/SceneManager.h"
#include"GameL/WinInputs.h"
#include"GameHead.h"
#include"ObjTime.h"
#include"GameL/DrawFont.h"
#include"GameL/UserData.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

int Gtime=864000;
int m_time = 0;
//�C�j�V�����C�Y
void CObjTime::Init()
{

	m_flag_time = false;
}

//�A�N�V����
void CObjTime::Action()
{
		for (int i = 1; i <= 120; i++)
		{
			m_time++;
			Gtime--;

			if (Gtime == 0)
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
		Font::StrDraw(L"��������", 630, 10, 30, c);
	swprintf_s(str, L"%d", Gtime / 7200);

	Font::StrDraw(str, 670, 40, 50, c);
}

