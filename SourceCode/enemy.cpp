#include "all.h"
#include <time.h>
#include<stdlib.h>

int enemy_state;
    int rnd;

OBJ2D enemy[ENEMY_MAX];

// 敵データ
struct ENEMY_DATA
{
    Sprite*         spr;
    const wchar_t*  filePath;
    VECTOR2         texPos;
    VECTOR2         texSize;
    VECTOR2         pivot;
    float           radius;
    VECTOR2         offset;
#if 15
//******************************************************************************
// TODO:15 FUNC_PTR型に変更しておく
//------------------------------------------------------------------------------
/*
課題）
    ENEMY_DATAのメンバ変数moveAlgを、OBJ2D::FUNC_PTR型型のmoveAlgに変更しておき
    ましょう。
*/
//******************************************************************************
#endif
#if 3
//******************************************************************************
// TODO:03 敵データ構造体に関数ポインタを追加する
//------------------------------------------------------------------------------
/*
課題）
    敵データの構造体に関数ポインタを追加し、どの敵がどの関数で動くかを指定する
    ようにしましょう。

手順）
    下記で戻り値void型で引数がOBJ2D*である関数のポインタmoveAlgを宣言する。
*/
//******************************************************************************
#endif
    //TODO_03

} enemyData[] = {
#if 4
//******************************************************************************
// TODO:04 敵データに関数ポインタを追加する
//------------------------------------------------------------------------------
/*
課題）
    敵データ構造体に関数ポインタが追加されたので、敵データの初期化時に関数の
    アドレスを設定しておきましょう。

手順）
    敵0のmoveAlgにmoveEnemy0、敵1のmoveAlgにmoveEnemy1、敵2のmoveAlgにmoveEnemy2
    をそれぞれ追加します。
*/
//******************************************************************************
#endif
    //TODO_04
    { NULL, L"./Data/Images/gole.png", { 0, 0 }, { 256, 800 }, { 128, 400 }, 20,{70,-110} },
    /*{ NULL, L"./Data/Images/kuma.png",   { 0, 0 }, { 256, 256 }, { 128, 128 }, 50 },
    { NULL, L"./Data/Images/neko.png",   { 0, 0 }, { 256, 256 }, { 128, 128 }, 60 },*/
};

// 敵配置用データ
struct ENEMY_SET
{
    int         area;
    int         enemyType;
    VECTOR2     pos;
} enemySet[] = {
    {  0,  0, {  50, 600 } }, 
   /* {  0,  0, {  800, 500 } },
    {  1,  0, {  200, 400 } },
    {  1,  1, {  600, 600 } },
    {  1,  1, {  900, 500 } },
    {  2,  1, {  200, 400 } },
    {  2,  1, {  500, 500 } },
    {  2,  2, { 1200, 200 } },*/
    { -1, -1, {   -1,  -1 } },
};

//--------------------------------------
//  敵の初期設定
//--------------------------------------
void enemy_init()
{
    enemy_state = 0;

    srand((unsigned)time(NULL));
    for(int i = 0; enemySet[i].enemyType >= 0; i++){
        rnd = 300 + rand() % 201;
        enemySet[i].pos.y = rnd;
    }
}

//--------------------------------------
//  敵の終了処理
//--------------------------------------
void enemy_deinit()
{
    int dataNum = ARRAYSIZE(enemyData);
    for (int i = 0; i < dataNum; ++i)
    {
        safe_delete(enemyData[i].spr);
    }
}

