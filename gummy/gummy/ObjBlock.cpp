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

}

//ドロー
void CObjBlock::Draw()
{
  //描画カラー情報
    float c[4] = { 1.0f,1.0f,1.0f,1.0f };
    RECT_F src;
    RECT_F dst;

    //ブロック描画
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            if (m_map[i][j] > 0)
            {
                //表示位置の設定
                dst.m_top = i * 64.0f;
                dst.m_left = j * 64.0f;
                dst.m_right = dst.m_left + 64.0f;
                dst.m_bottom = dst.m_top + 64.0f;
                if (m_map[i][j] == 1)
                {
                    //BlockDraw(64.0f, 0.0f, &dst, c, 1);
                    ;
                }
            }
        }
    }
}

