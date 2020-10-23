#pragma once
#include "GameL\SceneManager.h"

using namespace GameL;

class CObjRisu :public CObj
{
public:
	CObjRisu();
	~CObjRisu();
	void Init();
	void Action();
	void Draw();

private:
	float m_x;
	float m_y;
	float m_vx;
	float m_vy;
};
