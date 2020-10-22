#include"GameL/GameHead.h"
#include"GameL/WinInputs.h"

using namespace GameL;

void CObjCandy::Init()
{//‚ ‚ ‚ 

}

void CObjCandy::Action()
{
	CObjRisu* risu = (CObjRisu*)Objs::GetObj(OBJ_RISU);
	float hx = risu->GetX();
	float hy = risu->GetY();
}

void CObjCandy::Draw()
{

}
