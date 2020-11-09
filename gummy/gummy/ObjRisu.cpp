#include"GameL/DrawTexture.h"
#include"GameL/SceneObjManager.h"
#include"GameL/WinInputs.h"
#include"GameL/HitBoxManager.h"

#include"ObjRisu.h"
#include"GameHead.h"

using namespace GameL;

void CObjRisu::Init()
{
	m_px = 100;
	m_py = (600 / 2) - 16;
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_posture = 0.0f;//右向き0.0f,左向き1.0f

	//当たり判定
	Hits::SetHitBox(this, m_px, m_py, 18.85, 18.85, ELEMENT_PLAYER, OBJ_RISU, 1);
}
void CObjRisu::Action()
{
	//主人公の位置を取得
	CObjRisu* risu = (CObjRisu*)Objs::GetObj(OBJ_RISU);
	float hx = risu->GetX();
	float hy = risu->GetY();

	m_vy = 0.0f;
	m_vx = 0.0f;
	m_posture = 1.0f;

	m_ani_time = 0;
	m_ani_frame = 1;//静止フレームを初期にする

	m_speed_power = 0.5f;//通常速度
	/*m_ani_max_time = 4;*///アニメーション間隔幅

	//Zキー入力で速度アップ
	if (Input::GetVKey('Z') == true)
	{
		//ダッシュ時の速度
		m_speed_power = 1.1f;
	}
	else
	{
		//通常速度
		m_speed_power = 0.5f;
	}

	//キーの入力方向にベクトルの速度を入れる
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vx += 1.0f;
		m_vx += m_speed_power;
		m_posture = 0.0f;
		m_ani_time += 1;
	}

	//else if (Input::GetVKey(VK_LEFT) == true)
	//{
	//	m_vx += m_speed_power;
	//	m_posture = 0.0f;
	//	m_ani_time += 1;
	//}

	//else
	//{
	//	m_ani_frame = 1; //キー入力がない場合静止フレームにする
	//	m_ani_time = 0;
	//}

	//if (m_ani_time > m_ani_max_time)
	//{
	//	m_ani_frame = 1;
	//	m_ani_time = 0;
	//}

	//if (m_ani_time == 4)
	//{
	//	m_ani_frame = 0;
	//}

	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vx -= 1.0f;
		m_posture = 1.0f;
	}

	if (Input::GetVKey(VK_UP) == true)
	{
		m_vy -= 1.0f;
	}

	if (Input::GetVKey(VK_DOWN) == true)
	{
		m_vy += 1.0f;
	}

	//摩擦
	/*m_vx += -(m_vx * 0.098);*/

	//位置の更新
	m_px += m_vx;
	m_py += m_vy;

	if (m_px > 800.0f)
	{
		m_px = 0.0f;//原点回帰
	}

	//ベクトルの長さを求める
	float r = 0.0f;
	r = m_vx * m_vx + m_vy * m_vy;
	r = sqrt(r);//rをルートを求める

	//長さが0か求める
	if (r == 0.0f)
	{
		; //0なら何もしない。
	}
	else
	{
		//正規化を行う
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
	hit->SetPos(m_px, m_py);
}

//ドロー
void CObjRisu::Draw()
{
	int AniData[4] = 
	{
		1,0,2,0
	};
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };//描画カラー情報
	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	//切り取り位置
	src.m_top = 0.0f;
	src.m_left = 0.0f;// +AniData[m_ani_frame] * 128;
	src.m_right = 128.0f;// +AniData[m_ani_frame] * 128;
	src.m_bottom = 128.0f;

	//表示
	dst.m_top = 0.0f + m_py;
	dst.m_left = (18.85f * m_posture)+ m_px; //*(m_posture)
	dst.m_right = (18.85 - 18.85f * m_posture)+ dst.m_left; //*m_posture
	dst.m_bottom = 18.85f+ dst.m_top;

	//2番目に登録したグラフィックをもとにsrc.dst.cの情報をもとに描画
	Draw::Draw(2, &src, &dst, c, 0.0f); //右
	//Draw::Draw(3, &src, &dst, c, 0.0f); //左
	//Draw::Draw(4, &src, &dst, c, 0.0f); //前
	//Draw::Draw(5, &src, &dst, c, 0.0f); //後ろ

}