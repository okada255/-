#pragma once
//�g�p����w�b�_�[
#include"GameL/SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[���FMAP3
class CSceneMap3 :public CScene
{
public:
	CSceneMap3();
	~CSceneMap3();
	void InitScene();//���������\�b�h
	void Scene();    //���s�����\�b�h
private:
	int m_time;
};