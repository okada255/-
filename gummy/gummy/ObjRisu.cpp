#include"GameL/DrawTexture.h"
#include"GameL/SceneObjManager.h"
#include"GameL/WinInputs.h"
#include"GameL/HitBoxManager.h"

#include"ObjRisu.h"
#include"GameHead.h"

using namespace GameL;

void CObjRisu::Init()
{
	m_x = 100;
	m_y = (600 / 2) - 16;
	m_vx = 0.0f;
	m_vy = 0.0f;

	//当たり判定
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_PLAYER, OBJ_RISU, 1);
}
void CObjRisu::Action()
{

	m_vx = 0.0f;
	m_vy = 0.0f;

	//キーの入力方向にベクトルの速度を入れる
	if(Input::GetVKey(VK_RIGHT) == true)
	{
		m_vx += 1.0f;
	}

	if(Input::GetVKey(VK_LEFT) == true)
	{
		m_vx -= 1.0f;
	}

	if(Input::GetVKey(VK_UP) == true)
	{
		m_vy -= 1.0f;
	}

	if(Input::GetVKey(VK_DOWN) == true)
	{
		m_vy += 1.0f;
	}

	if(m_x > 800.0f)
	{
		m_x = 0.0f;//原点回帰
	}

	float r = 0.0f;
	r = m_vx * m_vx + m_vy * m_vy;
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
	m_x += m_vx;
	m_y += m_vy;

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

	//HitBoxの内容更新
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);
}

void CObjRisu::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	//切り取り位置
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 108.0f;
	src.m_bottom = 108.0f;

	//表示
	dst.m_top = 0.0f+ m_y;
	dst.m_left = 0.0f+ m_x;
	dst.m_right = 32.0f + dst.m_left;
	dst.m_bottom = 32.0f + dst.m_top;

	//０番目に登録したグラフィックをもとにsrc.dst.cの情報をもとに描画
	Draw::Draw(2, &src, &dst, c, 0.0f);
}