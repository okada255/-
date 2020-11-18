#pragma once
#include"GameL/SceneObjManager.h"
using namespace GameL;

class CObjChoco : public  CObj
{
public:
	CObjChoco(float x,float y);
	~CObjChoco(){};
	void Action();
	void Init();
	void Draw();

private:
	float x;
	float y;
	float m_x;
	float m_y;
};
