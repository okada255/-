#pragma once
//�g�p����w�b�_�[
#include"GameL/SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[���FMAP1C
class CSceneMap1C :public CScene
{
public:
	CSceneMap1C();
	~CSceneMap1C();
	void InitScene();//���������\�b�h
	void Scene();    //���s�����\�b�h
private:
	int m_time;
};

