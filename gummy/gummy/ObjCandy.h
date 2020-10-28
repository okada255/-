#pragma once
#include"GameL/SceneObjManager.h"
#include"GameL/DrawTexture.h"
using namespace GameL;

class CObjCandy : public  CObj
{
public:
	CObjCandy() {};
	~CObjCandy() {};
	void Action();
	void Init();
	void Draw();
	//
private:

	float m_x;
	float m_y;
};
