#pragma once
#include"GameL/SceneObjManager.h"

using namespace GameL;

class CObjupstage : public  CObj
{
public:
	CObjupstage(float x,float y);
	~CObjupstage() {};
	void Action();
	void Init();
	void Draw();

private:
	float m_x;
	float m_y;
	float x;
	float y;
	int ai = 0;
};