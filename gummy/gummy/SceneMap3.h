#pragma once
//使用するヘッダー
#include"GameL/SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：MAP3
class CSceneMap3 :public CScene
{
public:
	CSceneMap3();
	~CSceneMap3();
	void InitScene();//初期化メソッド
	void Scene();    //実行中メソッド
private:
	int m_time;
};