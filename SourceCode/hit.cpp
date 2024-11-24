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
    // 当たり判定
    //-------------------------------------------
    //障害物(上段)
    for (int i = 0; i < 9; i++)
    {
        primitive::circle(
            p.playerpositionx + 10, p.playerpositiony,             //位置
            32,                     //半径
            1, 1,                   //スケール
            ToRadian(0),            //角度
            1.0F, 0.0F, 0.0F, 0.2F); //色
        primitive::circle(
            o.overpositionx[i] + 64, o.overpositiony[i] + 64,             //位置
            32,                     //半径

            1, 1,                   //スケール
            ToRadian(0),            //角度
            0.0F, 0.0F, 1.0F, 0.5F); //色
        if (hitCheck(p.playerpositionx + 10, p.playerpositiony, 32, o.overpositionx[i] + 64,  o.overpositiony[i] + 64, 32)) {
            
            if (o.xyoverchange[i] == 0)
            {
                o.xyoverchange[i] = 1;
               }
            //当たり
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