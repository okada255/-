#pragma once
//使用するヘッダー
#include"GameL/SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：メイン
class CObjScore :public CObj
{
public:
	CObjScore() {};
	~CObjScore() {};
	void Init();
	void Action();
	void Draw();
	void SetGramFlag(bool g) { m_flag_gram = g; }
private:
	int m_gram; //グラム
	bool  m_flag_gram; //グラム計測フラグ
};