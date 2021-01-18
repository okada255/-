#pragma once

#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjDescription : public CObj {
public:
	CObjDescription() {};
	~CObjDescription() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_mou_x; //マウスの位置x
	float m_mou_y; //マウスの位置y
	bool m_mou_r; //マウスの右ボタン
	bool m_mou_l; //マウスの左ボタン

	bool m_key_flag;
	int ai = 0;
};
