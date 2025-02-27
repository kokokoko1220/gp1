#include "all.h"

//--------------------------------------
//  OBJ2Dの空きを見つけて生成させる関数（仮）
//--------------------------------------
#if 9
//******************************************************************************
// TODO:09 searchSet0関数の第3引数を関数ポインタに替える
//------------------------------------------------------------------------------
/*
課題）
    下記searchSet0関数の第3引数を、戻り値void型で引数がOBJ2D*である関数のポインタ
    に書き換えましょう。

解説）
    プリントで習った方法で関数ポインタを、関数の引数としても宣言する事ができます。
*/
//******************************************************************************
#endif
//TODO_09
OBJ2D* searchSet0(OBJ2D arr[], int dataNum, int moveAlg, VECTOR2 pos)
{
    for (int i = 0; i < dataNum; ++i)
    {
#if 10
//******************************************************************************
// TODO:10 moveAlgがNULLでなければ、既に存在しているのでcontinue
//------------------------------------------------------------------------------
/*
課題）
    ここはOBJ2Dの空きを見つけて生成するための関数searchSet0関数の中身です。
    生成する場合は更新や描画と違って、既に存在していればcontinueするのでしたね。

手順）
    もしarr[i].moveAlgがNULLでなければcontinueと書き換えましょう。
*/
//******************************************************************************
#endif
        //TODO_10 
        if (arr[i].moveAlg != -1)  continue;

        arr[i]          = {};
        arr[i].moveAlg  = moveAlg;
        arr[i].pos      = pos;
        return &arr[i];
    }

    return NULL;                        // 生成できなかった
}
