#pragma once
#include"GameL/SceneObjManager.h"
#include"GameL/DrawTexture.h"
using namespace GameL;

class CObjCandyuso : public  CObj
{
public:
	CObjCandyuso(float x, float y);
	~CObjCandyuso() {};
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