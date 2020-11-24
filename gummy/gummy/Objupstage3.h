#pragma once
#include"GameL/SceneObjManager.h"

using namespace GameL;

class CObjupstage3 : public  CObj
{
public:
	CObjupstage3() {};
	~CObjupstage3() {};
	void Action();
	void Init();
	void Draw();

private:
	float m_x;
	float m_y;
};