#include"GameL/DrawTexture.h"
#include"GameL/SceneObjManager.h"
#include"ObjDonatu.h"
#include"GameHead.h"//

using namespace GameL;

class CObjDonatu :public CObj
{
public:
	CObjDonatu(){};
	~CObjDonatu() {};
	void Init();
	void Action();
	void Draw();

private:
};