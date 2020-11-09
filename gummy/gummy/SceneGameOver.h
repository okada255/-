#pragma once

#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;


class CSceneGameOver :public CScene
{
public:
	CSceneGameOver();
	~CSceneGameOver();
	void InitScene(); //初期化メソッド
	void Scene();//実行中メソッド
private:
};