#include"GameL/DrawTexture.h"
#include"GameL/SceneObjManager.h"
#include"ObjGummy.h"
#include"GameHead.h"
#include"GameL/WinInputs.h"
#include"GameL/HitBoxManager.h"
#include"GameL/UserData.h"
#include"GameL/Audio.h"

using namespace GameL;

CObjGummy::CObjGummy(float x, float y)
{
	m_x = x;
	m_y = y;
}


void CObjGummy::Init()
{
	Hits::SetHitBox(this, m_x, m_y, 18.75, 18.75, ELEMENT_ITEM, OBJ_GUMMY, 3);
}

void CObjGummy::Action()
{

	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	//主人公と接触しているか調べる
	if (hit->CheckObjNameHit(OBJ_RISU) != nullptr)
	{
		Audio::Start(1);

		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	
		((UserData*)Save::GetData())->m_point += 5;
	}
}

void CObjGummy::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	//表示位置の設定

	//表示位置の設定
	dst.m_top = m_y;
	dst.m_left = m_x;
	dst.m_right = dst.m_left + 18.75f;
	dst.m_bottom = dst.m_top + 18.75f;

	//描画
	Draw::Draw(7, &src, &dst, c, 0.0f);
}
