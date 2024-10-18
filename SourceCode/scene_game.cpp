//******************************************************************************
//
//
//      scene_game
//
//
//******************************************************************************

//----< �C���N���[�h >-----------------------------------------------------------
#include "all.h"

//------< �萔 >----------------------------------------------------------------


//------< �\���� >---------------------------------------------------------------


//------< �ϐ� >----------------------------------------------------------------
int game_state;
int game_timer;

Sprite* sprBack;

extern int player_state;
extern int enemy_state;

//--------------------------------------
//  �Q�[���̏����ݒ�
//--------------------------------------
void game_init()
{
    game_state      = 0;
    game_timer      = 0;
}

//--------------------------------------
//  �Q�[���̏I������
//--------------------------------------
void game_deinit()
{
    // �G�̏I������
    enemy_deinit();

    // �v���C���[�̏I������
    player_deinit();

    safe_delete(sprBack);
}

//--------------------------------------
//  �Q�[���̍X�V����
//--------------------------------------
void game_update()
{
    switch (game_state)
    {
    case 0:
        //////// �����ݒ� ////////

        sprBack = sprite_load(L"./Data/Images/gamehaikei.png");

        // �v���C���[�̏����ݒ�
        player_init();

        // �G�̏����ݒ�
        enemy_init();

        game_state++;
        /*fallthrough*/

    case 1:
        //////// �p�����[�^�̐ݒ� ////////

        GameLib::setBlendMode(Blender::BS_ALPHA);

        game_state++;
        /*fallthrough*/

    case 2:
        //////// �ʏ펞 ////////

        debug::setString("");
        debug::setString("A D   : LEFT, RIGHT");
        debug::setString("SPACE : JUMP");
        debug::setString("");

        // �^�C�g���ɖ߂�
        if (TRG(0) & PAD_SELECT)
        {
            nextScene = SCENE_TITLE;
            break;
        }

        // �v���C���[�̍X�V
        player_update();

        // �G�̍X�V
        enemy_update();

        // �����蔻����s��
        judge();

        break;
    }

    game_timer++;
}

//--------------------------------------
//  �Q�[���̕`�揈��
//--------------------------------------
void game_render()
{
    // ��ʂ��N���A
    GameLib::clear(0.2f, 0.2f, 0.4f);
    GameLib::clear(1,1,1);

    // �w�i��`��
    area_render();

    // �G��`��
    enemy_render();

    // �v���C���[��`��
    player_render();
}

//--------------------------------------
//  �Q�[���̃��X�^�[�g
//--------------------------------------
void game_reset()
{
    // �Q�[�������Z�b�g����
    game_state      = 1;
    player_state    = 1;
    enemy_state     = 1;
}