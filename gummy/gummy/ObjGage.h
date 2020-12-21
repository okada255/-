#pragma once
#include"GameL/SceneManager.h"
using namespace GameL;
class CObjGage :public CObj
{
public:
	CObjGage() {};
	~CObjGage() {};

	void Init();   //イニシャライズ
	void Action(); //アクション
	void Draw();   //ドロー
	void SetMageFlag(bool b) { m_flag_gage = b; }
private:
	bool  m_flag_gage; //時間計測フラグ
	int m_sutamina = 1440000;
	int m_gage=1440000;
};