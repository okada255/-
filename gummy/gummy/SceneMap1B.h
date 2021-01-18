#pragma once
//使用するヘッダー
#include"GameL/SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：MAP1-B
class CSceneMap1B :public CScene
{
public:
	CSceneMap1B();
	~CSceneMap1B();
	void InitScene();//初期化メソッド
	void Scene();    //実行中メソッド
private:
	int m_time;
};
