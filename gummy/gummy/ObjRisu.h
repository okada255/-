#pragma once
#include "GameL\SceneManager.h"
#include"GameL/DrawTexture.h"
using namespace GameL;

class CObjRisu :public CObj
{
public:
	CObjRisu() {};
	~CObjRisu() {};
	void Init();   //�C�j�V�����C�Y
	void Action(); //�A�N�V����
	void Draw();   //�h���[

	float GetX() { return m_px; }
	float GetY() { return m_py; }
	void SetX(float x) { m_px = x; }
	void SetY(float y) { m_py = y; }
	void SetVY(float vy) { m_vy = vy; }
private:
	float m_px;//�ʒu
	float m_py;
	float m_vx;//�ړ�
	float m_vy;
	float m_posture;//��l���̌�����\������ϐ�

	int m_ani_time;//�A�j���[�V�����t���[������Ԋu
	int m_ani_frame;//�`��t���[��

	float m_speed_power; //�X�s�[�h�p���[
	float m_ani_max_time;//�A�j���[�V��������Ԋu�ő�l
};
