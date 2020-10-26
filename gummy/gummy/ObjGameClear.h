#pragma once
#pragma once

#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjGameClear : public CObj
{
public:
	CObjGameClear() {};
	~CObjGameClear() {};
	void Init();
	void Action();
	void Draw();
private:
	bool m_key_flag;
};