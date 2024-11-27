#include"all.h"

#include"player.h"
#include"object.h"
#include"hit.h"
#include"result.h"
#include"mission.h"
#include "audio.h"

extern player p;
extern object o;
extern result r;
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
    // “–‚½‚è”»’è
    //-------------------------------------------
    //áŠQ•¨(ã’i)
    for (int i = 0; i < 9; i++)
    {
        if (hitCheck(p.playerpositionx + 26, p.playerpositiony + 10, 32, o.overpositionx[i] + 64,  o.overpositiony[i] + 64, 32)) {
            
            if (o.xyoverchange[i] == 0)
            {
                music::play(1);
                o.xyoverchange[i] = 1;
                r.score += 20;
                r.judge++;
                same[0] = o.overchange[i];
               }
           
        }
        if (hitCheck(p.playerpositionx + 26, p.playerpositiony + 10, 32, o.centerpositionx[i] + 64, o.centerpositiony[i] + 64, 32)) {
            if (o.xycenterchange[i] == 0)
            {
                music::play(1);
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
                music::play(1);
                o.xyunderchange[i] = 1;
                r.score += 20;
                r.judge++;
                same[2] = o.underchange[i];
            }
        }
    }
    if (r.judge == 3)
    {
        r.threeoden++;
        r.score += 40;
        if (m.obj1 == same[0] && m.obj2 == same[1] && m.obj3 == same[2])
        {
            r.osinagaki++;
            r.score += 100;
        }
        r.judge = 0;
    }
}