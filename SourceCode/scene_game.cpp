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
//------< 定数 >----------------------------------------------------------------

//------< 変数 >----------------------------------------------------------------
int game_state = 0;    // 状態
int game_timer = 0;    // タイマー
int time_limit = 0;    //制限時間
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
        //////// パラメータの設定 ////////
        GameLib::setBlendMode(Blender::BS_ALPHA);
        game_state++;
    case 2:
        e.update();
        e.render();
        if (TRG(0) & PAD_START)
        {
            game_state++;
            p.init();
            o.init();
        }
        break;
    case 3:
        //////// 通常時 ////////
        s.render();
        p.update();
        o.update(time_limit);
        p.render();
        h.Update();
        o.render();
        time_limit = game_timer / 60;
        //制限時間
        if (time_limit >= 60)
        {
            p.render_delete();
            *state = 3;
            game_state = 0;
            GameLib::clear(0, 0, 0);
        }
       
        break;
       
    }
    if (game_state > 2)
    {
        game_timer++;
    }
    
    
   
}

//--------------------------------------
//  終了処理
//--------------------------------------
void game_deinit()
{
  
}
