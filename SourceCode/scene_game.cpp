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
//------< �萔 >----------------------------------------------------------------

//------< �ϐ� >----------------------------------------------------------------
int game_state = 0;    // ���
int game_timer = 0;    // �^�C�}�[
int time_limit = 0;    //��������
player p;
object o;

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
        p.init();
        o.init();
        game_state++;
        /*fallthrough*/
    case 1:
        //////// �p�����[�^�̐ݒ� ////////
        GameLib::setBlendMode(Blender::BS_ALPHA);

        game_state++;
        /*fallthrough*/
    case 2:
        //////// �ʏ펞 ////////
        game_render();
        p.update();
        o.update(time_limit);
        p.render();
        o.render();
        time_limit = game_timer / 60;
        debug::setString("time_limit:%d ", 60 - time_limit);
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
    game_timer++;
    
   
}

//--------------------------------------
//  �`�揈��
//--------------------------------------
void game_render()
{
    GameLib::clear(0, 0, 0);
    
    
    
}

//--------------------------------------
//  �I������
//--------------------------------------
void game_deinit()
{
  
}
