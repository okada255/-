#pragma once
//使用するヘッダー
#include"GameL/SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：MAP2C
class CSceneMap2C :public CScene
{
public:
	CSceneMap2C();
	~CSceneMap2C();
	void InitScene();//初期化メソッド
	void Scene();    //実行中メソッド
private:
	int m_time;
};