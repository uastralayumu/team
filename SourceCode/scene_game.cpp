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

//------< 定数 >----------------------------------------------------------------

//------< 変数 >----------------------------------------------------------------
int game_state = 0;    // 状態
int game_timer = 0;    // タイマー
int time_limit = 0;    //制限時間
player p;
object o;

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
        p.init();
        o.init();
        game_state++;
        /*fallthrough*/
    case 1:
        //////// パラメータの設定 ////////
        GameLib::setBlendMode(Blender::BS_ALPHA);

        game_state++;
        /*fallthrough*/
    case 2:
        //////// 通常時 ////////
        game_render();
        p.update();
        o.update(time_limit);
        p.render();
        o.render();
        time_limit = game_timer / 60;
        debug::setString("time_limit:%d ", 60 - time_limit);
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
    game_timer++;
    
   
}

//--------------------------------------
//  描画処理
//--------------------------------------
void game_render()
{
    GameLib::clear(0, 0, 0);
    
    
    
}

//--------------------------------------
//  終了処理
//--------------------------------------
void game_deinit()
{
  
}
