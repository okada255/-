//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawTexture.h"
#include"GameL/SceneManager.h"
#include"GameL/WinInputs.h"
#include"GameHead.h"
#include"ObjScore.h"
#include"GameL/DrawFont.h"
#include"GameL/UserData.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjScore::Init()
{
	m_gram = 0;
	m_flag_gram = false;

}

//�A�N�V����
void CObjScore::Action()
{
	m_gram = 0;
	if (ELEMENT_ITEM == false)
	{
		;
	}
	m_gram = 0;
	if (OBJ_TIME == false)
	{
		;
	}

}

//�h���[
void CObjScore::Draw()
{


	float cc[4] = { 1.0f,1.0f,1.0f,1.0f };
	wchar_t str[128];
	swprintf_s(str, L"���_�F%dg", ((UserData*)Save::GetData())->m_point);
	Font::StrDraw(str, 697, 10, 18.2, cc);
}