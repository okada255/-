//�g�p�w�b�_�[
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/SceneObjManager.h"
#include"GameL/HitBoxManager.h"

#include"GameHead.h"
#include"ObjBlock.h"

//�g�p�l�[���X�y�[�X
using namespace GameL;

CObjBlock::CObjBlock(int map[32][32])
{
    //MAP�f�[�^���R�s�[
    memcpy(m_map, map, sizeof(int) * (32 * 32));
}

//�C�j�V�����C�Y
void CObjBlock::Init()
{

}


//�A�N�V����
void CObjBlock::Action()
{

}

//�h���[
void CObjBlock::Draw()
{
  //�`��J���[���
    float c[4] = { 1.0f,1.0f,1.0f,1.0f };
    
    RECT_F dst;

    //�u���b�N�`��
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            if (m_map[i][j] > 0)
            {
                //�\���ʒu�̐ݒ�
                dst.m_top = i * 32.0f;
                dst.m_left = j * 32.0f;
                dst.m_right = dst.m_left + 32.0f;
                dst.m_bottom = dst.m_top + 32.0f;
                if (m_map[i][j] == 1)
                {
                    BlockDraw(32.0f, 0.0f, &dst, c);
                    
                }
            }
        }
    }
}

//BlockDraw�֐���`
void CObjBlock::BlockDraw(float x, float y, RECT_F* dst, float c[])
{

    RECT_F src;
    src.m_top = y;
    src.m_left = x;
    src.m_right = src.m_left + 32.0f;
    src.m_bottom = src.m_top + 32.0f;
    //�`��
    Draw::Draw(1, &src, dst, c, 0.0f);

}
//