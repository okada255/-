#include"GameL/DrawTexture.h"
#include"GameL/SceneObjManager.h"
#include"GameL/WinInputs.h"
#include"GameL/HitBoxManager.h"
#include"ObjRisu.h"
#include"GameHead.h"

using namespace GameL;

void CObjRisu::Init()
{
	//初期配置
	m_px = 38.5;
	m_py = (600 / 2) - 16;

	m_vx = 0.0f;
	m_vy = 0.0f;
	m_posture = 0.0f;//右向き0.0f,左向き1.0f
	//float move = 1.0f;
	m_dash = 200;

	//当たり判定
	Hits::SetHitBox(this, m_px, m_py, 23.00, 18.85, ELEMENT_PLAYER, OBJ_RISU, 1);
}
void CObjRisu::Action()
{
	//主人公の位置を取得
	CObjRisu* risu = (CObjRisu*)Objs::GetObj(OBJ_RISU);
	float hx = risu->GetX();
	float hy = risu->GetY();

	m_vy = 0.0f;//移動変数
	m_vx = 0.0f;
	m_posture = 0.0f;//右向き0.0f,左向き1.0f

	m_ani_time = 0;
	m_ani_frame = 1;//静止フレームを初期にする

	m_speed_power = 0.5f;//通常速度
	//m_ani_max_time = 4;//アニメーション間隔幅

	//Zキー入力で速度アップ
	if (Input::GetVKey('Z') == true)
	{
		m_dash--;
		if (m_dash >0)
		{
			//ダッシュ時の速度
			m_speed_power = 1.5f;
		}
		else
		{
			m_dash = 0;
		}

	}
	else
	{
		//通常速度
		m_speed_power = 0.5f;
	}



	//キーの入力方向にベクトルの速度を入れる
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vx += 1.0f;//m_vx
		m_vx += m_speed_power;
		m_posture = 0.0f;//右ボタンを押したときの表示されるイラスト
		m_ani_time += 1;
	}

	else if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vx -= 1.0f;//m_vx
		m_vx -= m_speed_power;
		m_posture = 1.0f;//左ボタンを押したときの表示されるイラスト
		m_ani_time += 1;
	}

	else if (Input::GetVKey(VK_UP) == true)
	{
		m_vy -= 1.0f;//m_vy
		m_vy -= m_speed_power;
		m_posture = 0.0f;//上ボタンを押したときの表示されるイラスト
		m_ani_time += 1;
	}

	

	else if (Input::GetVKey(VK_DOWN) == true)
	{
		m_vy += 1.0f;//m_vy
		m_vy += m_speed_power;
		m_posture = 0.0f;//下ボタンを押したときの表示されるイラスト
		m_ani_time += 1;
	}
	//
	if (Input::GetVKey(VK_RIGHT)==true && Input::GetVKey(VK_DOWN) == true)
	{
		m_vx += 0.5f;
		m_vy += 0.5f;
		m_vy += m_speed_power;
		m_vx += m_speed_power;
		m_posture = 0.0f;//下ボタンを押したときの表示されるイラスト
		m_ani_time += 1;
	}

	if (Input::GetVKey(VK_RIGHT)==true && Input::GetVKey(VK_UP) == true)
	{
		m_vx += 0.5f;
		m_vy -= 0.5f;
		m_vy -= m_speed_power;
		m_vx += m_speed_power;
		m_posture = 0.0f;//下ボタンを押したときの表示されるイラスト
		m_ani_time += 1;
	}

	if (Input::GetVKey(VK_LEFT)==true && Input::GetVKey(VK_DOWN) == true)
	{
		m_vx -= 0.5f;
		m_vy += 0.5f;
		m_vy += m_speed_power;
		m_vx -= m_speed_power;
		m_posture = 1.0f;//下ボタンを押したときの表示されるイラスト
		m_ani_time += 1;
	}

	if (Input::GetVKey(VK_LEFT)==true && Input::GetVKey(VK_UP) == true)
	{
		m_vx -= 0.5f;
		m_vy -= 0.5f;
		m_vy -= m_speed_power;
		m_vx -= m_speed_power;
		m_posture = 1.0f;//下ボタンを押したときの表示されるイラスト
		m_ani_time += 1;
	}


	else
	{
		m_ani_frame = 1; //キー入力がない場合静止フレームにする
		m_ani_time = 0;
	}

	//アニメーション
	/*if (m_ani_time > m_ani_max_time)
	{
		m_ani_frame = 1;
		m_ani_time = 0;
	}

	if (m_ani_time == 4)
	{
		m_ani_frame = 0;
	}*/

	//位置の更新
	m_px += m_vx;
	m_py += m_vy;

	if (m_px > 800.0f)
	{
		m_px = 0.0f;//原点回帰
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
	m_px += m_vx;
	m_py += m_vy;

	//領域外に行かない
	if (m_px + 32.0f > 800.0f)
	{
		m_px = 800.0f - 32.0f;
	}
	if (m_py + 32.0f > 600.0f)
	{
		m_py = 600.0f - 32.0f;
	}
	if (m_py < 0.0f)
	{
		m_py = 0.0f;
	}
	if (m_px < 0.0f)
	{
		m_px = 0.0f;
	}

	//HitBoxの内容更新
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_px, m_py);//
}

void CObjRisu::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	//切り取り位置
	src.m_top = 0.0f;// 25.0f;
	src.m_left = 0.0f;// 17.0f;
	src.m_right = 128.0f;// 95.0f;
	src.m_bottom = 128.0f;// 70.0f;

	//表示
	dst.m_top = 0.0f + m_py;
	dst.m_left = (30.0f *m_posture) + m_px;
	dst.m_right = (30.0 -30.0f * m_posture) + m_px;// dst.m_left;
	dst.m_bottom = 30.0f + m_py;// dst.m_top;

	//2番目に登録したグラフィックをもとにsrc.dst.cの情報をもとに描画
	Draw::Draw(2, &src, &dst, c, 0.0f); //左向きリスl優先度３→リス
}