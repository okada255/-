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
    //��l���̈ʒu���擾
    CObjRisu* risu = (CObjRisu*)Objs::GetObj(OBJ_RISU);
    float hx = risu->GetX();
    float hy = risu->GetY();

    //m_map�̑S�v�f�ɃA�N�Z�X
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            if (m_map[i][j] > 0)
            {
                //�v�f�ԍ������W�ɕύX
                float x = j * 18.75 + 100;
                float y = i * 18.75;

                //��l���ƃu���b�N�̓����蔻��
                if ((hx + 18.75f > x) && (hx < x + 18.75f) && (hy + 18.75f > y) && (hy < y + 18.75f))
                {
                    //�㉺���E����

                    //Vector�̍쐬
                    float vx = hx - x;
                    float vy = hy - y;

                    //���������߂�
                    float len = sqrt(vx * vx + vy * vy);

                    //�p�x�����߂�
                    float r = atan2(vy, vx);
                    r = r * 180.0f / 3.14f;

                    if (r <= 0.0f)
                        r = abs(r);
                    else
                        r = 360.0f - abs(r);
                    if (len < 19.00f)
                    {
                        //�p�x�ŏ㉺���E�𔻒�
                        if ((r < 45 && r>=0) || r > 315)
                        {
                            //�E
                            risu->SetRight(true);
                            risu->SetX(x + 18.75f);
                            risu->SetVY(-risu->GetVX() * 0.1f);
                        }
                        if (r > 45 && r < 135)
                        {
                            //��
                            risu->SetDown(true);
                            risu->SetY(y - 18.75f);
                            risu->SetVY(0.0f);
                        }
                        if (r > 135 && r < 225)
                        {
                            //��
                            risu->SetLeft(true);
                            risu->SetX(x - 18.75f);
                            risu->SetVX(-risu->GetVX() * 0.1f);
                        }
                        if (r > 225 && r < 315)
                        {
                            //��
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

//�h���[
void CObjBlock::Draw()
{
    //�`��J���[���
    float c[4] = { 1.0f,1.0f,1.0f,1.0f };

    RECT_F src;
    RECT_F dst;

    //�؂���ʒu�̐ݒ�
    src.m_top = 0.0f;
    src.m_left = 0.0f;
    src.m_right = 32.0f;
    src.m_bottom = 32.0f;



    //�u���b�N�`��
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            if (m_map[i][j] > 0)
            {
                //�\���ʒu�̐ݒ�
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