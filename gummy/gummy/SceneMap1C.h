#pragma once
//使用するヘッダー
#include"GameL/SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：MAP1C
class CSceneMap1C :public CScene
{
public:
	CSceneMap1C();
	~CSceneMap1C();
	void InitScene();//初期化メソッド
	void Scene();    //実行中メソッド
private:
	int m_time;
};