//--------------------------------------
//  敵の更新処理
//--------------------------------------
void enemy_update()
{
    switch (enemy_state)
    {
    case 0:
    {
        //////// 初期設定 ////////

        // 敵データ数の計算
        int dataNum = sizeof(enemyData) / sizeof(ENEMY_DATA);

        // スプライト読み込み
        for (int i = 0; i < dataNum; ++i)
        {
            enemyData[i].spr = sprite_load(enemyData[i].filePath);
        }

        ++enemy_state;
        /*fallthrough*/
    }

    case 1:
        //////// パラメータの設定 ////////

        // 敵データのクリア
        for (int i = 0; i < ENEMY_MAX; ++i)
        {
            enemy[i]            = {};
#if 8
//******************************************************************************
// TODO:08 moveAlgは既にNULL（存在しない）になっている
//------------------------------------------------------------------------------
/*
課題）
    この上の行でenemy[i] = {};を行っているので、enemy[i]のメンバ変数は全てゼロで
    クリアされている。moveAlgがNULLという事になるので、既に存在を消せている。
    そのため、下記の行をコメントアウトしましょう。（もう削除してもよい）
*/
//******************************************************************************
#endif
            //TODO_08
            enemy[i].moveAlg    = -1;
        }

        // 敵の出現
        for (int i = 0; enemySet[i].enemyType >= 0; ++i)
        {
#if 12
//******************************************************************************
// TODO:12 searchSet0関数を呼び出す際の引数を変更する
//------------------------------------------------------------------------------
/*
課題）
    searchSet0関数の第3引数が関数ポインタに変わったので、引数を変更しましょう。
    設問の03番や04番で行った事をよく考えてみましょう。
*/
//******************************************************************************
#endif
            //TODO_12
            OBJ2D* p = searchSet0(enemy, ENEMY_MAX, enemySet[i].enemyType, enemySet[i].pos);

            if (!p) break;

            p->area = enemySet[i].area;
        }

        ++enemy_state;
        /*fallthrough*/

    case 2:
        //////// 通常時 ////////

        // 敵の行動
        for (int i = 0; i < ENEMY_MAX; ++i)
        {
#if 5
//******************************************************************************
// TODO:05 moveAlgがNULLならそのOBJ2Dは存在していない
//------------------------------------------------------------------------------
/*
課題）
    前回はmoveAlgが-1の場合に存在していないという意味にしていた。
    関数ポインタを導入したので、moveAlgがNULLの場合に存在していないという意味に
    変える必要がある。

手順）
    下記のif文の条件を書き換えましょう。
*/
//******************************************************************************
#endif
            //TODO_05
            if (enemy[i].moveAlg == -1)         continue;

            if (enemy[i].area != player.area)   continue;

#if 2
//******************************************************************************
// TODO:02 関数ポインタを使って関数を呼ぶ
//------------------------------------------------------------------------------
/*
課題）
    関数ポインタmoveAlgを使って関数を呼ぶように変更しましょう。

手順）
    1.  下記のswitch文をコメントアウトする（あとで削除してもよい）

    2.  enemy[i].moveAlgが、その敵を行動させる関数の関数ポインタなので、それを
        使って関数を呼び出すようにする。
*/
//******************************************************************************
#endif
            //TODO_02
            switch (enemy[i].moveAlg)
            {
            case 0: moveEnemy0(&enemy[i]); break;
            case 1: moveEnemy1(&enemy[i]); break;
            case 2: moveEnemy2(&enemy[i]); break;
            }

            ++enemy[i].timer;
        }

        break;
    }
}

//--------------------------------------
//  敵の描画処理
//--------------------------------------
void enemy_render()
{
    for (int i = 0; i < ENEMY_MAX; ++i)
    {
#if 6
//******************************************************************************
// TODO:06 moveAlgがNULLならそのOBJ2Dは存在していない
//------------------------------------------------------------------------------
/*
課題）
    設問05番と同じです。
*/
//******************************************************************************
#endif
        //TODO_06
        if (enemy[i].moveAlg == -1)         continue;
        if (enemy[i].area != player.area)   continue;

        sprite_render(
            enemy[i].spr, 
            enemy[i].pos.x,     enemy[i].pos.y, 
            enemy[i].scale.x,   enemy[i].scale.y, 
            enemy[i].texPos.x,  enemy[i].texPos.y, 
            enemy[i].texSize.x, enemy[i].texSize.y, 
            enemy[i].pivot.x,   enemy[i].pivot.y, 
            ToRadian(0), 
            enemy[i].color.x,   enemy[i].color.y, 
            enemy[i].color.z,   enemy[i].color.w
        );

        // 敵のあたり領域の描画
        primitive::circle(
            enemy[i].pos, enemy[i].radius,
            { 1, 1 }, ToRadian(0), 
            { 1, 0, 0, 0.2f }
        );
    }
}

