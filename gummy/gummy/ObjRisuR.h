#pragma once
#include "GameL\SceneManager.h"
#include"GameL/DrawTexture.h"
using namespace GameL;

class CObjRisuR :public CObj
{
public:
	CObjRisuR() {};
	~CObjRisuR() {};
	void Init();   //イニシャライズ
	void Action(); //アクション
	void Draw();   //ドロー

	float GetX() { return m_px; }
	float GetY() { return m_py; }
	void SetX(float x) { m_px = x; }
	void SetY(float y) { m_py = y; }
	void SetVY(float vy) { m_vy = vy; }
private:
	float m_px;
	float m_py;
	float m_vx;
	float m_vy;
	float m_posture;

	int m_ani_time;//アニメーションフレーム動作間隔
	int m_ani_frame;//描画フレーム

	float m_speed_power; //スピードパワー
	float m_ani_max_time;//アニメーション動作間隔最大値
};

