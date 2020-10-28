#pragma once
#include "GameL\SceneManager.h"
#include"GameL/DrawTexture.h"
using namespace GameL;

class CObjRisu :public CObj
{
public:
	CObjRisu() {};
	~CObjRisu() {};
	void Init();
	void Action();
	void Draw();

private:
	float m_px;
	float m_py;
	float m_vx;
	float m_vy;
	float m_posture;

	int m_ani_time;
	int m_ani_frame;
};
