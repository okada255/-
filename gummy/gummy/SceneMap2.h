#pragma once
//使用するヘッダー
#include"GameL/SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：MAP2
class CSceneMap2 :public CScene
{
public:
	CSceneMap2();
	~CSceneMap2();
	void InitScene();//初期化メソッド
	void Scene();    //実行中メソッド
private:

};