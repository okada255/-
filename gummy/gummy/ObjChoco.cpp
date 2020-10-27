#include"GameL/DrawTexture.h"
#include"GameL/SceneObjManager.h"
#include"ObjChoco.h"
#include"GameHead.h"
#include"GameL/WinInputs.h"
#include"GameL/HitBoxManager.h"

using namespace GameL;

void CObjChoco::Init()
{//
	float m_x= 0;
	float m_y= 0;
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ITEM, OBJ_CHOCO, 6);
}

void CObjChoco::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	if (hit->CheckObjNameHit(OBJ_RISU) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}

void CObjChoco::Draw()
{
	// 描画カラー情報
		float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	//表示位置の設定
	dst.m_top = 270.0f;
	dst.m_left = 250.0f;
	dst.m_right = dst.m_left + 18.75f;
	dst.m_bottom = dst.m_top + 18.75f;
	//描画
	Draw::Draw(6, &src, &dst, c, 0.0f);
}
