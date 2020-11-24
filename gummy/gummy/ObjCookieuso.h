#pragma once
#include"GameL/SceneObjManager.h"
using namespace GameL;

class CObjCookieuso : public  CObj
{
public:
	CObjCookieuso(float x, float y);
	~CObjCookieuso() {};
	void Action();
	void Init();
	void Draw();

private:
	float x;
	float y;
	float m_x;
	float m_y;
};
