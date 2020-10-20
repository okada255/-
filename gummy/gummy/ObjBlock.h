#pragma once
#include"GameL/SceneObjManager.h"
//ネームスペース
using namespace GameL;

//オブジェクト：ブロック＆背景
class CObjBlock :public CObj
{
public:
	CObjBlock() {};
	~CObjBlock() {};
	void Init();
	void Action();
	void Draw();
private:
};