#include"GameHead.h"
#include"GameL/WinInputs.h"
#include"GameL/HitBoxManager.h"
#include"ObjBigCakeuso.h"
#include"GameL/DrawTexture.h"
#include"GameL/SceneObjManager.h"

using namespace GameL;

CObjBigCakeuso::CObjBigCakeuso(float x, float y)
{
	m_x = x;
	m_y = y;
}
void CObjBigCakeuso::Init()
{
	/*m_x = 550;
	m_y = 300;*/

	Hits::SetHitBox(this, m_x, m_y, 112.5, 112.5, ELEMENT_ITEM, OBJ_BIG_CAKEUSO, 50);
}

void CObjBigCakeuso::Action()
{
	CObjBigCake* bigcake = (CObjBigCake*)Objs::GetObj(OBJ_BIG_CAKEUSO);
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);
	//主人公と接触しているか調べる
	if (hit->CheckObjNameHit(OBJ_RISU) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}

void CObjBigCakeuso::Draw()
{
	// 描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 714.0f;
	src.m_bottom = 714.0f;

	//表示位置の設定
	dst.m_top = m_y;/*300.0f;*/
	dst.m_left = m_x;//550.0f;
	dst.m_right = dst.m_left + 112.5f;
	dst.m_bottom = dst.m_top + 112.5f;

	//描画
	Draw::Draw(8, &src, &dst, c, 0.0f);
}