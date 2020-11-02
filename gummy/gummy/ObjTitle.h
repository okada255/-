#pragma once

#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjTitle : public CObj {
public:
	CObjTitle() {};
	~CObjTitle() {};
	void Init();
	void Action();
	void Draw();
private:
	bool m_key_flag;
};

#define RANKING_POS_X     (600)
#define RANKING_POS_Y     (0)
#define RANKING_FONT_SIZE  (24)
#define RANKING_SCORE_MAX (15)
#define STR_MAX           (256)
#define SCORE_INIT        (1)
#define SCORE_POS_X       (670)
#define SCORE_POS_Y       (24)
#define SCORE_POINT_MAX   (100)
#define SCORE_INTERVAL    (24)
#define SCORE_FONT_SIZE    (12)