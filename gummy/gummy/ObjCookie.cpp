#include"GameL/DrawTexture.h"
#include"GameL/SceneObjManager.h"
#include"ObjCookie.h"
#include"GameL/GameHead.h"
#include"GameL/WinInputs.h"

using namespace GameL;

void CObjCookie::Init()
{//

}

void CObjCookie::Action()
{
	CObjRisu* risu = (CObjRisu*)Objs::GetObj(OBJ_RISU);
	float hx = risu->GetX();
	float hy = risu->GetY();
}

void CObjCookie::Draw()
{

}
