#pragma once
#include"GameL/SceneObjManager.h"
//�l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�u���b�N���w�i
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