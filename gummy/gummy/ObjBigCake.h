#pragma once
#include"GameL/SceneObjManager.h"
#include"GameL/DrawTexture.h"
using namespace GameL;

class CObjBigCake : public  CObj
{
public:
	CObjBigCake(float x, float y);//{}
	~CObjBigCake() {};
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
