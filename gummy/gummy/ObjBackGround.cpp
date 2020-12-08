//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameHead.h"

#include"ObjBackGround.h"

//使用するネームスペース
using namespace GameL;



//イニシャライズ
void CObjBackGround::Init()
{

}

//アクション
void CObjBackGround::Action()
{

}

//ドロー
void CObjBackGround::Draw()
{
	//描画カラー情報 R G B A
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 256.0f;
	src.m_bottom = 256.0f;

	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 600.0f;
	dst.m_bottom = 600.0f;

	//登録したグラフィックを↑の情報をもとに表示
	Draw::Draw(53, &src, &dst, c, 0.0f);
}