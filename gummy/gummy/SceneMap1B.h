#pragma once
//�g�p����w�b�_�[
#include"GameL/SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[���FMAP1-B
class CSceneMap1B :public CScene
{
public:
	CSceneMap1B();
	~CSceneMap1B();
	void InitScene();//���������\�b�h
	void Scene();    //���s�����\�b�h
private:
	int m_time;
};
