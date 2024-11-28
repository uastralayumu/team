//******************************************************************************
//
//
//      main
//
//
//******************************************************************************

//------< �C���N���[�h >---------------------------------------------------------
#include "all.h"
#include "title.h"
#include "result.h"
#include "audio.h"
//------< namespace >-----------------------------------------------------------
using namespace GameLib;

//------< �ϐ� >----------------------------------------------------------------

//------------------------------------------------------------------------------
//  WinMain�i�G���g���|�C���g�j
//------------------------------------------------------------------------------
int APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, int)// �g�p���Ȃ��ϐ��͋L�q���Ȃ�
{
    // �Q�[�����C�u�����̏����ݒ�
    GameLib::init(L"�Q�[���v���O���~���O�T", SCREEN_W, SCREEN_H, FULLSCREEN);
    int state = 0;
    int timer;
    title t;
    result r;
    using namespace input;
    GameLib::setBlendMode(Blender::BS_ALPHA);

    while (GameLib::gameLoop())
    {
        // ���͏���
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
            // ���݂̃V�[�����X�V�E�`��
            game_update(&state);
            break;
        case 3:
            //�X�R�A�V�[�����X�V�E�`��
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
        // �f�o�b�O�������`��
        debug::display(1.0f, 1.0f, 1.0f, 1, 1);

        //debug::setString("GP1_01 SAMPLE");

        // �o�b�N�o�b�t�@�̓��e��\��
        GameLib::present(1, 0);
    }

    // �Q�[���V�[���̏I��
    game_deinit();

    // �Q�[�����C�u�����̏I������
    GameLib::uninit();
}
