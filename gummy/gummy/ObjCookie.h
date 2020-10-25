#include"GameL/SceneObjManager.h"
using namespace GameL;

class CObjCookie : public  CObj
{
public:
	CObjCookie(){};
	~CObjCookie(){};
	void Action();
	void Init();
	void Draw();

private:

	float m_x;
	float m_y;
};
