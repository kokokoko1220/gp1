//******************************************************************************
//
//
//      scene_game
//
//
//******************************************************************************

//----< インクルード >-----------------------------------------------------------
#include "all.h"

//------< 定数 >----------------------------------------------------------------


//------< 構造体 >---------------------------------------------------------------


//------< 変数 >----------------------------------------------------------------
int game_state;
int game_timer;

Sprite* sprBack;

extern int player_state;
extern int enemy_state;

//--------------------------------------
//  ゲームの初期設定
//--------------------------------------
void game_init()
{
    game_state      = 0;
    game_timer      = 0;
}

//--------------------------------------
//  ゲームの終了処理
//--------------------------------------
void game_deinit()
{
    // 敵の終了処理
    enemy_deinit();

    // プレイヤーの終了処理
    player_deinit();

    safe_delete(sprBack);
}

//--------------------------------------
//  ゲームの更新処理
//--------------------------------------
void game_update()
{
    switch (game_state)
    {
    case 0:
        //////// 初期設定 ////////

        sprBack = sprite_load(L"./Data/Images/gamehaikei.png");

        // プレイヤーの初期設定
        player_init();

        // 敵の初期設定
        enemy_init();

        game_state++;
        /*fallthrough*/

    case 1:
        //////// パラメータの設定 ////////

        GameLib::setBlendMode(Blender::BS_ALPHA);

        game_state++;
        /*fallthrough*/

    case 2:
        //////// 通常時 ////////

        debug::setString("");
        debug::setString("A D   : LEFT, RIGHT");
        debug::setString("SPACE : JUMP");
        debug::setString("");

        // タイトルに戻る
        if (TRG(0) & PAD_SELECT)
        {
            nextScene = SCENE_TITLE;
            break;
        }

        // プレイヤーの更新
        player_update();

        // 敵の更新
        enemy_update();

        // あたり判定を行う
        judge();

        break;
    }

    game_timer++;
}

//--------------------------------------
//  ゲームの描画処理
//--------------------------------------
void game_render()
{
    // 画面をクリア
    GameLib::clear(0.2f, 0.2f, 0.4f);
    GameLib::clear(1,1,1);

    // 背景を描画
    area_render();

    // 敵を描画
    enemy_render();

    // プレイヤーを描画
    player_render();
}

//--------------------------------------
//  ゲームのリスタート
//--------------------------------------
void game_reset()
{
    // ゲームをリセットする
    game_state      = 1;
    player_state    = 1;
    enemy_state     = 1;
}