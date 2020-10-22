#pragma once
#include "GameL\SceneManager.h"

using namespace GameL;

class CObjRisu : public  CObj
{
public:
	CObjRisu();
	~CObjRisu();
	void Action();
	void Init();
	void Draw();
	//
private:

	float m_x;
	float m_y;
};