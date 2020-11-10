#pragma once
#include"GameL/SceneObjManager.h"
#include"GameL/DrawTexture.h"
using namespace GameL;

class CObjBigCake : public  CObj
{
public:
	CObjBigCake() {};
	~CObjBigCake() {};
	void Action();
	void Init();
	void Draw();
	//
private:

	float m_x;
	float m_y;
};
