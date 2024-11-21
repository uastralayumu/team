//******************************************************************************
//
//
//      main
//
//
//******************************************************************************

//------< インクルード >---------------------------------------------------------
#include "all.h"
#include "title.h"
#include "explanation.h"

//------< namespace >-----------------------------------------------------------
using namespace GameLib;

//------< 変数 >----------------------------------------------------------------

//------------------------------------------------------------------------------
//  WinMain（エントリポイント）
//------------------------------------------------------------------------------
int APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, int)// 使用しない変数は記述しない
{
    // ゲームライブラリの初期設定
    GameLib::init(L"ゲームプログラミングⅠ", SCREEN_W, SCREEN_H, FULLSCREEN);
    int state = 0;
    title t;
    explanation e;
    using namespace input;
   

    while (GameLib::gameLoop())
    {
        // 入力処理
        input::update();
        switch (state)
        {
        case 0:
            game_init();
            t.init();
            state++;
            break;
           
        
        case 1:
        
            t.render();
            if (TRG(0) & PAD_START)
            {
                state++;
                e.init();
            }
                
            break;
        
        case 2:
            e.update();
            e.render();
            if (TRG(0) & PAD_START)
            {
                state++;
            }

            break;
        case 3:
            // 現在のシーンを更新・描画
            game_update(&state);
            break;
        case 4:
            //スコアシーンを更新・描画


            if (TRG(0) & PAD_START)
            {
                state = 0;
            }
            break;
        }
        // デバッグ文字列を描画
        debug::display(1.0f, 1.0f, 1.0f, 1, 1);

        //debug::setString("GP1_01 SAMPLE");

        // バックバッファの内容を表示
        GameLib::present(1, 0);
    }

    // ゲームシーンの終了
    game_deinit();

    // ゲームライブラリの終了処理
    GameLib::uninit();
}
