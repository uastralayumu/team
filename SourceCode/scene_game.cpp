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
        //////// �p�����[�^�̐ݒ� ////////
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
        //////// �ʏ펞 ////////
        s.render();
        p.update();
        o.update(time_limit);
        p.render();
        h.Update();
        o.render();
        time_limit = game_timer / 60;
        //��������
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
//  �I������
//--------------------------------------
void game_deinit()
{
  
}
