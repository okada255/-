#include"GameL/DrawTexture.h"
#include"GameL/SceneObjManager.h"
#include"ObjDonatu.h"
#include"GameL/GameHead.h"
#include"GameL/WinInputs.h"
#include"GameL/HitBoxManager.h"

using namespace GameL;

void CObjDonatu::Init()
{//

}

void CObjDonatu::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	if (hit->CheckObjNameHit(OBJ_RISU) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}

void CObjDonatu::Draw()
{

}
