#include"GameL/DrawTexture.h"
#include"GameL/SceneObjManager.h"
#include"Objupstage2.h"
#include"GameHead.h"
#include"GameL/WinInputs.h"
#include"GameL/HitBoxManager.h"
#include"GameL/Audio.h"

using namespace GameL;

CObjupstage::CObjupstage(float x, float y)
{
	m_x = x;
	m_y = y;
}

void CObjupstage::Init()
{
	Hits::SetHitBox(this, m_x, m_y, 26.25, 26.25, ELEMENT_ITEM, OBJ_UPSTAGE2, 30);
}

void CObjupstage::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	//主人公と接触しているか調べる
	if (hit->CheckObjNameHit(OBJ_RISU) != nullptr)
	{
		Audio::Start(2);
		this->SetStatus(false);
		Scene::SetScene(new CSceneMap2());

		Audio::Stop(0);
	}
}

void CObjupstage::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 499.0f;
	src.m_bottom = 499.0f;

	//表示位置の設定
	dst.m_top = m_y;
	dst.m_left = m_x;
	dst.m_right = dst.m_left + 26.25f;
	dst.m_bottom = dst.m_top + 26.25f;

	//描画
	Draw::Draw(30, &src, &dst, c, 0.0f);
}