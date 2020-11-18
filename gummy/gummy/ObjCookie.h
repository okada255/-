#pragma once
#include"GameL/SceneObjManager.h"
using namespace GameL;

class CObjCookie : public  CObj
{
public:
	CObjCookie(float x, float y);
	~CObjCookie(){};
	void Action();
	void Init();
	void Draw();

private:
	float x;
	float y;
	float m_x;
	float m_y;
};
