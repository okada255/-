#include"GameHead.h"
#include"GameL/WinInputs.h"
#include"GameL/HitBoxManager.h"
#include"ObjBigCake.h"
#include"GameL/DrawTexture.h"
#include"GameL/SceneObjManager.h"
#include "GameL\Audio.h"
#include"GameL/UserData.h"

using namespace GameL;

CObjBigCake::CObjBigCake(float x, float y)
{
	m_x = x;
	m_y = y;
}
void CObjBigCake::Init()
{
	/*m_x = 550;
	m_y = 300;*/

	Hits::SetHitBox(this, m_x, m_y, 112.5, 112.5, ELEMENT_ITEM, OBJ_BIG_CAKE, 50);
}

void CObjBigCake::Action()
{
	CObjBigCake* bigcake = (CObjBigCake*)Objs::GetObj(OBJ_BIG_CAKE);
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);
	//主人公と接触しているか調べる
	if (hit->CheckObjNameHit(OBJ_RISU) != nullptr)
	{
		Audio::Start(1);

		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		((UserData*)Save::GetData())->m_point += 150;
		Scene::SetScene(new CSceneGameClear());
	}
}

void CObjBigCake::Draw()
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
	dst.m_top = m_y;/*300.0f;*/
	dst.m_left = m_x;//550.0f;
	dst.m_right = dst.m_left + 112.5f;
	dst.m_bottom = dst.m_top +112.5f;

	//描画
	Draw::Draw(8, &src, &dst, c, 0.0f);
}