#pragma once
#include"GameL/SceneObjManager.h"
//ネームスペース
using namespace GameL;

//オブジェクト：ブロック＆背景
class CObjBlock :public CObj
{
public:
	CObjBlock(int map[32][32]);
	~CObjBlock() {};
	void Init();
	void Action();
	void Draw();
private:
	int m_map[32][32];//マップ情報（仮）
	void BlockDraw(float x, float y, RECT_F* dst, float c[]);
};