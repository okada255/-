#pragma once
//�g�p����w�b�_�[
#include"GameL/SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[���FMAP1
class CSceneMap1 :public CScene
{
public:
	CSceneMap1();
	~CSceneMap1();
	void InitScene();//���������\�b�h
	void Scene();    //���s�����\�b�h
private:
	int m_time;
};