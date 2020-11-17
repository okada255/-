#pragma once
#include"GameL/SceneObjManager.h"
#include"GameL/DrawTexture.h"
using namespace GameL;

class CObjCandy : public  CObj
{
public:
	CObjCandy(float x,float y);
	~CObjCandy() {};
	void Action();
	void Init();
	void Draw();
	//
private:
	float x;
	float y;
	float m_x;
	float m_y;
};
