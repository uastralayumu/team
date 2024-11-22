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
    ////デバック用 串の先端に円をつける
    //primitive::circle(
    //    px, py,             //位置
    //    32,                     //半径
    //    1, 1,                   //スケール
    //    ToRadian(0),            //角度
    //    0.0F, 1.0F, 0.0F, 0.5F   //色
    //);

    //maemaemae
    //-------------------------------------------
    // 当たり判定
    //-------------------------------------------
    //障害物(上段)
    for (int i = 0; i < 9; i++)
    {


        primitive::circle(
            px + 10, py,             //位置
            32,                     //半径
            1, 1,                   //スケール
            ToRadian(0),            //角度
            1.0F, 0.0F, 0.0F, 0.2F); //色
        primitive::circle(
            ox[i] + 64, oy[i] + 64,             //位置
            32,                     //半径

            1, 1,                   //スケール
            ToRadian(0),            //角度
            0.0F, 0.0F, 1.0F, 0.5F); //色
        if (hitCheck(px + 10, py, 32, ox[i] + 64, oy[i] + 64, 32)) {
            //当たり

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