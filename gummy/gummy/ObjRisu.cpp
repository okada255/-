#include"GameL/DrawTexture.h"
#include"GameL/SceneObjManager.h"
#include"ObjRisu.h"
#include"GameHead.h"
#include"GameL/WinInputs.h"

using namespace GameL;

void CObjRisu::Init()
{
	m_x = 0;
	m_y = 0;
}

void CObjRisu::Action()
{

	if (Input::Getkey(VK_RIGHT) == true)
	{
		m_x += 1.0f;
	}

	if (Input::Getkey(VK_LEFT) == true)
	{
		m_x -= 1.0f;
	}

	if (Input::Getkey(VK_UP) == true)
	{
		m_y -= 1.0f;
	}

	if (Input::Getkey(VK_DOWN) == true)
	{
		m_y += 1.0f;
	}

	float r = 0.0f;
	r = m_vx = *m_vx + m_vy * m_vy;
	r = sqrt(r);

	if (r == 0.0f)
	{
		;
	}
	else
	{
		m_vx = 1.0f / r * m_vx;
		m_vy = 1.0f / r * m_vy;
	}

	//移動ベクトルを座標に加算
	m_x = m_vx;
	m_y = m_vy;

	//領域外に行かない
	if (m_x + 32.0f > 800.0f)
	{
		m_x = 800.0f - 32.0f;
	}
	if (m_y + 32.0f > 600.0f)
	{
		m_y = 600.0f - 32.0f;
	}
	if (m_y < 0.0f)
	{
		m_y = 0.0f;
	}
	if (m_x < 0.0f)
	{
		m_x = 0.0f;
	}

}

void CObjRisu::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f }
	RECT_F src;
	RECT_F dst;

	//切り取り位置
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 32.0f;
	src.m_bottom = 32.0f;

	//表示
	src.m_top = 0.0f + m_y;
	src.m_left = 0.0f + m_x;
	src.m_right = 32.0f + m_x;
	src.m_bottom = 32.0f + m_y;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}