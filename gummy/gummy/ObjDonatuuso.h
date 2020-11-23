#pragma once
#include"GameL/SceneObjManager.h"

using namespace GameL;

class CObjDonatuuso : public  CObj
{
public:
	CObjDonatuuso(float x, float y);
	~CObjDonatuuso() {};
	void Action();
	void Init();
	void Draw();

private:
	float m_x;
	float m_y;
	float x;
	float y;
};
