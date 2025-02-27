#include "all.h"

extern OBJ2D player;
extern OBJ2D enemy[ENEMY_MAX];

//--------------------------------------
//  円と円のあたり判定
//--------------------------------------
bool hitCheckCircle(VECTOR2 pos1, float r1, VECTOR2 pos2, float r2)
{
    float dx = pos2.x - pos1.x;
    float dy = pos2.y - pos1.y;
    float r  = r1 + r2;

    if (dx * dx + dy * dy <= r * r)
        return true;

    return false;
}

//--------------------------------------
//  OBJ2D同士のあたり判定
//--------------------------------------
bool hitCheck(OBJ2D* obj1, OBJ2D* obj2)
{
    return hitCheckCircle(
        obj1->pos + obj1->offset, obj1->radius,
        obj2->pos + obj2->offset, obj2->radius
    );
}

//--------------------------------------
//  あたり判定
//--------------------------------------
void judge()
{
    // プレイヤーvs敵のあたり判定
    for (int i = 0; i < ENEMY_MAX; ++i)
    {
#if 7
//******************************************************************************
// TODO:07 moveAlgがNULLならそのOBJ2Dは存在していない
//------------------------------------------------------------------------------
/*
課題）
    設問05番と同じです。
*/
//******************************************************************************
#endif
        //TODO_07
        if (enemy[i].moveAlg == -1)         continue;
        if (enemy[i].area != player.area)   continue;

        if (hitCheck(&player, &enemy[i]))
        {
            game_reset();
        }
    }
}