#pragma once
#include"GameL/SceneObjManager.h"
#include"GameL/DrawTexture.h"
using namespace GameL;

class CObjBigCakeuso : public  CObj
{
public:
	CObjBigCakeuso(float x, float y);//{}
	~CObjBigCakeuso() {};
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
