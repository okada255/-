#pragma once//
#include "GameL\SceneManager.h"

using namespace GameL;

class CSeneMain :public CScene
{
public:
	CSeneMain();
	~CSeneMain();
	void InitScene();
	void Scene();
private:
	float m_x;
	float m_y;

};