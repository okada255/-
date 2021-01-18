#pragma once
#include"GameL/SceneObjManager.h"
#include"GameL/DrawTexture.h"
using namespace GameL;

class CObjSnkscr : public  CObj
{
public:
	CObjSnkscr(float x, float y);//{}
	~CObjSnkscr() {};
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
