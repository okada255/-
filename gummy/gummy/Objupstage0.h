#pragma once
#include"GameL/SceneObjManager.h"

using namespace GameL;

class CObjupstage0 : public  CObj
{
public:
	CObjupstage0() {};
	~CObjupstage0() {};
	void Action();
	void Init();
	void Draw();

private:
	float m_x;
	float m_y;
	int ai = 0;
};
