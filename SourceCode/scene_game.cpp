//******************************************************************************
//
//
//      scene_game
//
//
//******************************************************************************

//----< インクルード >-----------------------------------------------------------
#include "all.h"
#include <sstream>
#include"player.h"
#include"object.h"
#include "stage.h"
#include "explanation.h"
#include"hit.h"
#include "audio.h"
//------< 定数 >----------------------------------------------------------------

//------< 変数 >----------------------------------------------------------------
int game_state = 0;    // 状態
int game_timer = 0;    // タイマー
int time_limit = 0;    //制限時間
int explanation_timer = 0;
hit h;
player p;
object o;
stage s;
explanation e;
//--------------------------------------
//  初期設定
//--------------------------------------
void game_init()
{
    game_state = 0;
    game_timer = 0;
    time_limit = 0;
    explanation_timer = 0;
}

//--------------------------------------
//  更新処理
//--------------------------------------
void game_update(int *state)
{
    using namespace input;
 
    switch (game_state)
    {
    case 0:
        //////// 初期設定 ////////
        e.init();
        game_state++;
    case 1:
        e.render();
        explanation_timer++;
        if (explanation_timer > 60)
        {
            GameLib::text_out(5, "ENTER START", 1280, 1000, 2, 2, 0, 0, 0, 1, TEXT_ALIGN::UPPER_RIGHT);
            if (TRG(0) & PAD_START)
            {
                game_state++;
                p.init();
                o.init();
                e.render_delete();
            }
        }
        break;
    case 2:
        //////// 通常時 ////////
        s.render();
        p.update();
        o.update(time_limit);
        p.render();
        o.render();
        h.Update();
        time_limit = game_timer / 60;
        game_timer++;
        //制限時間
        if (time_limit >= 60)
        {
            music::play(6);
            *state = 3;
            game_state = 0;
            s.render_delete();
        }
        break;
    }
}

