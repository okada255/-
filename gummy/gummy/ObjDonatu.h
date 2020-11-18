#pragma once
#include"GameL/SceneObjManager.h"

using namespace GameL;

class CObjDonatu : public  CObj
{
public:
	CObjDonatu(float x,float y) ;
	~CObjDonatu() {};
	void Action();
	void Init();
	void Draw();

private:
	float m_x;
	float m_y;
	float x;
	float y;
};