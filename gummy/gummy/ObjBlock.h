#pragma once
#include"GameL/SceneObjManager.h"
//�l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�u���b�N���w�i
class CObjBlock :public CObj
{
public:
	CObjBlock(int map[32][32]);
	~CObjBlock() {};
	void Init();
	void Action();
	void Draw();
private:
	int m_map[32][32];//�}�b�v���i���j
	void BlockDraw(float x, float y, RECT_F* dst, float c[]);
};