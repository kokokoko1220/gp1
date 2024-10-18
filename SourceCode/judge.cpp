#include "all.h"

extern OBJ2D player;
extern OBJ2D enemy[ENEMY_MAX];

//--------------------------------------
//  â~Ç∆â~ÇÃÇ†ÇΩÇËîªíË
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
//  OBJ2DìØémÇÃÇ†ÇΩÇËîªíË
//--------------------------------------
bool hitCheck(OBJ2D* obj1, OBJ2D* obj2)
{
    return hitCheckCircle(
        obj1->pos + obj1->offset, obj1->radius,
        obj2->pos + obj2->offset, obj2->radius
    );
}

//--------------------------------------
//  Ç†ÇΩÇËîªíË
//--------------------------------------
void judge()
{
    // ÉvÉåÉCÉÑÅ[vsìGÇÃÇ†ÇΩÇËîªíË
    for (int i = 0; i < ENEMY_MAX; ++i)
    {
#if 7
//******************************************************************************
// TODO:07 moveAlgÇ™NULLÇ»ÇÁÇªÇÃOBJ2DÇÕë∂ç›ÇµÇƒÇ¢Ç»Ç¢
//------------------------------------------------------------------------------
/*
â€ëËÅj
    ê›ñ‚05î‘Ç∆ìØÇ∂Ç≈Ç∑ÅB
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