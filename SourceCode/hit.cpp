#include"all.h"

#include"player.h"
#include"object.h"
#include"hit.h"

player p2;
object o2;
bool hitCheck(int x1, int y1, float r1, int x2, int y2, float r2)
{
    float disx = x2 - x1;
    float disy = y2 - y1;
    float r = r1 + r2;

    if ((disx * disx + disy * disy) <= (r * r))return true;

    return false;
}

void hit::Update()
{
    
    p2.GettherX();
    py = p2.GettherY();
    for (int i = 0; i < 9; i++)
    {
        ox[i] = o2.GettherX();
        oy[i] = o2.GettherY();
        oo[i] = o2.GettherO();
    }
    ////�f�o�b�N�p ���̐�[�ɉ~������
    //primitive::circle(
    //    px, py,             //�ʒu
    //    32,                     //���a
    //    1, 1,                   //�X�P�[��
    //    ToRadian(0),            //�p�x
    //    0.0F, 1.0F, 0.0F, 0.5F   //�F
    //);

    //maemaemae
    //-------------------------------------------
    // �����蔻��
    //-------------------------------------------
    //��Q��(��i)
    for (int i = 0; i < 9; i++)
    {


        primitive::circle(
            px + 10, py,             //�ʒu
            32,                     //���a
            1, 1,                   //�X�P�[��
            ToRadian(0),            //�p�x
            1.0F, 0.0F, 0.0F, 0.2F); //�F
        primitive::circle(
            ox[i] + 64, oy[i] + 64,             //�ʒu
            32,                     //���a

            1, 1,                   //�X�P�[��
            ToRadian(0),            //�p�x
            0.0F, 0.0F, 1.0F, 0.5F); //�F
        if (hitCheck(px + 10, py, 32, ox[i] + 64, oy[i] + 64, 32)) {
            //������

            if (oo[i] == 0)
            {

                /*p.hitObj[0] = o.overchange[i];*/


            }
            else
            {

            }
        }

    }
}