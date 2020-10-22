#include"GameL/DrawTexture.h"
#include"GameL/SceneObjManager.h"
#include"ObjDonatu.h"
#include"GameL/GameHead.h"
#include"GameL/WinInputs.h"

using namespace GameL;

void CObjDonatu::Init()
{//

}

void CObjDonatu::Action()
{
	CObjRisu* risu = (CObjRisu*)Objs::GetObj(OBJ_RISU);
	float hx = risu->GetX();
	float hy = risu->GetY();
}

void CObjDonatu::Draw()
{

}