//--------------------------------------
//  敵0の動作
//--------------------------------------
void moveEnemy0(OBJ2D* obj)
{
    switch (obj->state)
    {
    case 0:
        //////// 初期設定 ////////

        obj->scale      = { 0.5f, 0.5f };
        obj->color      = { 1, 1, 1, 1 };
        obj->spr        = enemyData[0].spr;
        obj->texPos     = enemyData[0].texPos;
        obj->texSize    = enemyData[0].texSize;
        obj->pivot      = enemyData[0].pivot;
        obj->radius     = enemyData[0].radius;
        obj->offset = enemyData[0].offset;

#if 17
//******************************************************************************
// TODO:17 初期位置を保持
//------------------------------------------------------------------------------
/*
課題）
    敵0の初期設定のところで、初期位置を保存しておきましょう。

手順）
    ここでobj->originにobj->posを代入しておく。
*/
//******************************************************************************
#endif
        //TODO_17
        

        ++obj->state;
        /*fallthrough*/

    case 1:
        //////// 通常時 ////////

#if 18
//******************************************************************************
// TODO:18 敵0の行動
//------------------------------------------------------------------------------
/*
課題）
    敵0の行動を実装しましょう。[プリント参照]

手順）
    右→下→左→上→右のように、四角形を描くように動かしていきます。[完成サンプル参照]

    obj->actで分岐させます。
    0 右へ進む準備
    1 右へ進む
    2 下へ進む準備
    3 下へ進む
    4 左へ進む準備
    5 左へ進む
    6 上へ進む準備
    7 上へ進む

    ・準備のところは全てbreakなし、進むところはbreak有りです。

    ・準備のところでは、速度を設定します。
    　例）case 0:
            obj->speed = { 2, 0 };

    ・進むところでは、次の準備へ遷移する条件を記述します。
    　例）case 1:
            if (obj->pos.x > obj->origin.x + 50)
                ++obj->act;

    ・上へ進んだ後は、0に遷移します。

ヒント）
    先に設問19番をやっておくと、動作をひとつひとつ確認しながら組めます。
*/
//******************************************************************************
#endif
        //TODO_18


#if 19
//******************************************************************************
// TODO:19 位置に速度を足す
//------------------------------------------------------------------------------
/*
課題）
    位置に速度を足します。

解説）
    全ての敵が、位置に速度を足す方法で動くとは限らないので、各敵固有の動作の関数
    の内で足しておきます。（共通にしない）
*/
//******************************************************************************
#endif
        //TODO_19
        

        break;
    }
}

//--------------------------------------
//  敵1の動作
//--------------------------------------
void moveEnemy1(OBJ2D* obj)
{
    switch (obj->state)
    {
    case 0:
        //////// 初期設定 ////////

        obj->scale      = { 1.0f, 1.0f };
        obj->color      = { 1, 1, 1, 1 };
        obj->spr        = enemyData[1].spr;
        obj->texPos     = enemyData[1].texPos;
        obj->texSize    = enemyData[1].texSize;
        obj->pivot      = enemyData[1].pivot;
        obj->radius     = enemyData[1].radius;

#if 21
//******************************************************************************
// TODO:21 初期位置を保持
//------------------------------------------------------------------------------
/*
課題）
    敵1の初期設定のところで、初期位置を保存しておきましょう。
    設問17番と同じです。
*/
//******************************************************************************
#endif
        //TODO_21


        ++obj->state;
        /*fallthrough*/

    case 1:
        //////// 通常時 ////////

#if 22
//******************************************************************************
// TODO:22 敵1の行動（円運動）
//------------------------------------------------------------------------------
/*
課題）
    敵1の行動を実装します。敵1はoriginを中心として、半径200の位置で時計回りに
    回転する円運動をさせていきます。

手順）
    1.  obj->actで分岐させる（switch文）
        case 0:は初期設定（break無し）
        case 1:は通常時（break有り）

    2.  【初期設定】
        obj->angleに-90度を設定する。

    3.  【通常時】
        位置にobj->originからobj->angleの方向に距離200進んだ地点を設定する。
        角度に1度を足す。
        角度が-PIからPIまでに収まるようにする。
*/
//******************************************************************************
#endif
        //TODO_22


        break;
    }
}

//--------------------------------------
//  敵2の動作
//--------------------------------------
void moveEnemy2(OBJ2D* obj)
{
    switch (obj->state)
    {
    case 0:
        //////// 初期設定 ////////

        obj->scale      = { 0.5f, 0.5f };
        obj->color      = { 1, 1, 1, 1 };
        obj->spr        = enemyData[2].spr;
        obj->texPos     = enemyData[2].texPos;
        obj->texSize    = enemyData[2].texSize;
        obj->pivot      = enemyData[2].pivot;
        obj->radius     = enemyData[2].radius;

        ++obj->state;
        /*fallthrough*/

    case 1:
        //////// 通常時 ////////

#if 23
//******************************************************************************
// TODO:23 敵2の行動
//------------------------------------------------------------------------------
/*
課題）
    敵2の行動を実装します。敵2は横方向には等速直線運動、縦方向には等加速度直線運動
    を行う事になります。

手順）
    1.  obj->actで分岐させる（switch文）
        case 0:は初期設定（break無し）
        case 1:は通常時（break有り）

    2.  【初期設定】
        速度に{ -5, 0 }を設定する。

    3.  【通常時】
        速度yにGRAVITYを足す。
        もし位置.yがGROUND_Yを超えたら
            位置.yにGROUND_Yを設定
            速度.yに-30.0fを設定

    4.  【3の続き】
        もし位置xがプレイヤーの位置x-240より小さければ
            速度xに5を代入する
            スケールxに-0.5fを代入する
        もし位置xがプレイヤーの位置x+240より大きければ
            速度xに-5を代入する
            スケールxに0.5fを代入する

    5.  【switch文の後】
        位置に速度を加える
*/
//******************************************************************************
#endif
        //TODO_23


        break;
    }
}
