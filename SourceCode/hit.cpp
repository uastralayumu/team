#include"all.h"

#include"player.h"
#include"object.h"
#include"hit.h"

extern player p;
extern object o;

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
    //-------------------------------------------
    // �����蔻��
    //-------------------------------------------
    //��Q��(��i)
    for (int i = 0; i < 9; i++)
    {
        primitive::circle(
            p.playerpositionx + 10, p.playerpositiony,             //�ʒu
            32,                     //���a
            1, 1,                   //�X�P�[��
            ToRadian(0),            //�p�x
            1.0F, 0.0F, 0.0F, 0.2F); //�F
        primitive::circle(
            o.overpositionx[i] + 64, o.overpositiony[i] + 64,             //�ʒu
            32,                     //���a

            1, 1,                   //�X�P�[��
            ToRadian(0),            //�p�x
            0.0F, 0.0F, 1.0F, 0.5F); //�F
        if (hitCheck(p.playerpositionx + 10, p.playerpositiony, 32, o.overpositionx[i] + 64,  o.overpositiony[i] + 64, 32)) {
            
            if (o.xyoverchange[i] == 0)
            {
                o.xyoverchange[i] = 1;
               }
            //������
            if (o.overchange[i] == 0)
            {

                /*p.hitObj[0] = o.overchange[i];*/


            }
            else
            {

            }
        }

    }
}