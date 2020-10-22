using namespace GameL;
#include"GameL/SceneObjManager.h"

class CObjChoco : public  CObj
{
public:
	CObjChoco();
	~CObjChoco();
	void Action();
	void Init();
	void Draw();

private:

	float m_x;
	float m_y;
};

