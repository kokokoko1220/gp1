#include "all.h"

int title_state;
int title_timer;

Sprite* sprCar;

//--------------------------------------
//  初期設定
//--------------------------------------
void title_init()
{
    title_state = 0;
    title_timer = 0;
}

//--------------------------------------
//  終了処理
//--------------------------------------
void title_deinit()
{
    music::stop(0);

    safe_delete(sprCar);
}

//--------------------------------------
//  タイトルの更新処理
//--------------------------------------
void title_update()
{
    switch (title_state)
    {
    case 0:
        //////// 初期設定 ////////

        sprCar = sprite_load(L"./Data/Images/sukoaend.png");

        title_state++;
        /*fallthrough*/

    case 1:
        //////// パラメータの設定 ////////

        GameLib::setBlendMode(Blender::BS_ALPHA);

        music::play(0);
        music::setVolume(0, 0.1f);

        title_state++;
        /*fallthrough*/

    case 2:
        //////// 通常時 ////////

        if (TRG(0) & PAD_START)
        {
            sound::play(XWB_SYSTEM, XWB_SYSTEM_START);

            nextScene = SCENE_GAME;
            break;
        }

        break;
    }

    debug::setString("");
    debug::setString("title_state:%d", title_state);
    debug::setString("title_timer:%d", title_timer);

    title_timer++;
}

//--------------------------------------
//  タイトルの描画処理
//--------------------------------------
void title_render()
{
    // 画面を青で塗りつぶす
    GameLib::clear(0.3f, 0.5f, 1.0f);
    sprite_render(sprCar, 0, 0);

    // タイトルの文字
    font::textOut(4, "space　jump & ", VECTOR2(100, 180), VECTOR2(1.8f, 1.8f), VECTOR4(0, 0.0f, 0, 1));
    font::textOut(4, " chage highjump ", VECTOR2(80, 240), VECTOR2(1.8f, 1.8f), VECTOR4(0, 0, 0.0f, 1));

    // "Push Enter Key" 点滅
    if (title_timer >> 5 & 0x01)
    {
        font::textOut(4, "Push Enter Key", VECTOR2(120, 460), VECTOR2(3.0f, 3.0f));
    }

}
