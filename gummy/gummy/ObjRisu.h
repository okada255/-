#pragma once
#include "GameL\SceneManager.h"
#include"GameL/DrawTexture.h"
using namespace GameL;


class CObjRisu :public CObj
{
public:
	CObjRisu() {};
	~CObjRisu() {};
	void Init();   //イニシャライズ
	void Action(); //アクション
	void Draw();   //ドロー

	float m_speed_power; //スピードパワー
	float GetX() { return m_px; }
	float GetY() { return m_py; }
	float GetVY() { return m_vy; }
	float GetVX() { return m_vx; }
	void SetX(float x) { m_px = x; }
	void SetY(float y) { m_py = y; }
	void SetVY(float vy) { m_vy = vy; }
	void SetVX(float vx) { m_vx = vx; }

	void SetUp(bool b) { m_hit_up = b; }
	void SetDown(bool b) { m_hit_down = b; }
	void SetLeft(bool b) { m_hit_left = b; }
	void SetRight(bool b) { m_hit_right = b; }

	float m_dash = 100;//ダッシュのクールタイム用変数


private:
	float m_px;
	float m_py;
	float m_vx;
	float m_vy;
	/*float m_x;
	float m_y;*/
	float m_posture;

	int m_ani_time;//アニメーションフレーム動作間隔
	int m_ani_frame;//描画フレーム
	float m_ani_max_time;//アニメーション動作間隔最大値

	//blockとの衝突状態確認用
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;
};
