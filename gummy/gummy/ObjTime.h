#pragma once
//�g�p����w�b�_�[
#include"GameL/SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[���F���C��
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
	int m_time; //����
	bool  m_flag_time; //���Ԍv���t���O
};
