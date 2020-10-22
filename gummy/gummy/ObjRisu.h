#pragma once
#include "GameL\SceneManager.h"

using namespace GameL;

class CObjRisu :public CObj
{
public:
	CObjRisu();
	~CObjRisu();
	void Init();
	void action();
	void draw();

private:
	float m_x;
	float m_y;
};
