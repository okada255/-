#pragma once
#include"GameL/SceneObjManager.h"
using namespace GameL;

class CObjGummy : public  CObj
{
public:
	CObjGummy(float x,float y);
	~CObjGummy(){};
	void Action();
	void Init();//
	void Draw();

private:
	float x;
	float y;
	float m_x;
	float m_y;
};

