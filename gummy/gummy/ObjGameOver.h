#pragma once

#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト ゲームオーバー
class CObjGameOver :public CObj
{
public:
	CObjGameOver() {};
	~CObjGameOver() {};
	void Init();  // イニシャライズ
	void Action();//アクション
	void Draw();  //ドロー
private:
};