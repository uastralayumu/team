//******************************************************************************
//
//
//      scene_game
//
//
//******************************************************************************

//----< �C���N���[�h >-----------------------------------------------------------
#include "all.h"
#include <sstream>
#include"player.h"
#include"object.h"
#include "stage.h"
#include "explanation.h"
#include"hit.h"
//------< �萔 >----------------------------------------------------------------

//------< �ϐ� >----------------------------------------------------------------
int game_state = 0;    // ���
int game_timer = 0;    // �^�C�}�[
int time_limit = 0;    //��������
int explanation_timer = 0;
hit h;
player p;
object o;
stage s;
explanation e;
//--------------------------------------
//  �����ݒ�
//--------------------------------------
void game_init()
{
    game_state = 0;
    game_timer = 0;
    time_limit = 0;
    explanation_timer = 0;
}

//--------------------------------------
//  �X�V����
//--------------------------------------
void game_update(int *state)
{
    using namespace input;
 
    switch (game_state)
    {
    case 0:
        //////// �����ݒ� ////////
        e.init();
        game_state++;
    case 1:
        e.update();
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
            }
        }
        break;
    case 2:
        //////// �ʏ펞 ////////
        s.render();
        p.update();
        o.update(time_limit);
        p.render();
        o.render();
        h.Update();
        time_limit = game_timer / 60;
        game_timer++;
        //��������
        if (time_limit >= 60)
        {
            *state = 3;
            game_state = 0;
            s.render_delete();
        }
        break;
    }
}

