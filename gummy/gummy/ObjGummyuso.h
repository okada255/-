#pragma once
#include"GameL/SceneObjManager.h"
using namespace GameL;

class CObjGummyuso : public  CObj
{
public:
	CObjGummyuso(float x, float y);
	~CObjGummyuso() {};
	void Action();
	void Init();//
	void Draw();

private:
	float x;
	float y;
	float m_x;
	float m_y;
};
