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
	Font::StrDraw(str, 600, 80, 35, cc);

	//�̈�O���َq
	swprintf_s(str, L"�F5g", ((UserData*)Save::GetData())->m_point);
	Font::StrDraw(str, 630, 300, 20, cc);
	swprintf_s(str, L"�F10g", ((UserData*)Save::GetData())->m_point);
	Font::StrDraw(str, 630, 330, 20, cc);
	swprintf_s(str, L"�F15g", ((UserData*)Save::GetData())->m_point);
	Font::StrDraw(str, 630, 360, 20, cc);
	swprintf_s(str, L"�F20g", ((UserData*)Save::GetData())->m_point);
	Font::StrDraw(str, 630, 390, 20, cc);
	swprintf_s(str, L"�F50g", ((UserData*)Save::GetData())->m_point);
	Font::StrDraw(str, 630, 420, 20, cc);


}