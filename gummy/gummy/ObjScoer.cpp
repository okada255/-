//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawTexture.h"
#include"GameL/SceneManager.h"
#include"GameL/WinInputs.h"
#include"GameHead.h"
#include"ObjScore.h"
#include"GameL/DrawFont.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjScore::Init()
{
	m_flag_gram = false;
	m_gram = 1000 * 7200;
}

//�A�N�V����
void CObjScore::Action()
{
	if (ELEMENT_ITEM == false)
	{
		;
	}
}

//�h���[
void CObjScore::Draw()
{
	int minute; //��
	int second = 500; //�b


	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	wchar_t str[128];


	if (second > 0)
		swprintf_s(str, L"%d", m_gram / 7200);

	Font::StrDraw(str, 740, 10, 20, c);
}