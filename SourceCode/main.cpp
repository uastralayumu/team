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
#include "result.h"
#include "audio.h"
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
    int timer;
    title t;
    result r;
    using namespace input;
    GameLib::setBlendMode(Blender::BS_ALPHA);

    while (GameLib::gameLoop())
    {
        // 入力処理
        input::update();
        switch (state)
        {
        case 0:
            game_init();
            t.init();
            r.init();
            audio_init();
            music::play(4);
            timer = 0;
            state++;
            break;
           
        
        case 1:
            t.render();
            if (TRG(0) & PAD_START)
            {
                music::play(2);
                music::stop(4);
                music::play(5);
                t.render_delete();
                state++;
            }
            break;
        case 2:
            // 現在のシーンを更新・描画
            game_update(&state);
            break;
        case 3:
            //スコアシーンを更新・描画
            music::stop(5);
            r.render();
            timer++;
            if (timer > 61)
            {
                GameLib::text_out(5, "ENTER START", 1280, 1000, 2, 2, 0, 0, 0, 1, TEXT_ALIGN::UPPER_RIGHT);
                if (TRG(0) & PAD_START)
                {
                    music::play(3);
                    state = 0;

                }
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
