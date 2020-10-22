#include"GameL/DrawTexture.h"
#include"GameL/SceneObjManager.h"
#include"ObjGummy.h"
#include"GameL/GameHead.h"
#include"GameL/WinInputs.h"

using namespace GameL;

void CObjGummy::Init()
{//

}

void CObjGummy::Action()
{
	CObjRisu* risu = (CObjRisu*)Objs::GetObj(OBJ_RISU);
	float hx = risu->GetX();
	float hy = risu->GetY();
}

void CObjGummy::Draw()
{

}
