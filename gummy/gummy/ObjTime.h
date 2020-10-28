#pragma once
//使用するヘッダー
#include"GameL/SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：メイン
class CObjTime :public CObj
{
public:
	CObjTime() {};
	~CObjTime() {};
	void Init();
	void Action();
	void Draw();
private:

};
