#pragma once
//�g�p����w�b�_�[
#include"GameL/SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[���F���C��
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
	int m_gram; //�O����
	bool  m_flag_gram; //�O�����v���t���O
};