#include"GameHead.h"
#include"GameL/WinInputs.h"
#include"GameL/HitBoxManager.h"
#include"ObjCandy.h"
#include"GameL/DrawTexture.h"
#include"GameL/SceneObjManager.h"
#include"GameL/UserData.h"

using namespace GameL;

CObjCandy::CObjCandy(float x, float y)
{
	m_x = x;
	m_y = y;
}

void CObjCandy::Init()
{
	
	//HitBox作成
	Hits::SetHitBox(this, m_x, m_y, 18.75, 18.75, ELEMENT_ITEM, OBJ_CANDY, 1);
}

void CObjCandy::Action()
{
	//HitBox更新
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);
	//主人公と接触しているか調べる
	if (hit->CheckObjNameHit(OBJ_RISU) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		((UserData*)Save::GetData())->m_point += 10;
	}
}

void CObjCandy::Draw()
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
	dst.m_top = m_y;
	dst.m_left = m_x;
	dst.m_right = dst.m_left + 18.75f;
	dst.m_bottom = dst.m_top + 18.75f;

	//描画
	Draw::Draw(4, &src, &dst, c, 0.0f);
}

