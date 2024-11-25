#include"all.h"

#include"player.h"
#include"object.h"
#include"hit.h"
#include"result.h"
#include"mission.h"

extern player p;
extern object o;
result r;
extern mission m;

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
            p.playerpositionx + 26, p.playerpositiony + 10,             //位置
            8,                     //半径
            1, 1,                   //スケール
            ToRadian(0),            //角度
            1.0F, 0.0F, 0.0F, 0.2F); //色
        primitive::circle(
            o.overpositionx[i] + 64, o.overpositiony[i] + 64,             //位置
            32,                     //半径

            1, 1,                   //スケール
            ToRadian(0),            //角度
            0.0F, 0.0F, 1.0F, 0.5F); //色
        if (hitCheck(p.playerpositionx + 26, p.playerpositiony + 10, 32, o.overpositionx[i] + 64,  o.overpositiony[i] + 64, 32)) {
            
            if (o.xyoverchange[i] == 0)
            {
                o.xyoverchange[i] = 1;
                r.score += 20;
                r.judge++;
                same[0] = o.overchange[i];
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
        if (hitCheck(p.playerpositionx + 26, p.playerpositiony + 10, 32, o.centerpositionx[i] + 64, o.centerpositiony[i] + 64, 32)) {
            if (o.xycenterchange[i] == 0)
            {
                o.xycenterchange[i] = 1;
                r.score += 20;
                r.judge++;
                same[1] = o.centerchange[i];
            }
            
        }
       
    }
    for (int i = 0; i < 13; i++)
    {
        if (hitCheck(p.playerpositionx + 26, p.playerpositiony + 10, 32, o.underpositionx[i] + 64, o.underpositiony[i] + 64, 32)) {
            if (o.xyunderchange[i] == 0)
            {
                o.xyunderchange[i] = 1;
                r.score += 20;
                r.judge++;
                same[2] = o.underchange[i];
            }
        }
    }
    if (r.judge == 3)
    {
        r.score += 40;
        if (m.obj1 == same[0] && m.obj2 == same[1] && m.obj3 == same[2])
        {
            r.score += 100;
        }
    }
}