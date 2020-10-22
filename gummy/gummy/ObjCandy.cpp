/*#include"GameL/GameHead.h"
#include"GameL/WinInputs.h"
#include"GameL/HitBoxManager.h"
#include"ObjCandy.h"
#include"GameL/DrawTexture.h"
#include"GameL/SceneObjManager.h"

using namespace GameL;

void CObjCandy::Init()
{//‚ ‚ ‚ 

}

void CObjCandy::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	if (hit->CheckObjNameHit(OBJ_RISU) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}

void CObjCandy::Draw()
{

}
*/