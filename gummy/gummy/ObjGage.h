#pragma once
#include"GameL/SceneManager.h"
using namespace GameL;
class CObjGage :public CObj
{
public:
	CObjGage() {};
	~CObjGage() {};

	void Init();   //�C�j�V�����C�Y
	void Action(); //�A�N�V����
	void Draw();   //�h���[
	void SetMageFlag(bool b) { m_flag_gage = b; }
private:
	bool  m_flag_gage; //���Ԍv���t���O
	int m_sutamina = 720000;
	int m_gage=720000;
};