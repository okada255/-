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

	float GetX() { return m_px; }
	float GetY() { return m_py; }
	void SetX(float x) { m_px = x; }
	void SetY(float y) { m_py = y; }
	void SetVY(float vy) { m_vy = vy; }
private:
	float m_px;//位置
	float m_py;
	float m_vx;//移動
	float m_vy;
	float m_posture;//主人公の向きを表現する変数

	int m_ani_time;//アニメーションフレーム動作間隔
	int m_ani_frame;//描画フレーム

	float m_speed_power; //スピードパワー
	float m_ani_max_time;//アニメーション動作間隔最大値
};
