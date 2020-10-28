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

	void SetTimeFlag(bool b) { m_flag_time = b; }
private:
	int m_time; //時間
	bool  m_flag_time; //時間計測フラグ
};
