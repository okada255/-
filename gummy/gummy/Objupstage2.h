#pragma once
#include"GameL/SceneObjManager.h"

using namespace GameL;

class CObjupstage2 : public  CObj
{
public:
	CObjupstage2(float x,float y);
	~CObjupstage2() {};
	void Action();
	void Init();
	void Draw();

private:
	float m_x;
	float m_y;
	float x;
	float y;
};