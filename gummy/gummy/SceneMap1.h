#pragma once
//使用するヘッダー
#include"GameL/SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：MAP1
class CSceneMap1 :public CScene
{
public:
	CSceneMap1();
	~CSceneMap1();
	void InitScene();//初期化メソッド
	void Scene();    //実行中メソッド
private:
	int m_time;
};