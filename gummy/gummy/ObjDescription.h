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
	float m_mou_x; //�}�E�X�̈ʒux
	float m_mou_y; //�}�E�X�̈ʒuy
	bool m_mou_r; //�}�E�X�̉E�{�^��
	bool m_mou_l; //�}�E�X�̍��{�^��

	bool m_key_flag;
	int ai = 0;
};
