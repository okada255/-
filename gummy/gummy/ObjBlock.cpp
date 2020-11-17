//使用ヘッダー
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/SceneObjManager.h"
#include"GameL/HitBoxManager.h"

#include"GameHead.h"
#include"ObjBlock.h"

//使用ネームスペース
using namespace GameL;

CObjBlock::CObjBlock(int map[32][32])
{
    //MAPデータをコピー
    memcpy(m_map, map, sizeof(int) * (32 * 32));
}

//イニシャライズ
void CObjBlock::Init()
{

}


//アクション
void CObjBlock::Action()
{
    //主人公の位置を取得
    CObjRisu* risu = (CObjRisu*)Objs::GetObj(OBJ_RISU);
    float hx = risu->GetX();
    float hy = risu->GetY();

    //m_mapの全要素にアクセス
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            if (m_map[i][j] > 0)
            {
                //要素番号を座標に変更
                float x = j * 18.75 + 100;
                float y = i * 18.75;

                //主人公とブロックの当たり判定
                if ((hx + 18.75f > x) && (hx < x + 18.75f) && (hy + 18.75f > y) && (hy < y + 18.75f))
                {
                    //上下左右判定

                    //Vectorの作成
                    float vx = hx - x;
                    float vy = hy - y;

                    //長さを求める
                    float len = sqrt(vx * vx + vy * vy);

                    //角度を求める
                    float r = atan2(vy, vx);
                    r = r * 180.0f / 3.14f;

                    if (r <= 0.0f)
                        r = abs(r);
                    else
                        r = 360.0f - abs(r);
                    if (len < 19.00f)
                    {
                        //角度で上下左右を判定
                        if ((r < 45 && r>=0) || r > 315)
                        {
                            //右
                            risu->SetRight(true);
                            risu->SetX(x + 18.75f);
                            risu->SetVY(-risu->GetVX() * 0.1f);
                        }
                        if (r > 45 && r < 135)
                        {
                            //上
                            risu->SetDown(true);
                            risu->SetY(y - 18.75f);
                            risu->SetVY(0.0f);
                        }
                        if (r > 135 && r < 225)
                        {
                            //左
                            risu->SetLeft(true);
                            risu->SetX(x - 18.75f);
                            risu->SetVX(-risu->GetVX() * 0.1f);
                        }
                        if (r > 225 && r < 315)
                        {
                            //下
                            risu->SetUp(true);
                            risu->SetY(y + 18.75f);
                            if (risu->GetVY() < 0)
                            {
                                risu->SetVY(0.0f);
                            }

                        }
                    }


                }
            }
        }
    }
}

//ドロー
void CObjBlock::Draw()
{
    //描画カラー情報
    float c[4] = { 1.0f,1.0f,1.0f,1.0f };

    RECT_F src;
    RECT_F dst;

    //切り取り位置の設定
    src.m_top = 0.0f;
    src.m_left = 0.0f;
    src.m_right = 32.0f;
    src.m_bottom = 32.0f;



    //ブロック描画
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            if (m_map[i][j] > 0)
            {
                //表示位置の設定
                dst.m_top = i * 18.75f;
                dst.m_left = j * 18.75f + 100.0;
                dst.m_right = dst.m_left + 18.75f;
                dst.m_bottom = dst.m_top + 18.75f;
                if (m_map[i][j] == 1)
                {
                    BlockDraw(0, 0, &dst, c);

                }
            }
        }
    }
}

//BlockDraw関数定義
void CObjBlock::BlockDraw(float x, float y, RECT_F* dst, float c[])
{

    RECT_F src;
    src.m_top = y;
    src.m_left = x;
    src.m_right = src.m_left + 32.0f;
    src.m_bottom = src.m_top + 32.0f;
    //描画
    Draw::Draw(1, &src, dst, c, 0.0f);

}