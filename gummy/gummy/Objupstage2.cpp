#include"GameL/DrawTexture.h"
#include"GameL/SceneObjManager.h"
#include"Objupstage.h"
#include"GameHead.h"
#include"GameL/WinInputs.h"
#include"GameL/HitBoxManager.h"


using namespace GameL;

void CObjupstage2::Init()
{
	m_x = 660;
	m_y = 530;
	Hits::SetHitBox(this, m_x, m_y, 18.75, 18.75, ELEMENT_ITEM, OBJ_UPSTAGE2, 30);
}

void CObjupstage2::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	//主人公と接触しているか調べる
	if (hit->CheckObjNameHit(OBJ_RISU) != nullptr)
	{
		this->SetStatus(false);

		Scene::SetScene(new CSceneMap1());
	}
}

void CObjupstage2::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 696.0f;
	src.m_bottom = 696.0f;

	//表示位置の設定
	dst.m_top = 530.0f;
	dst.m_left = 660.0f;
	dst.m_right = dst.m_left + 18.75f;
	dst.m_bottom = dst.m_top + 18.75f;

	//描画
	Draw::Draw(30, &src, &dst, c, 0.0f);
}