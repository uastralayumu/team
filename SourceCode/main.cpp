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
    title t;
    using namespace input;
   

    while (GameLib::gameLoop())
    {
        // ���͏���
        input::update();
        switch (state)
        {
        case 0:
            game_init();
            t.init();
            state++;
            break;
           
        
        case 1:
        
            if (TRG(0) & PAD_START)
            {
                state++;
            }
                
            break;
        
        case 2:
            // ���݂̃V�[�����X�V�E�`��
            game_update(&state);
            break;
        case 3:
            //�X�R�A�V�[�����X�V�E�`��


            if (TRG(0) & PAD_START)
            {
                state = 0;
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
