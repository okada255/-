#pragma once
//�g�p����w�b�_�[
#include"GameL/SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[���FMAP2B
class CSceneMap2B :public CScene
{
public:
	CSceneMap2B();
	~CSceneMap2B();
	void InitScene();//���������\�b�h
	void Scene();    //���s�����\�b�h
private:
	int m_time;
};