#pragma once
#include"GameL/SceneObjManager.h"
using namespace GameL;

class CObjChocouso : public  CObj
{
public:
	CObjChocouso(float x, float y);
	~CObjChocouso() {};
	void Action();
	void Init();
	void Draw();

private:
	float x;
	float y;
	float m_x;
	float m_y;
};
