#include"GameL/DrawTexture.h"
#include"GameL/SceneObjManager.h"
#include"Objupstage0.h"
#include"GameHead.h"
#include"GameL/WinInputs.h"
#include"GameL/HitBoxManager.h"
#include"GameL/Audio.h"
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

using namespace GameL;

void CObjupstage0::Init()
{
	m_x = 660;
	m_y = 100;
	Hits::SetHitBox(this, m_x, m_y, 26.25, 26.25, ELEMENT_ITEM, OBJ_UPSTAGE0, 30);
}

void CObjupstage0::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	//主人公と接触しているか調べる
	if (hit->CheckObjNameHit(OBJ_RISU) != nullptr)
	{
		Audio::Start(2);
		this->SetStatus(false);
		srand(time(NULL));
		ai = rand() % 3;
		if (ai == 0)
		{
			Scene::SetScene(new CSceneMap1());
		}
		else if (ai == 1)
		{
			Scene::SetScene(new CSceneMap1B());
		}
		else if (ai == 2)
		{
			Scene::SetScene(new CSceneMap1C());
		}
	}
}

void CObjupstage0::Draw()
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
	dst.m_top = 100.0f;
	dst.m_left = 660.0f;
	dst.m_right = dst.m_left + 26.25f;
	dst.m_bottom = dst.m_top + 26.25f;

	//描画
	Draw::Draw(30, &src, &dst, c, 0.0f);

	////切り取り位置設定
	//src.m_top = 0.0f;
	//src.m_left = 0.0f;
	//src.m_right = 1200.0f;
	//src.m_bottom = 800.0f;

	////表示位置の設定
	//dst.m_top = 0.0f;
	//dst.m_left = 0.0f;
	//dst.m_right = 800.0f;
	//dst.m_bottom = 600.0f;

	////登録したグラフィックを↑の情報をもとに表示
	//Draw::Draw(52, &src, &dst, c, 0.0f);
}